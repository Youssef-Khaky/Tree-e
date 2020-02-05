// connect motor controller pins to Arduino digital pins
// motor one
//POWER SUPPLY VOLTAGE: 11.8V
int enA = 10;
int in1 = 9;
int in2 = 8;

void setup()
{
  // set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  analogWrite(enA, 255);
  reset();
//  stopMotor();
}
void loop()
{
  demoOne();
  delay(100);
}
void extend()
{
  Serial.print("Extending");
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
}
void retract()
{
  Serial.print("Retracting");
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH); 
}
void reset(){
  Serial.print("Reset Initiated");
  retract();
  delay(21000);
  Serial.print("Reset Complete");
}
void stopMotor()
{
  Serial.print("Stopping Motor");
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
}
void demoOne()
{
  
  extend();
  delay(4800);
  retract();
  delay(5200);

 
  
}
//void demoTwo()
//{
//  // this function will run the motors across the range of possible speeds
//  // note that maximum speed is determined by the motor itself and the operating voltage
//  // the PWM values sent by analogWrite() are fractions of the maximum speed possible
//  // by your hardware
//  // turn on motors
//  digitalWrite(in1, LOW);
//  digitalWrite(in2, HIGH); 
//  
//  // accelerate from zero to maximum speed
// 
// for (int i = 0; i < 256; i++) {
//  analogWrite(enA, i);
//  delay(20);
//  }
//// decelerate from maximum speed to zero
//for (int i = 255; i > 0; --i)
//  {
//    analogWrite(enA, i);
//    delay(20);
//  }
// 
//  
//  // now turn off motors
//  digitalWrite(in1, LOW);
//  digitalWrite(in2, LOW);  
//}
