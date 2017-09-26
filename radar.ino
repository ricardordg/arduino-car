// Includes the Servo library
#include <Servo.h>.

// Defines Tirg and Echo pins of the Ultrasonic Sensor
const int trigPin = 10;
const int echoPin = 11;

// Variables for the duration,distance and angle
long duration;
int distance;
int angle;

int MIN = 30;
int MAX = 150;

// String that will be send
char message[128];

//Position
char posX[] = "100";
char posY[] = "0";

Servo myServo; // Creates a servo object for controlling the servo motor

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input

  Serial.begin(9600);

  myServo.attach(12); // Defines on which pin is the servo motor attached
  //myServo.write(0);
}

void loop() {
  // rotates the servo motor from 15 to 165 degrees
  for(angle = MIN; angle < MAX; angle++){
    myServo.write(angle);
    
    distance = calculateDistance();// Calls a function for calculating the distance measured by the Ultrasonic sensor for each degree
    
    sendMessage(angle,distance);
    delay(30);
  }

    // Repeats the previous lines from 165 to 15 degrees
  for(angle = MAX; angle > MIN; angle--){
    myServo.write(angle);

    distance = calculateDistance();
      
    sendMessage(angle,distance);
    delay(30);
  }
}

void sendMessage(int angle_, int distance_) {
  char distanceChar[20];
  char angleChar[20];
  char str[128];

  sprintf(distanceChar, "%d", distance_);
  sprintf(angleChar, "%d", angle_);

  strcpy(str, posX);
  strcat(str, ",");
  strcat(str, posY);
  strcat(str, ",");
  strcat(str, distanceChar);
  strcat(str, ",");
  strcat(str, angleChar);
  strcat(str, "\n");

  //Serial.println(str);

  Serial.write(str);
}

// Function for calculating the distance measured by the Ultrasonic sensor
int calculateDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  distance = duration * 0.034 / 2;
  //distance = duration/58.2;
  return distance;
}
