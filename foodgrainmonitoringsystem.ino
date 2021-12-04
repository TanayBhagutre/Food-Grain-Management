#include <dht.h>

#define dht_apin A0 // Analog Pin sensor is connected to

const int sensor_pin =A1;

#define BULB 7
#define m1 2
#define m2 3
#define m3 4 
#define m4 5
#define MOISTURE_SENSOR 7
#define trig 33
#define echo 34
#define buzzer 15

int WET= 3; 
int DRY= 2;  
int Sensor= A1; // Soil Sensor input at Analog PIN A0
int value= 0;
long duration;
int distance;
 
dht DHT;
 
void setup(){
  pinMode(BULB, OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(15,OUTPUT);
  pinMode(WET, OUTPUT);
 
  Serial.begin(9600);
  delay(500);//Delay to let system boot
  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
  delay(1000);//Wait before accessing Sensor
//  pinMode(BULB, OUTPUT);
//  pinMode(2,OUTPUT);
//  pinMode(3,OUTPUT);
//  pinMode(4,OUTPUT);
//  pinMode(5,OUTPUT);
//  pinMode(15,OUTPUT);
//  pinMode(WET, OUTPUT);
   
   delay(2000);
   pinMode(33,OUTPUT);
   pinMode(34,INPUT);
   pinMode(15,OUTPUT);
  
  
 
}//end "setup()"
 
void loop(){
  
float moisture_percentage;
delay(5000);
   Serial.print("MOISTURE LEVEL : ");
   value= analogRead(Sensor);
   value= value/10;
   moisture_percentage = ( ( (value/1023.00) * 100 ) );
   Serial.println(moisture_percentage );
  
  //Start of Program 

    DHT.read11(dht_apin);
    
    Serial.print("Current humidity = ");
    Serial.print(DHT.humidity);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(DHT.temperature); 
    Serial.println("C  ");
    // Clears the trigPin condition
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echo, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  if(distance<15){
    digitalWrite(buzzer, HIGH);
    
  }
  else{
    digitalWrite(buzzer, LOW);
    
  }

    if(DHT.temperature < 28  ){
      digitalWrite(BULB,HIGH);
     
       digitalWrite(m1,HIGH);
      digitalWrite(m2,LOW);
      digitalWrite(m3,LOW);
      digitalWrite(m4,LOW);
    }
    else{
      digitalWrite(BULB,LOW);
      
       digitalWrite(m1,LOW);
      digitalWrite(m2,LOW);
      digitalWrite(m3,HIGH);
      digitalWrite(m4,LOW);
    }
}
