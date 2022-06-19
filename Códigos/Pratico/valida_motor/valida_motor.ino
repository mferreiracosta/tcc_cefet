const int IN1 = 7;
const int IN2 = 8;
const int IN3 = 10;
const int IN4 = 11;
const int EN_MOTOR_A = 6;
const int EN_MOTOR_B = 9;

void setup() {
  pinMode(EN_MOTOR_A, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(EN_MOTOR_B, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

}

void loop() {
  analogWrite(EN_MOTOR_A, 120);
  digitalWrite(IN1, 1);     // Controlando o Motor da Direita para F.
  digitalWrite(IN2, 0);      // Controlando o Motor da Direita para T.
  analogWrite(EN_MOTOR_B, 120);  
  digitalWrite(IN3, 1);     // Controlando o Motor da Esquerda para F.
  digitalWrite(IN4, 0);      // Controlando o Motor da Esquerda para T.

}
