// C++ code
/*
Language: C++ 
Project: DLC_Q1_Finals
Description: Create an "Automatic Room Lightning System" with code
Instructor: Ms.Tan
ThinkCard URL:https://www.tinkercad.com/things/cSiiL6Sid4z 
Submit Date: 7:59AM,Nov.26,2022
Refrence: https://www.youtube.com/watch?v=iHOWohC6Ecs

Modify By Duke

*/
//define variables.
float pir,pts;

void setup()
{
  pinMode(A5,INPUT);//Photoresistor
  pinMode(8,INPUT);//PIR sensor
  pinMode(5,OUTPUT);//Power control 
  Serial.begin(9600);//serial prot
}

void loop()
{
  
  pts= analogRead(A5);//defin pin A5 is Photoresistor.
  pir= digitalRead(8);
  
  Serial.println(pts);// serial monitor pts value.
  Serial.println(pir);
  
  if((pir>0)) //motion detection alarms has data >0.
  {
	if((pts<500))
    {
    	digitalWrite(5,HIGH);//if pts <500,turn on light
    
    }
   	else
    {
    	digitalWrite(5,LOW);//else pts > 500, turn off light 
    
    }
  
  }
  else //else motion detection alarms no data = 0
  {
  	
    digitalWrite(5,LOW); //turn off light.
  
  }
  
  
  
}
