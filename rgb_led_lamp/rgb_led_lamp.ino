/* 

Original code from cyragia on Instructables (http://www.instructables.com/id/Fading-RGB-LED-Arduino/step3/Code/)
Slightly modified by Eric Weinhoffer.
Assembly instructions are available on Make Projects.

*/

#define GREEN 3
#define BLUE 5
#define RED 6
#define delayTime 20 // increase this value to increase the fading time between colors

void setup() 
{
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(RED, OUTPUT);
  digitalWrite(GREEN, HIGH);
  digitalWrite(BLUE, HIGH);
  digitalWrite(RED, HIGH);
}

int redVal;
int blueVal;
int greenVal;
 
void loop() 
{
  redVal = 255; // choose a value between 1 and 255 to change the color. 
  blueVal = 0;
  greenVal = 0;
  for(int i = 0; i < 255; i += 1) // fades out of red and into full (i = 255) green
  {
    greenVal += 1;
    redVal -= 1;
    analogWrite(GREEN, 255 - greenVal);
    analogWrite(RED, 255 - redVal);
    delay(delayTime);
  }
 
  redVal = 0;
  blueVal = 0;
  greenVal = 255;
  for(int i = 0; i < 255; i += 1)
  {
    blueVal += 1;
    greenVal -= 1;
    analogWrite(BLUE, 255 - blueVal);
    analogWrite(GREEN, 255 - greenVal);
    delay(delayTime);
  }
 
  redVal = 0;
  blueVal = 255;
  greenVal = 0;
  for(int i = 0; i < 255; i += 1)
  {
    redVal += 1;
    blueVal -= 1;
    analogWrite(RED, 255 - redVal);
    analogWrite(BLUE, 255 - blueVal);
    delay(delayTime);
  }
}
