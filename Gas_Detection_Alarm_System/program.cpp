/*
Created 9AM , Dec 14, 2022
Project: Gas Detection Alarm System
*/

#include<LiquidCrystal.h>

LiquidCrystal lcd(13,12,8,9,10,11);//define Lcd pins RS,E,D4-D7

int sensor = A0;  //define sensor pin 
int analogValue = 0;//  set analog value 0 
int redled = 4;  //define led,speaker,fan pin
int greenled = 5; 
int speaker = 3; 
int fan = 2;


void setup()
{
  pinMode(sensor,INPUT); //set sensor,led,fan,speaker output
  pinMode(redled,OUTPUT);
  pinMode(greenled,OUTPUT);
  pinMode(speaker,OUTPUT);
  pinMode(fan,OUTPUT);
  Serial.begin(9600); //serial port  for debug
  lcd.begin(16,2); //set lcd
  
  
}

void loop()
{

  
  analogValue = analogRead(0); //read analog value 
  Serial.println(analogValue);  //display analog value 
  
  if(analogValue > 400) //if the sensor detects gas and value > 400
  {
  	digitalWrite(redled,HIGH);  //redled turn on
    digitalWrite(greenled,LOW); //greenled off
    digitalWrite(fan,HIGH);		//fan turn off
    tone(speaker,1000,1000);    //speaker turn on
    lcd.clear();
  	lcd.setCursor(0,0);    //first row
  	lcd.print("=ALERT-EVACUATE=");  //dispaly on lcd information and sensor value
  	lcd.setCursor(0,1);  // second row
  	lcd.print(analogValue);
    delay(500); 

  }
  else //else sensor value <400
  {
  
  	digitalWrite(redled,LOW); //redled turn off
    digitalWrite(greenled,HIGH); //greenled turn on
    digitalWrite(fan,LOW); //fan turn off
    lcd.clear();
  	lcd.setCursor(0,0);
  	lcd.print("=SAFE=");   //display on lcd information and sensor value
  	lcd.setCursor(0,1);
  	lcd.print(analogValue);
    delay(500);
  	lcd.clear();
  	lcd.setCursor(0,0);
  	lcd.print("Sensor now is:");
  	lcd.setCursor(0,1);
  	lcd.print(analogValue);
    delay(500);
  }

  
}
