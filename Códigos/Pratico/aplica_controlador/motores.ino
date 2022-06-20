//OUT_MAX_A = 200
//OUT_MAX_B = 200
//OUT_MIN_A = 80
//OUT_MIN_B = 65

const int IN1 = 5;
const int IN2 = 6;
const int IN3 = 9;
const int IN4 = 11;

double pwm = 0;

void init_motores(){
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void PWMControleMotores(double comando){
  
  if (comando < 0){
    
    pwm = map(comando, 0, -200, -80, -200);
    Serial.print(pwm); Serial.print("\t");
    
    analogWrite(IN1, 0);     
    analogWrite(IN2, abs(pwm));     // Controlando o Motor A para F.
    analogWrite(IN3, 0);     
    analogWrite(IN4, abs(pwm));     // Controlando o Motor B para F.
  }
  else {
    
    pwm = map(comando, 0, 200, 80, 200);
    Serial.print(pwm); Serial.print("\t");
    
    analogWrite(IN1, abs(pwm));     // Controlando o Motor A para T.
    analogWrite(IN2, 0);     
    analogWrite(IN3, abs(pwm));     // Controlando o Motor B para T.
    analogWrite(IN4, 0);     
  }
}
