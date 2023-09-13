#include <Servo.h>  // Thư viện điều khiển servo
#include <DFRobot_DHT11.h>
DFRobot_DHT11 DHT;

#define DHT11_PIN 10

// Khai báo đối tượng myservo dùng để điều khiển servo
Servo myservo;
int led = 13;
int test = 0;
int servoPin = 2;  // Khai báo chân điều khiển servo
int button = 3;
int temp = 1;
int status = 0;
char data;
int loa = 12;
void setup() {
  // Cài đặt chức năng điều khiển servo cho chân servoPin
  myservo.attach(servoPin);
  pinMode(led, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  pinMode(loa, OUTPUT);
  Serial.begin(9600);  // Mở giao tiếp Serial ở baudrate 9600
}
void loop() {
  // put your main code here, to run repeatedly:
  hienthongtin();
  if (DHT.temperature < 35) {
    dongcua();
    while (DHT.temperature < 35) {
      hienthongtin();
      if (digitalRead(button) == LOW) {
        delay(20);
        if (digitalRead(button) == LOW) {
          mocua();
          //delay(5000);
          while (digitalRead(button) == HIGH);
          dongcua();
        }
      }
      delay(1000);
    }
  } else {
    mocua();
  }
  while (DHT.temperature >= 35) {
    hienthongtin();
    //if(Serial.available())
    if (DHT.temperature > 50 || Serial.read() == '1') {
      Serial.println("Nhiet Do Qua Cao");
      while (status == 0) {
        digitalWrite(led, HIGH);
        delay(50);
        digitalWrite(led, LOW);
        delay(50);
        digitalWrite(loa, HIGH);
        if (digitalRead(button) == LOW || Serial.read() == '0') {
          //Serial.flush();
          digitalWrite(loa, LOW);
          break;
        }
      }
    }
    delay(1000);
    /*
      if(DHT.temperature> 50){
        while(status==0){
          digitalWrite(led,HIGH);
          delay(50);
          digitalWrite(led,LOW);
          delay(50);
          if(digitalRead(button)==LOW)
            break;
        }
      }
      */
    if (digitalRead(button) == LOW) {
      delay(20);
      if (digitalRead(button) == LOW) {
        dongcua();
      }
      //delay(5000);
      while (digitalRead(button) == HIGH);
      mocua();
    }
  }
  delay(1000);
}
void hienthongtin() {
  DHT.read(DHT11_PIN);
  Serial.print("Nhiet Do:");
  Serial.print(DHT.temperature);
  Serial.print(" C");
  Serial.print("\tDo Am:");
  Serial.print(DHT.humidity);
  Serial.println(" %");
}

void mocua() {
  Serial.println("MO CUA");
  for (test = 0; test <= 180; test += 1) {
    myservo.write(test);
    delay(15);
  }
}

void dongcua() {
  Serial.println("Dong Cua");
  for (test = 180; test >= 1; test -= 1) {
    myservo.write(test);
    delay(15);
  }
}
