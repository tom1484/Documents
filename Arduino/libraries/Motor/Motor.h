#ifndef MOTOR_H
#define MOTOR_H
#endif

#include <Arduino.h>
#include <Servo.h>

#define MG996R 0
#define AX1 1

class Motor {
public:
	Motor();
	Motor(const int);
	void mode(const int);
	void attach(const int);
	void write(const int);
private:
	Servo servo;
	int PULSE_MIN, PULSE_MAX;
};