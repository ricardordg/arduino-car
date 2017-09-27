#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include "Arduino.h"

class Ultrasonic{
	private:
		int trigPin = 10;
		int echoPin = 11;
	public:
		Ultrasonic();
		Ultrasonic(int trigPin, int echoPin);
		void setup();
		long getDistance();
};

#endif
