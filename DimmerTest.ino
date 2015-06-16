int lightPin=2;
int brightnessRelayPin1=3;
int brightnessRelayPin2=4;

int value=3;
void setup()
{
  pinMode(lightPin,OUTPUT);
  pinMode(brightnessRelayPin1,OUTPUT);
  pinMode(brightnessRelayPin2,OUTPUT);
}

void loop()
{
  //value++;
  //value%=5;
  if(value==0)  
    digitalWrite(lightPin,LOW);
  else
  {
    digitalWrite(lightPin,HIGH); 
    if(value==1)
    {
       digitalWrite(brightnessRelayPin1,HIGH);
       digitalWrite(brightnessRelayPin2,HIGH);
    }
    else if(value==2)
    {
       digitalWrite(brightnessRelayPin1,LOW);
       digitalWrite(brightnessRelayPin2,HIGH);
    }
    else if(value==3)
    {
       digitalWrite(brightnessRelayPin1,HIGH);
       digitalWrite(brightnessRelayPin2,LOW);
    }
    else
    {
       digitalWrite(brightnessRelayPin1,LOW);
       digitalWrite(brightnessRelayPin2,LOW);
    }
  }
  //delay(2000);
}
