#include "Motor.h"

Motor::Motor() {
	PULSE_MIN = 500;
	PULSE_MAX = 2100;
}

Motor::Motor(const int MODE) {
	if (MODE == 0) {
		PULSE_MIN = 500;
		PULSE_MAX = 2100;
	}
	if (MODE == 1) {
		PULSE_MIN = 900;
		PULSE_MAX = 2100;
	}
}

void Motor::mode(const int MODE) {
	if (MODE == 0) {
		PULSE_MIN = 500;
		PULSE_MAX = 2100;
	}
	if (MODE == 1) {
		PULSE_MIN = 900;
		PULSE_MAX = 2100;
	}
}

void Motor::attach(const int PIN) {
	servo.attach(PIN);
}

void Motor::write(const int ANGLE) {
	const int PULSE_WIDTH = 
		map(ANGLE, 0, 180, PULSE_MIN, PULSE_MAX);
	servo.writeMicroseconds(PULSE_WIDTH);
	// servo.write(ANGLE);
}