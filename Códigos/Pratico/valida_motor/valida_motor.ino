const int IN1 = 5;    // Motor A
const int IN2 = 6;    // Motor A
const int IN3 = 9;    // Motor B
const int IN4 = 11;   // Motor B

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {
  analogWrite(IN1, 0);
  analogWrite(IN2, 120);    // Controlando o Motor A para F (Sentido positivo de accX do sensor e negtivo de KalAngleY)
  analogWrite(IN3, 0);
  analogWrite(IN4, 120);    // Controlando o Motor B para F
  delay(10000);

  analogWrite(IN1, 120);    // Controlando o Motor A para T (Sentido negativo de de accX do sensor e positivo de KalAngleY)
  analogWrite(IN2, 0);
  analogWrite(IN3, 120);    // Controlando o Motor B para T
  analogWrite(IN4, 0);
  delay(10000);
}
