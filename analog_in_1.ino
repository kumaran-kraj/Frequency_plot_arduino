/*
 * an exercise in LCD display and analog input
 * arduino samples frequency and has an oscilating array of pixels based on pitch
 * texted on a UM666 melody generator IC
 * 
 */
#include <LiquidCrystal.h>
#include<stdlib.h>
//defining custom "fonts" as a bit array for characer grid
byte s1[8]= { // Array of bytes
  B00000,// B stands for binary formatter and the 5 numbers are the pixels
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B11111,
};
byte s2[8]={ // Array of bytes
  B00000,// B stands for binary formatter and the 5 numbers are the pixels
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B11111,
  B00000,
};

byte s3[8]= { // Array of bytes
  B00000,// B stands for binary formatter and the 5 numbers are the pixels
  B00000,
  B00000,
  B00000,
  B00000,
  B11111,
  B00000,
  B00000,
};
byte s4[8]= { // Array of bytes
  B00000,// B stands for binary formatter and the 5 numbers are the pixels
  B00000,
  B00000,
  B00000,
  B11111,
  B00000,
  B00000,
  B00000,
};
byte s5[8]= { // Array of bytes
  B00000,// B stands for binary formatter and the 5 numbers are the pixels
  B00000,
  B00000,
  B11111,
  B00000,
  B00000,
  B00000,
  B00000,
};
byte s6[8]= { // Array of bytes
  B00000,// B stands for binary formatter and the 5 numbers are the pixels
  B00000,
  B11111,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
};
byte s7[8]= { // Array of bytes
  B00000,// B stands for binary formatter and the 5 numbers are the pixels
  B11111,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
};
byte s8[8]= { // Array of bytes
  B11111,// B stands for binary formatter and the 5 numbers are the pixels
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
};
/*
  
*/
const int buttonPin = 2;
//int sensorPin = A6;
//int sensorPin2 = A4;
//int sensorPin1 = A5;// select the input pin for the potentiometer (test)
      // select the pin for the LED (test)
int sensorValue = 0;// variable to store the value coming from the sensor
//int sensorValue3 = 0;
//int sensorValue2 = 0;//use if needed for more signal inputs 
//int sensorValue1 = 0;

int ds1=0;
//int ds2=0;
int tmp;
int tmp1;
int tmp2;
int tmp3;
int tmp4;

//bool ds11=0;
//bool ds12=0;
//bool t1=0;
//int t2=0;
//int d1=0;int d2=0;
char buf[10];
int ht,lt;
int freq;
LiquidCrystal lcd( 2, 3, 4, 5, 6, 7);
void setup() {
  // declare the ledPin as an OUTPUT:
  lcd.begin(16,2);
  //creating "custom character's" associiation with int value a
  lcd.createChar(1, s1);
  lcd.createChar(2, s2);
  lcd.createChar(3, s3);
  lcd.createChar(4, s4);
  lcd.createChar(5, s5);
  lcd.createChar(6, s6);
  lcd.createChar(7, s7);
  lcd.createChar(8, s8);

  
   pinMode(A0, INPUT);
   pinMode(13, INPUT);
 //Serial.begin(115200);
 Serial.begin(250000);
 ht= pulseIn(13,HIGH) ;
  freq=1000000/(ht);
  //buffering value , maybe use array instead
  tmp=freq;
  tmp1=tmp;
  tmp2=tmp1;
  tmp3=tmp2;
  tmp4=tmp3;
  //
  lcd.setCursor(0,0);
    lcd.write ("frequency:");
    lcd.setCursor(4,1);
    lcd.write ("Hz");
}

void loop() {

  sensorValue = analogRead(A0);
  Serial.print("\n sensor = ");
  Serial.print(sensorValue);

  
  ht= pulseIn(13,HIGH) ;//trigger on event pin goes high
  //lt= pulseIn(13,LOW);
  //buffering value , maybe use array 
  tmp4=tmp3;
  tmp3=tmp2;
  tmp2=tmp1;
  tmp1=tmp;
  tmp=freq;
  freq=1000000/(ht);
  //freq=ht;
  
  
  
  

  
  
ds1=abs(freq-tmp);//change temp value to see difference over longer time period 
  

  Serial.print("\t sensor = ");
  
  // if freq change is considerable change graph, considerable here is a delta of 500
  if (ds1>500)
  {Serial.print(500);
  freq=tmp3;
  }
  
  else
  {Serial.print(100);}
  //write frequency line to to lcd 
  if (ds1>50)
  {
    
    lcd.setCursor(0,1);
    itoa(freq,buf,10);
    lcd.write (buf);
    if(freq<1100)
    {lcd.setCursor(6,1);
    lcd.write (1);}
    else if(freq>1100&&freq<1320)
    {lcd.setCursor(6,1);
    lcd.write (2);}
    else if(freq>1320&&freq<1420)
    {lcd.setCursor(6,1);
    lcd.write (3);}
    else if(freq>1420&&freq<1500)
    {lcd.setCursor(6,1);
    lcd.write (4);}
    else if(freq>1500&&freq<1700)
    {lcd.setCursor(6,1);
    lcd.write (5);}
    else if(freq>1700&&freq<1800)
    {lcd.setCursor(6,1);
    lcd.write (6);}
    else if(freq>1800&&freq<2000)
    {lcd.setCursor(6,1);
    lcd.write (7);}
    else if(freq>2000)
    {lcd.setCursor(6,1);
    lcd.write (8);}
    
    
  }
  //print raw freq
  Serial.print("\t sensor = ");
  Serial.print(freq);
  
  //delay(1);
  //for stability 
   delayMicroseconds(50);
}
