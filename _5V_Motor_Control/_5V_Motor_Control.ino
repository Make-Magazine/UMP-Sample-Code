/*

Ultimate Microcontroller Pack Sample Code - Using a 5V Motor with the Arduino
For build instructions, head over to Make Projects: http://makeprojects.com/Project/Control+a+5V+Motor+with+the+Arduino/3270/1#.UQxOI1pdfNo

Upon uploading, open the serial monitor and type in a motor speed, from 0 to 255.

*/
 
 
int motorPin = 3;
int newspeed;
 
void setup() 
{ 
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600);
  while (! Serial);
  Serial.println("Speed 0 to 100%");
} 
 
 
void loop() 
{ 
  if (Serial.available())
  {
    int speed = Serial.parseInt(); 
    newspeed = map(speed, 0, 255, 0, 100); // Scales the force reading to degrees for servo control
    if (newspeed >= 0 && newspeed <= 100) // This if statement will prevent the user from entering invalid motor speeds
    {
      analogWrite(motorPin, newspeed); 
    }
  }
} 
