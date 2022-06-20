import processing.serial.*;
Serial mySerial;
PrintWriter output;

void setup() {
  String portName = "COM5";
  mySerial = new Serial(this, portName, 115200);
  output = createWriter("dadosControlador.txt");
}

void draw() {
  if (mySerial.available() > 0) {
     String value = mySerial.readStringUntil('\n');
     if (value != null) {
       output.println(value);
       output.flush();
     }
     delay(2);
  }
}

void keyPressed() {
  output.flush();
  output.close();
  exit();
}
