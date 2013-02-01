/*

Sample RGB Code for the Ultimate Microcontroller Pack
Code by alpinenapo on Make Projects. 
Build instructions here: http://makeprojects.com/Project/RGB+LED+Lamp/1144/1#.UQxTW1pdfNo

*/


#define red 9  // Red pin connected to pin 9
#define green 6 // Green pin connected to pin 9
#define blue 5 // Blue pin connected to pin 9

int val = 8 ; // It's the value for delay used between every for cicle
int di = 254; // It's the intensity of led
int i = 0; 
int rit = 1200;

void setup () {
  // The three pins of rgb led, used for OUTPUT
  pinMode ( red , OUTPUT );
  pinMode ( green , OUTPUT );
  pinMode ( blue , OUTPUT );
  
}

void loop () { 
  
  for ( i = 0 ; i < di ; i++) {
    analogWrite ( red , i );
    delay ( val );
  }
   
  delay ( rit );
  
  for ( i = di ; i > 0 ; i--) {
    analogWrite ( red , i );
    delay ( val );
  }   
  
  for ( i = 0 ; i < di ; i++) {
    analogWrite ( green , i );
    delay ( val );
  }
   
  delay ( rit ); 
   
  for ( i = di ; i > 0 ; i--) {
    analogWrite ( green , i );
    delay ( val );
  }   
  
  for ( i = 0 ; i < di ; i++) {
    analogWrite ( blue , i );
    delay ( val );
  }
   
  delay ( rit );
   
  for ( i = di ; i > 0 ; i--) {
    analogWrite ( blue , i );
    delay ( val );
  }   
}

