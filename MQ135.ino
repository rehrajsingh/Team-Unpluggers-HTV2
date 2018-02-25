#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,7,8,9,10);

#define LED 6

float mq7 = A0; // CO
float mq2 = A1;   //smoke and methane
float mhz19 = A2;// CO2 select input pin for gasSensor

float val1 = 0;
float val2 = 0;
float val3 = 0;// variable to store the value coming from the sensor

void setup() 
{
  
Serial.begin(9600);
lcd.begin(16,2);
pinMode(LED,OUTPUT);


}

void loop()
{
val1 = analogRead(mq7);
val2 = analogRead(mq2);
val3 = analogRead(mhz19); // read the value from the pot

Serial.print("Carbon Monoxide ");
Serial.println( val1/175.471 );
lcd.setCursor(0,0);
lcd.print("CO ");
lcd.setCursor(3,0);
lcd.print(val1/175.471);
lcd.setCursor(8,0);
lcd.print("ppm");

Serial.print("Methane ");
Serial.println( val2-3.456 );
lcd.setCursor(0,1);
lcd.print("CH4 ");
lcd.setCursor(4,1);
lcd.print(val2-3.456 );
lcd.setCursor(11,1);
lcd.print("ppm" );

delay(1000);
lcd.clear();

Serial.print("Carbon Dioxide ");
Serial.println( val3/170 );
lcd.setCursor(0,0);
lcd.print("CO2 ");
lcd.setCursor(4,0);
lcd.print(val3/170);
lcd.setCursor(9,0);
lcd.print("ppm");

Serial.print("Smoke ");
Serial.println( val2-227.68 );
lcd.setCursor(0,1);
lcd.print("Smoke ");
lcd.setCursor(6,1);
lcd.print(val2-227.68);
lcd.setCursor(13,1);
lcd.print("ppm");

delay(1000);
lcd.clear();

if((val1/175.471)>=2)          //CO
digitalWrite(LED, );
else
digitalWrite(LED, LOW);



}

