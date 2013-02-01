/*

Ultimate Microcontroller Pack Sample Code - Using a 5V Motor with the Arduino
For build instructions, head over to Make Projects: http://makeprojects.com/Project/Control+a+5V+Motor+with+the+Arduino/3270/1#.UQxOI1pdfNo

Upon uploading, open the serial monitor and type in a motor speed, from 0 to 255.

*/
 
 
int motorPin = 3;
 
void setup() 
{ 
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600);
  while (! Serial);
  Serial.println("Speed 0 to 255");
} 
 
 
void loop() 
{ 
  if (Serial.available())
  {
    int speed = Serial.parseInt(); 
    if (speed >= 0 && speed <= 255) // This if statement will prevent the user from entering invalid motor speeds
    {
      analogWrite(motorPin, speed); 
    }
  }
} 
