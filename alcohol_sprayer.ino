// defines pins numbers
const int trigPin = 2;
const int echoPin = 4;
// defines variables
long duration;
int distance;
#include <Servo.h>

Servo spray;  // create servo object to control a servo

void setup() {
spray.attach(9);
spray.write(0);
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(LED_BUILTIN, OUTPUT);
//Serial.begin(9600); // Starts the serial communication
}
void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
if(distance > 200){
 distance =200; 
}
// Prints the distance on the Serial Monitor
//Serial.print("Distance: ");//debug info
//Serial.println(distance);
digitalWrite(LED_BUILTIN, LOW);  

if(distance < 20){
  for(int loops = 0; distance < 30 && loops < 4; loops++){//won't spray more than 4 times.
    //distance calculations
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);
    // Calculating the distance
    distance= duration*0.034/2;//I have to add the ultrasonic code in here so that distance can be updated inside the for loop.
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    spray.write(10);
    delay(500);
    spray.write(35);
    delay(800);
  }
  
}else{
   digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
   spray.write(10);
}
delay(1000);//only checks every second instead of milisecond.
}
