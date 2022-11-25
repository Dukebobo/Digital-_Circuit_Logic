// C++ code
//
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
