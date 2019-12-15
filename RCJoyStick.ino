#include <Joystick.h>

int AleronPin = 3;
int ElevatorPin = 4;
int ThrottlePin =5;
int RudderPin = 6;
int Aux1Pin = 7;
int Aux2Pin = 8;


Joystick_ Joystick;

void setup() 
{
  pinMode(AleronPin, INPUT);
  pinMode(ElevatorPin, INPUT);
  pinMode(ThrottlePin, INPUT);
  pinMode(RudderPin, INPUT);
  pinMode(Aux1Pin, INPUT);
  pinMode(Aux2Pin, INPUT);
  
  Joystick.begin();
  Serial.begin(9600);

}

void loop() 
{

  
  int AleronChannel = pulseIn(AleronPin, HIGH, 25000);
  int AXY = map(AleronChannel, 975, 1935, 0, 1000);
  delay(5);
  int ElevatorChannel = pulseIn(ElevatorPin, HIGH, 25000);
  int EXY = map(ElevatorChannel, 975, 1935, 0, 1000);
  delay(5);
  int ThrottleChannel = pulseIn(ThrottlePin, HIGH, 25000);
  int TXY = map(ThrottleChannel, 975, 1935, 0, 1000);
  delay(5);
  int RudderChannel = pulseIn(RudderPin, HIGH, 25000);
  int RXY = map(RudderChannel, 975, 1935, 0, 1000);
  delay(5);
  
  Joystick.setRxAxis(AXY);
  Serial.println(AXY);
  Joystick.setRyAxis(EXY);
  Serial.println(EXY);
  Joystick.setXAxis(TXY);
  Serial.println(TXY);
  Joystick.setYAxis(RXY);
  Serial.println(RXY);
  
  
}
