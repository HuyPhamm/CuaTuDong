int led = 2;
char data;
int status = 0;
int loa = 5;
void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);
  pinMode(loa,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available())
  {
    data = Serial.read();
    Serial.println(data);
  }
  if(data=='1')
  {
    data=Serial.read();
    while(status == 0)
    {
      digitalWrite(led,HIGH);
      delay(50);
      digitalWrite(led,LOW);
      delay(50);
      digitalWrite(loa,HIGH);
      if(Serial.read() == '0')
        break;
    }
  }
  else if(data == '0'){
    digitalWrite(led,LOW);
    digitalWrite(loa,LOW);
    status = 0;
  }
}
