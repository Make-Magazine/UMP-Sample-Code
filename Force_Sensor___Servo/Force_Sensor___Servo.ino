/* Force Sensor + Servo Test
 
Connect one end of the Force Sensitive Resistor to power, the other end to Analog 0.
Then connect one end of a 10KΩ resistor from Analog 0 to ground, and a servo to D9.
Build Instructions on Make Projects: http://makeprojects.com/Project/Control+a+Servo+with+a+Force-Sensitive+Resistor/3269/1#.UQw251pdfNo

*/

#include <Servo.h>

Servo myservo;

int pos;
int pin = 0;     // pin the sensor and 10k pulldown resistor
int force;     // the analog reading from the FSR resistor divider
 
void setup() 
{
  Serial.begin(9600);   
  myservo.attach(9);  // pin the servo is connected to
}
 
void loop()
{
  force = analogRead(pin);  // Reads the FSR
  Serial.print("Analog reading = "); 
  Serial.println(force); // This will print the raw force value
  pos = map(force, 0, 1023, 0, 179); // Scales the force reading to degrees for servo control
  Serial.print("Adjusted reading = ");
  Serial.println(pos); // This will print the adjusted servo reading (an angle)
  myservo.write(pos); // Write the new angle to the servo
  delay(150); // Delay 150 milliseconds before taking another reading
} 
