
double K[] = {3.2023, 1.1508};
double voltage = 0;
double output = 0;

int OUTMAX = 200;
int OUTMIN = -200;

double Compute(double angle, double angleRate){

  voltage = (K[0] * angle) + (K[1] * angleRate);

  output = voltage * (255/7.4);
  
  if (output > OUTMAX){
    output = OUTMAX;
  } 
  else {
    output = OUTMIN;
  }

  return output;
  
}
