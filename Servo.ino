#include <Servo.h>      // Thư viện điều khiển servo

// Khai báo đối tượng myservo dùng để điều khiển servo
Servo myservo;          

int servoPin = 2;       // Khai báo chân điều khiển servo
void setup ()
{
    // Cài đặt chức năng điều khiển servo cho chân servoPin
    myservo.attach(servoPin); 
    Serial.begin(9600); // Mở giao tiếp Serial ở baudrate 9600
}

void loop ()
{
    
    for(int i = 0; i < 180; i += 1){ 
        myservo.write(i);
        delay(15);
    }
    
    for(int i = 180; i>=1; i-=1) {                           
        myservo.write(i);
        delay(15);
    } 
  
}
