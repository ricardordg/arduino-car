#include "Ultrasonic.h"

Ultrasonic::Ultrasonic(){

}

Ultrasonic::Ultrasonic(int trigPin, int echoPin){
	this->trigPin = trigPin;
	this->echoPin = echoPin;
}

void Ultrasonic::setup(){
	pinMode(this->trigPin, OUTPUT);
	pinMode(this->echoPin, INPUT);
}

long Ultrasonic::getDistance(){
	long duration, distance;
  
	digitalWrite(trigPin, LOW);
	delayMicroseconds(5);
	digitalWrite(trigPin, HIGH);
	delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
	duration = pulseIn(echoPin, HIGH);
	distance = (duration / 2) / 29.1;
 
	return (distance);
}

