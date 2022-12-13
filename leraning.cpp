//  practice 10PM Dec 13, 2022  
// for sensor debug.

int sensor = A0;  //define sensor pin 
int analogValue = 0; //  set analog value 0 


void setup()
{
  pinMode(sensor, OUTPUT); //set pin A0 output
  Serial.begin(9600); //serial port  for debug
  
  
}

void loop()
{
	
  analogValue = analogRead(0); //read analog value 
  
  Serial.println(analogValue);  //display analog value 
  
  Serial.println(analogValue,DEC); // decimal output
 
  Serial.println(analogValue,OCT);  // octal output 
  
  Serial.println(analogValue,BIN);  // binary output
  
  Serial.println(analogValue,HEX); //hexcimal output 
   
  delay(1000);  //delay 1 sencond 

  
}
