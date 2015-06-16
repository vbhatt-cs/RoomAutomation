#include<IRremote.h>

IRsend irsend;
#define TOPBIT 0x800000

unsigned long data1=0xB24D5F;
unsigned long data11=0xA040BF;
unsigned long data2=0xB24D3F;
unsigned long data21=0xC040BF;
unsigned long data3=0xB24D9F;
unsigned long data31=0x6040BF;
  
// the setup function runs once when you press reset or power the board
void setup() 
{
  //Serial.begin(9600);
}

// the loop function runs over and over again until power down or reset
void loop() 
{ 
  sendData(data1,data11);
  irsend.space(5000);
  sendData(data1,data11);
  delay(5000);
  sendData(data2,data21);
  irsend.space(5000);
  sendData(data2,data21);
  delay(5000);
  sendData(data3,data31);
  irsend.space(5000);
  sendData(data3,data31);
  delay(5000);
  //Serial.println();
}

void sendData(unsigned long data0,unsigned long data01)
{
  irsend.enableIROut(38);
  irsend.mark(4400);
  irsend.space(4300);
  for (int i = 0; i < 24; i++) {
    if (data0 & TOPBIT) {
      //Serial.print("500 -1650 ");
      //Serial.print("1");
      irsend.mark(600);  
      irsend.space(1550);  
    } 
    else {
      //Serial.print("500 -600 ");
      //Serial.print("0");
      irsend.mark(600);
      irsend.space(470);  
    }
    data0 <<= 1;
  }
  for (int i = 0; i < 24; i++) {
    if (data01 & TOPBIT) {
      //Serial.print("600 -1400 ");
      //Serial.print("1");
      irsend.mark(600);  
      irsend.space(1550);  
    } 
    else {
      //Serial.print("600 -400 ");
      //Serial.print("0");
      irsend.mark(600);
      irsend.space(470);  
    }
    data01 <<= 1;
  }
  //Serial.print("600");
  irsend.mark(600);
  irsend.space(0);
}
