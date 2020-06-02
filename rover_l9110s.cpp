#include <analogWrite.h>  // shim for analogWrite() on ESP32

/******************************************************/
/****************rover control ************************/
/******************************************************/
byte speed = 128;

int AIA_PIN = -1;
int AIB_PIN = -1;
int BIA_PIN = -1;
int BIB_PIN = -1;

//
// set the rover pins
//
void roverInit(int a1, int a2, int b1, int b2) {
  AIA_PIN = a1;
  AIB_PIN = a2;
  BIA_PIN = b1;
  BIB_PIN = b2;
}

void roverSetSpeed(byte inSpeed) {
  speed = inSpeed;
}
byte roverGetSpeed() {
  return speed;
}

void roverStop() {
  if (-1 == AIA_PIN) return;
  
  analogWrite(AIA_PIN, 0);
  analogWrite(AIB_PIN, 0);
  analogWrite(BIA_PIN, 0);
  analogWrite(BIB_PIN, 0);
}
void roverForward(){
  if (-1 == AIA_PIN) return;

  analogWrite(AIA_PIN, speed);
  analogWrite(AIB_PIN, 0);
  analogWrite(BIA_PIN, 0);
  analogWrite(BIB_PIN, speed);
}
void roverReverse(){
  if (-1 == AIA_PIN) return;

  analogWrite(AIA_PIN, 0);
  analogWrite(AIB_PIN, speed);
  analogWrite(BIA_PIN, speed);
  analogWrite(BIB_PIN, 0);
}
void roverTurnRight() {
  if (-1 == AIA_PIN) return;

  analogWrite(AIA_PIN, speed);
  analogWrite(AIB_PIN, 0);
  analogWrite(BIA_PIN, speed);
  analogWrite(BIB_PIN, 0);
}
void roverTurnLeft() {
  if (-1 == AIA_PIN) return;

  analogWrite(AIA_PIN, 0);
  analogWrite(AIB_PIN, speed);
  analogWrite(BIA_PIN, 0);
  analogWrite(BIB_PIN, speed);
}
