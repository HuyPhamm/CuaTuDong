#include <Servo.h>      // Thư viện điều khiển servo
#include <DFRobot_DHT11.h>
DFRobot_DHT11 DHT;

#define DHT11_PIN 10

// Khai báo đối tượng myservo dùng để điều khiển servo
Servo myservo;
int led = 13;          
int test = 0;
int servoPin = 2;       // Khai báo chân điều khiển servo
int button = 3;
int temp = 1;
void setup ()
{
    // Cài đặt chức năng điều khiển servo cho chân servoPin
    myservo.attach(servoPin); 
    pinMode(led, OUTPUT);
    pinMode(button,INPUT_PULLUP);
    Serial.begin(9600); // Mở giao tiếp Serial ở baudrate 9600
}
void loop() {
  // put your main code here, to run repeatedly:
  DHT.read(DHT11_PIN);
  Serial.print("Do AM:");
  Serial.print(DHT.humidity);
  Serial.println(" %");
    if(DHT.humidity>=85)
    {
      digitalWrite(led,HIGH);
      Serial.print("DONG CUA");
      for(test = 180; test>=1; test-=1) 
      {                           
        myservo.write(test);
        delay(15);
      } 
      Serial.println();
      while(DHT.humidity>=85)
      {
        DHT.read(DHT11_PIN);
        Serial.print("Do AM:");
        Serial.print(DHT.humidity);
        Serial.println(" %");
        if(digitalRead(button)==LOW)
        {
          delay(20);
          if(digitalRead(button)==LOW)
          {
            Serial.println("MO CUA");
            for(test = 0; test<=180; test+=1) 
            {                           
              myservo.write(test);
              delay(15);
            } 
          //delay(5000);
            while(digitalRead(button)==HIGH);
            Serial.println("Dong Cua");
            for(test = 180; test>=1; test-=1) 
            {                           
              myservo.write(test);
              delay(15);
            }
          }  
        }
        delay(1000);
      }
    }
    else
    {
      digitalWrite(led,LOW);
      Serial.println("MO CUA");
      for(test = 0; test<=180; test+=1) 
      {                           
        myservo.write(test);
        delay(15);
      } 
      Serial.println();
      while(DHT.humidity<85)
      {
        DHT.read(DHT11_PIN);
        Serial.print("Do AM:");
        Serial.print(DHT.humidity);
        Serial.println(" %");
        if(digitalRead(button)==LOW)
        {
          delay(20);
          if(digitalRead(button)==LOW)
          {
            Serial.println("Dong Cua");
            for(test = 180; test>=1; test-=1) 
            {                           
              myservo.write(test);
              delay(15);
            } 
          }
          //delay(5000);
          while(digitalRead(button)==HIGH);
          Serial.println("MO CUA");
          for(test = 0; test<=180; test+=1) 
          {                           
            myservo.write(test);
            delay(15);
          }        
        }
        delay(1000);
      }
    }
}
