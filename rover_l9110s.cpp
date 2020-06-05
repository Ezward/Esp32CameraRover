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

  pinMode(AIA_PIN, OUTPUT);
  pinMode(AIB_PIN, OUTPUT);
  pinMode(BIA_PIN, OUTPUT);
  pinMode(BIB_PIN, OUTPUT);
  
}

void roverSetSpeed(byte inSpeed) {
  speed = inSpeed;
}
byte roverGetSpeed() {
  return speed;
}

void roverStop() {
  if (-1 == AIA_PIN) return;
  
  digitalWrite(AIA_PIN, LOW);
  digitalWrite(AIB_PIN, LOW);
  digitalWrite(BIA_PIN, LOW);
  digitalWrite(BIB_PIN, LOW);
}
void roverForward(){
  if (-1 == AIA_PIN) return;

  digitalWrite(AIA_PIN, HIGH);
  digitalWrite(AIB_PIN, LOW);
  digitalWrite(BIA_PIN, LOW);
  digitalWrite(BIB_PIN, HIGH);
}
void roverReverse(){
  if (-1 == AIA_PIN) return;

  digitalWrite(AIA_PIN, LOW);
  digitalWrite(AIB_PIN, HIGH);
  digitalWrite(BIA_PIN, HIGH);
  digitalWrite(BIB_PIN, LOW);
}
void roverTurnRight() {
  if (-1 == AIA_PIN) return;

  digitalWrite(AIA_PIN, HIGH);
  digitalWrite(AIB_PIN, LOW);
  digitalWrite(BIA_PIN, HIGH);
  digitalWrite(BIB_PIN, LOW);
}
void roverTurnLeft() {
  if (-1 == AIA_PIN) return;

  digitalWrite(AIA_PIN, LOW);
  digitalWrite(AIB_PIN, HIGH);
  digitalWrite(BIA_PIN, LOW);
  digitalWrite(BIB_PIN, HIGH);
}
