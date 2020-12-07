#include <M5StickC.h>
#include <M5StickC.h>
#include <Tone32.h>
#include "arow.h"

#define BUZZER_PIN 0
#define BUZZER_CHANNEL 0

float accX = 0;
float accY = 0;
float accZ = 0;

char nn[9]={'c','d','e','f','g','a','b','c','d'};


int notes[9]={NOTE_C6,NOTE_D6,NOTE_E6,NOTE_F6,NOTE_G6,NOTE_A6,NOTE_B6,NOTE_C7,NOTE_D7};
float temp = 0;
void setup() {
  pinMode(37,INPUT);
  M5.begin();
  M5.Lcd.setRotation(0);
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setTextSize(1);
  M5.Lcd.setSwapBytes(true);
  delay(100);
  M5.MPU6886.Init();
  pinMode(37,INPUT_PULLUP);
  M5.Lcd.drawString("TONE",44,8,1);
  M5.Lcd.fillRect(50,22,2,132,TFT_RED);
  for(int i=0;i<8;i++){
  M5.Lcd.drawString(String(nn[i]),60,135-(i*16),2);
  M5.Lcd.fillRect(48,144-(i*16),5,2,TFT_RED);
  }

}
int y=0;
int y2=0;
int i=0;
bool pres=false;
void loop() {
  
 if(pres==0){
  M5.MPU6886.getAccelData(&accX,&accY,&accZ);
  


    int v=int(accY*1000);
    i=map(v,0,1000,0,8);
    y=137-(i*16);
    
    if(i>7)
    i=7;

    if(i<0)
    i=0;
 
 if(y!=y2){
 M5.Lcd.fillRect(26,y2,16,16,TFT_BLACK);
 M5.Lcd.pushImage(26,y,16,16,arr);
 y2=y;
 }}
 
 
  

 if(digitalRead(37)==LOW){
 pres=1;
 tone(BUZZER_PIN, notes[i],500, BUZZER_CHANNEL);
 M5.Lcd.drawString(String(nn[i]),8,6,4);
 
 }else{
  M5.Lcd.fillRect(8,6,18,22,TFT_BLACK);
 noTone(BUZZER_PIN,BUZZER_CHANNEL);
 pres=0;}
 


}
