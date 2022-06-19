//OUT_MAX_A = 200
//OUT_MAX_B = 200
//OUT_MIN_A = 80
//OUT_MIN_B = 65

const int IN1 = 7;
const int IN2 = 8;
const int IN3 = 10;
const int IN4 = 11;
const int EN_MOTOR_A = 6;
const int EN_MOTOR_B = 9;

void init_motores(){
  pinMode(EN_MOTOR_A, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(EN_MOTOR_B, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void PWMControleMotores(double comando){

  if (comando < 0){
    analogWrite(EN_MOTOR_A, abs(comando));
    digitalWrite(IN1, 0);     
    digitalWrite(IN2, 1);     // Controlando o Motor A para F.
    analogWrite(EN_MOTOR_B, abs(comando));
    digitalWrite(IN3, 0);     
    digitalWrite(IN4, 1);     // Controlando o Motor B para F.
  }
  else {
    analogWrite(EN_MOTOR_A, abs(comando));
    digitalWrite(IN1, 1);     // Controlando o Motor A para T.
    digitalWrite(IN2, 0);     
    analogWrite(EN_MOTOR_B, abs(comando));
    digitalWrite(IN3, 1);     // Controlando o Motor B para T.
    digitalWrite(IN4, 0);     
  }
}
