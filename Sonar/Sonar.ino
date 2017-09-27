#include "Ultrasonic.h"
#include <Servo.h>

#define MAX 150
#define MIN 30

long duration;
int distance;
int angle;

//posição do sonar
char posX[] = "100";
char posY[] = "0";

//sensor ultrassonico
Ultrasonic *ultrasonic = new Ultrasonic(8,9);

//servo motor
Servo myServo;

void setup() {
  Serial.begin(9600);
  
  ultrasonic->setup();
  
  myServo.attach(12);
  myServo.write(0);
}

void loop() {
  
  
  for(angle = MIN; angle < MAX; angle++){
    myServo.write(angle);    
    distance = ultrasonic->getDistance();
    sendMessage(angle,distance);
    delay(60);
  }

  for(angle = MAX; angle > MIN; angle--){
    myServo.write(angle);
    distance = ultrasonic->getDistance();
    sendMessage(angle,distance);
    delay(60);
  }
}

void sendMessage(int angle_, int distance_) {
  char distanceChar[20];
  char angleChar[20];
  char message[128];

  sprintf(distanceChar, "%d", distance_);
  sprintf(angleChar, "%d", angle_);

  strcpy(message, posX);
  strcat(message, ",");
  strcat(message, posY);
  strcat(message, ",");
  strcat(message, distanceChar);
  strcat(message, ",");
  strcat(message, angleChar);
  
  Serial.println(message);
}
