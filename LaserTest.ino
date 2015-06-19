int ldrPin1=A0;
int ldrPin2=A1;

int ldrValue1=0;
int ldrValue2=0;

String pattern="";
char ldrPrev1='0';
char ldrPrev2='0';
char ldrCur1='0';
char ldrCur2='0';

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  ldrPrev1=ldrCur1;
  ldrPrev2=ldrCur2;
  ldrValue1=analogRead(ldrPin1);
  if(ldrValue1>500)
    ldrCur1='1';
  else
    ldrCur1='0';
  ldrValue2=analogRead(ldrPin2);
  if(ldrValue2>500)
    ldrCur2='1';
  else
    ldrCur2='0';
  //Serial.print(ldrCur1);
  //Serial.print("\t");
  //Serial.print(ldrCur2);
  //Serial.println();
  
  if(ldrPrev1!=ldrCur1 || ldrPrev2!=ldrCur2)
  {
    Serial.println(pattern);
    pattern+=ldrCur1;
    pattern+=ldrCur2;
    int index1=pattern.indexOf("01111000");
    int index2=pattern.indexOf("10110100");
    if(index1>-1 && index1%2==0 && pattern[0]=='0')  //Entering pattern
      Serial.println("Entered");
    if(index2>-1 && index2%2==0 && pattern[0]=='1')  //Exiting pattern
      Serial.println("Exited");
  }
  if(ldrCur1=='0' && ldrCur2=='0')
  {
    pattern.remove(0);
  }
  
}
