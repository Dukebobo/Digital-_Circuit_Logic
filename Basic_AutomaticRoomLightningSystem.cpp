
/*
Language: C++ 
Project: DLC_Q1_Finals
Description: Create an "Automatic Room Lightning System" with code
Instructor: Ms.Tan
ThinkCard URL: 
Submit Date: 
Refrence: https://www.youtube.com/watch?v=iHOWohC6Ecs

Modify By Duke

*/

// define variables pir, pts, tmp, temp is temperature value.
float pir,pts,tmp,temp;


void setup()
{
  
  pinMode(8, INPUT);//pinmode is input (PIR Sensor data)
  pinMode(5, OUTPUT);//pinmode is  out put(Relay PDT for light)
  pinMode(6, OUTPUT);//pinmode is  out put(Relaay PDT for light)
  pinMode(A5, INPUT);//pinmode is input (photoresistor data)
  pinMode(A4, INPUT);//pinmode is input (temperature data)
  Serial.begin(9600); //serial port  to monitor output data 
}


void loop()
{

  pir= digitalRead(8);//define pin D8 is PIR Sensor
  pts= analogRead(A5);//define pin A5 is photoresistor
  tmp= analogRead(A4);//define pin A4 is temperature


  Serial.println(pir);// monitor D8 PIR Sensor output data 
  Serial.println(pts);// monitor A5 photoresistor output data 
  Serial.println(tmp);// monitor A4 temperature output data 
  
  temp = ((double)tmp / 1024*5-0.5)*100; //get temperature and convert to temperature value 
  //(tmp vaule / 1024 *5v -0.5) =mA *100 = temperature value. 
  // (153/1024*5-0.5)*100 = 24.730°C
               
  if ( (pir>0) ) // Pir sensor  vaule > 0  (have people)
  {
    if ((pts<550)&&(temp>30)) //if photoresistor  value <550 (nigh) temp >30°C
    {
      digitalWrite(5, HIGH);//ligh turn on
      digitalWrite(6, HIGH);//fan turn on
    }
    else if((pts<550)&&(temp<30)) //if photoresistor  value <550 (nigh) temp < 30°C
    {
      digitalWrite(5, HIGH);//ligh turn on
      digitalWrite(6, LOW);//fan turn off
    }
    else if((pts>550)&&(temp>30)) //if photoresistor  value > 550 (day time ) temp >30°C
    {
      digitalWrite(5, LOW);// light turn off
      digitalWrite(6, HIGH);//fan turn on 
    }
    else if((pts>550)&&(temp<30)) //if photoresistor  value > 550 (day time ) temp <30°C
    {
      digitalWrite(5, LOW);// light turn off
      digitalWrite(6, LOW);// fan turn off
    }
  }
  else //Pir sensor  vaule < or =  0  (no people)
  {
    digitalWrite(5, LOW);// light turn off
    digitalWrite(6, LOW);// fan turn off
  }
}
