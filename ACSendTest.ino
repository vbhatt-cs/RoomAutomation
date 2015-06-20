#include<IRremote.h>

IRsend irsend;
#define TOPBIT 0x800000

unsigned long data1=0xB24D5F;//24 C, F2
unsigned long data11=0xA040BF;
unsigned long data2=0xB24D3F;//24C F3
unsigned long data21=0xC040BF;
unsigned long data3=0xB24D9F;//24C F1
unsigned long data31=0x6040BF;
unsigned long data4=0xB24D7B;//OFF
unsigned long data41=0x84E01F;
unsigned long data5=0xB24D3F;//25 C F3
unsigned long data51=0xC0C03F;
unsigned long data6=0xB24D9F;//25 C F1
unsigned long data61=0x60C03F;
unsigned long data7=0xB24D5F;//25 C F2
unsigned long data71=0xA0C03F;
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
