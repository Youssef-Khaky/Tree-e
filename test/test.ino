//The sample code for driving one way motor encoder
//const byte encoder0pinA = 2;//A pin -> the interrupt pin 0
//const byte encoder0pinB = 4;//B pin -> the digital pin 4

//const byte encoder1pinA = 5;//A pin -> the interrupt pin 5
//const byte encoder1pinB = 6;//B pin -> the digital pin 6

//const byte rearLeftMotorPinA = 8;
//const byte rearLeftMotorPinB = 9;
//const byte rearRightMotorPinA = 10;
//const byte rearRightMotorPinB = 11;
const byte trigPin = 13;
const byte echoPin = 12;

long duration_sound;
double distance_sound;



byte encoder0PinALast;
byte encoder1PinALast;
int duration;//the number of the pulses
boolean Direction;//the rotation direction


void setup()  
{
  Serial.begin(57600);//Initialize the serial port
//  EncoderInit();//Initialize the module
//  pinMode(rearLeftMotorPinA,OUTPUT);
//  pinMode(rearLeftMotorPinB,OUTPUT);
//  pinMode(rearRightMotorPinA,OUTPUT);
//  pinMode(rearRightMotorPinA,OUTPUT);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
}

void loop()
{
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration_sound = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance_sound= duration_sound*0.00034/2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance_sound);
  Serial.print(" ");

//  digitalWrite(rearLeftMotorPinA, LOW);
//  digitalWrite(rearLeftMotorPinB, HIGH);
//  digitalWrite(rearRightMotorPinA, LOW);
//  digitalWrite(rearRightMotorPinB, HIGH);
//  delay(5000);
//  digitalWrite(rearLeftMotorPinA, HIGH);
//  digitalWrite(rearLeftMotorPinB, HIGH);
//  digitalWrite(rearRightMotorPinA, HIGH);
//  digitalWrite(rearRightMotorPinB, HIGH);
//  delay(5000);
//  digitalWrite(rearLeftMotorPinA, HIGH);
//  digitalWrite(rearLeftMotorPinB, LOW);
//  digitalWrite(rearRightMotorPinA, HIGH);
//  digitalWrite(rearRightMotorPinB, LOW);
//  delay(5000);

//  Serial.println("Pulse:");
//  Serial.println(duration);
//  duration = 0;
//  delay(100);
}

//void EncoderInit()
//{
//  Direction = true;//default -> Forward
//  pinMode(encoder0pinB,INPUT);
//  pinMode(encoder1pinB,INPUT);
//  attachInterrupt(0, wheelSpeed, CHANGE);
//}

//void wheelSpeed()
//{
//  int Lstate = digitalRead(encoder0pinA);
//  int L1state = digitalRead(encoder1pinA);
//  if((encoder0PinALast == LOW) && Lstate==HIGH)
//  {
//    int val = digitalRead(encoder0pinB);
//    if(val == LOW && Direction)
//   {
//      Direction = false; //Reverse
//    }
//    else if(val == HIGH && !Direction)
//    {
//      Direction = true;  //Forward
//    }
//  }
//  if((encoder1PinALast == LOW) && L1state==HIGH)
//  {
//    int val = digitalRead(encoder1pinB);
//    if(val == LOW && Direction)
//   {
//      Direction = false; //Reverse
//    }
//    else if(val == HIGH && !Direction)
//    {
//      Direction = true;  //Forward
//    }
//  }
//  encoder0PinALast = Lstate;
//  encoder1PinALast = L1state;
//
//  if(!Direction)  duration  ;
//  else  duration--;
//}
