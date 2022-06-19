/*************************************************************************
 * TRABALHO DE TCC II - SELF BALACING ROBOT - VALIDANDO SINAL SENSOR
 * 
 * APRESENTAÇÃO DIA 02/07/2022
 * 
 *************************************************************************/

#include <Wire.h>
#include <Kalman.h>

Kalman KalmanX, KalmanY;

float accX, accY, accZ;
float gyroX, gyroY, gyroZ;

float KalAngleX, KalAngleY;
float KalAngleYrate, KalAngleYprev; // angulo anterior e velocidade angular
float gyroXrate, gyroYrate;

const float dT = 10e-3;

int acc_offset[]  = {-585, 2185, 1495};
int gyro_offset[] = {24, 44, 7};

uint8_t i2c_data[14];
uint32_t timer;

/*************************************************************************
 * Configurações iniciais do código
 **************************************************************************/
void setup() {

  /* Inicializando a Serial para exibir mensagens de debug */
  Serial.begin(115200);

  /* Inicializando o barramento i2C para comunicação com a MPU6050 */
  Wire.begin();

#if ARDUINO >= 157
  Wire.setClock(400000UL); // Freq = 400kHz
#else
  TWBR = ((F_CPU / 400000ul) - 16) / 2; // Freq = 400kHz
#endif

  i2c_data[0] = 7;      /* 0x19 - Amostragem: Taxa de Saída Giroscopio = 8kHz/(1 + SMPLRT_DIV) -- Taxa: 8kHz/(1 + 7) = 1kHz */
  i2c_data[1] = 0x00;   /* 0x1A - Desabilitar FSYNC, Configurar o Filtro de ACC 260Hz, Configurar Filtro de Gyro 256Hz, Amostragem de 8kHz */
  i2c_data[2] = 0x00;   /* 0x1B - Configurar o fundo de escala do Gyro +-250deg/s - Faixa */
  i2c_data[3] = 0x00;   /* 0x1C - Configurar o fundo de escala do Acelerômetro para +-2g - Faixa */

  /* Configurações do i2c */
  while (i2cWrite(0x19, i2c_data, 4, false));

  /* PLL tenha como referência o gyro do eixo X, Desabilitando Sleep Mode */
  while (i2cWrite(0x6B, 0x01, true));

  /* */
  while (i2cRead(0x75, i2c_data, 1));

  if (i2c_data[0] != 0x68) {
    Serial.print("Erro. Placa desconhecida.\n");
    while (1) {
      Serial.print("Erro. Conecte a MPU6050 no barramento i2c.\n");
    }
  }

  /* Tempo de estabilidade do Sensor MPU6050 */
  delay(100);

  /* Chamando a função de inicialização da MPU6050 e alguns cálculos iniciais */
  init_MPUSensor();

  timer = micros();

  //init_motores();

}

void loop() {

  while (i2cRead(0x3B, i2c_data, 14));

  accX = (int16_t)((i2c_data[0] << 8) | i2c_data[1]) ; // ([ MSB ] [ LSB ]) - o símbolo (<<) é para deslocar i2c_data[0] 8 posições e concatenar (|) com a posição i2c_data[1]
  accY = (int16_t)((i2c_data[2] << 8) | i2c_data[3]) ; // ([ MSB ] [ LSB ]) - uma única palavra de 16 bytes se forma
  accZ = (int16_t)((i2c_data[4] << 8) | i2c_data[5]) ; // ([ MSB ] [ LSB ])

  gyroX = (int16_t)((i2c_data[8]  << 8) | i2c_data[9])  ;  // ([ MSB ] [ LSB ])
  gyroY = (int16_t)((i2c_data[10] << 8) | i2c_data[11]) ; // ([ MSB ] [ LSB ])
  gyroZ = (int16_t)((i2c_data[12] << 8) | i2c_data[13]) ; // ([ MSB ] [ LSB ])

  /******************************** Filtro de Kalman ***********************************/

  /* Calculo do Delta Time */
  float dt = (float)(micros() - timer) / 1000000;
  timer = micros();

  float roll  = atan(accY/sqrt(accX * accX + accZ * accZ)) * RAD_TO_DEG;
  float pitch = atan(accX/sqrt(accY * accY + accZ * accZ)) * RAD_TO_DEG;

  /* Convertendo de Rad/segundo para Graus/segundo. Calculo da taxa angula baseado no Giroscópio */
  gyroXrate = gyroX / 131.0;
  gyroYrate = gyroY / 131.0;  

  /* Estimativa de ângulo nos Eixos X e Y usando o Filtro de Kalman */
  KalAngleX = KalmanX.getAngle(roll, gyroXrate, dt);
  KalAngleY = KalmanY.getAngle(pitch, gyroYrate, dt);

  /* Estimativa da velocidade angular no Eixo Y */
  KalAngleYrate = (KalAngleY - KalAngleYprev) / dT;   // velocidade angular em relação a Y
  KalAngleYprev = KalAngleY;

  if (isnan(KalAngleY) || isnan(pitch)) {    
    return;
  }

  String sinais = String(KalAngleY) + "|" + String(pitch);
  Serial.println(sinais);

  delay(2);
}

void init_MPUSensor(void){
  /* 1 - Leitura dos dados de Acc XYZ */
  while (i2cRead(0x3B, i2c_data, 14));

  /* 2 - Organizar os dados de Acc XYZ */
  accX = (int16_t)((i2c_data[0] << 8) | i2c_data[1]) ; // ([ MSB ] [ LSB ])
  accY = (int16_t)((i2c_data[2] << 8) | i2c_data[3]) ; // ([ MSB ] [ LSB ]) 
  accZ = (int16_t)((i2c_data[4] << 8) | i2c_data[5]) ; // ([ MSB ] [ LSB ]) 

  /* 3 - Calculo de Pitch e Roll */
  double pitch = atan(accX / sqrt(accY * accY + accZ * accZ)) * RAD_TO_DEG;
  double roll  = atan(accY / sqrt(accX * accX + accZ * accZ)) * RAD_TO_DEG;

  /* 4 - Inicialização do Filtro de Kalman XY */
  KalmanY.setAngle(pitch);
  KalmanX.setAngle(roll);

  /* 5 - Guardando o valor do ângulo anterior */
  KalAngleYprev = pitch;

  /* 6 - Inicializando os valores da taxa de gyro */
  gyroYrate = pitch;
  gyroXrate = roll;
}
