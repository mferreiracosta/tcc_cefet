
double K[] = {40.2535, 50.1798};
//K[] = {3.2535, 1.1798};
double voltage = 0;
double output = 0;

int OUTMAX = 200;
int OUTMIN = -200;

double Compute(double angle, double angleRate){

  angle = angle / RAD_TO_DEG;          // Transformando de graus para rad
  angleRate = angleRate / RAD_TO_DEG;  // Transformando de graus para rad/s

  voltage = (K[0] * angle) + (K[1] * angleRate);

  output = voltage * (255/7.4);
  
  if (output > OUTMAX){
    output = OUTMAX;
  } 
  else if (output < OUTMIN) {
    output = OUTMIN;
  }

  return output;
  
}
