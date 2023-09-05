int button = 2;
int status = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(button,INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  if(digitalRead(button)==LOW)
  {
    delay(20);
    if(digitalRead(button)==LOW)
    {
      if(status == 0)
      {
        status = 1;
        Serial.println("Den Sang");
      }
      else
      {
        status = 0;
        Serial.println("Den Tat");
      }
      while(digitalRead(button)==LOW);
    }
  }
}
