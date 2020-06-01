#ifndef ROVER_H
#define ROVER_H

extern void roverInit(int a1, int a2, int b1, int b2);
extern void roverSetSpeed(byte inSpeed);
extern byte roverGetSpeed();
extern void roverStop();
extern void roverForward();
extern void roverReverse();
extern void roverTurnRight();
extern void roverTurnLeft();

#endif
