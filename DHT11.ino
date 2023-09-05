// Gọi thư viện DHT11
#include <DFRobot_DHT11.h>
DFRobot_DHT11 DHT;

#define DHT11_PIN 10


void setup() {
  Serial.begin(9600);
}
 
void loop() {
  DHT.read(DHT11_PIN);
  Serial.print("Nhiet Do:");
  Serial.print(DHT.temperature);
  Serial.println(" C");
  Serial.print("Do Am:");
  Serial.print(DHT.humidity);
  Serial.println(" %");
  Serial.println();
  delay(1000);                     //Đợi 1 giây
}