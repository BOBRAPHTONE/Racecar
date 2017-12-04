/*
* Arduino code for controlling the four wheels
* Uses a motor driver to specify the direction of rotation ,speed etc
* Firmware also includes GSM ,GPS and LCD funtionality 
*
*/


//includes
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int pwm = 12; // assigns pin 12 to variable pwm
int pot = A0; // assigns analog input A0 to variable pot
int t1 = 0;   // declares variable t1
int t2 = 0;   // declares variable t2

String location ="";
/*
* Funtion Prototypes
*/

void display_location(); //display location on an lcd
void send_location(); //send the location as an sms
void get_location(); //read the location from the gps module


void setup()  // setup loop
{
  pinMode(pwm, OUTPUT); // declares pin 12 as output
  pinMode(pot, INPUT);  // declares pin A0 as input
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  
}
void loop()
{
  t2= analogRead(pot); // reads the voltage at A0 and saves in t2
  t1= 1000-t2;         // subtracts t2 from 1000 ans saves the result in t1
  digitalWrite(pwm, HIGH); // sets pin 12 HIGH
  delayMicroseconds(t1);   // waits for t1 uS (high time)
  digitalWrite(pwm, LOW);  // sets pin 12 LOW
  delayMicroseconds(t2);   // waits for t2 uS (low time)
}


void display_location(String location)
{
 // Print the location to the LCD.
  lcd.print("Location of Car %s",location);
}