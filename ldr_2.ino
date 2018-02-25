#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,7,6,5,4);
float i;
void setup() {
 Serial.begin(9600);
 pinMode(3,OUTPUT);
  
}

void loop() {
  

  i=analogRead(A0);
  Serial.println(i);
  lcd.setCursor(0,0);
   
  if((i>=0)&&(i<=340))
  
  {
   lcd.print("Low Turbidity");
   lcd.setCursor(0,1);
   lcd.print("pH-> basic");
   delay(100);
   lcd.setCursor(0,0);
   lcd.print("                ");
   lcd.setCursor(0,1);
   lcd.print("                ");
   Serial.println("Low Turbidity");
 
  }
  
else if((i>=341)&&(i<=899))
  
  {
   lcd.print("Medium Turbidity");
   lcd.setCursor(0,1);
   lcd.print("pH-> neutral");
   delay(100);
   lcd.setCursor(0,0);
   lcd.print("                ");
   lcd.setCursor(0,1);
   lcd.print("                ");
   Serial.println("Medium Turbidity");
  }

  else 
  
  {lcd.setCursor(0,0);
   lcd.print("High Turbidity");
   lcd.setCursor(0,1);
   lcd.print("pH-> neutral");
   delay(100);
   lcd.setCursor(0,0);
   lcd.print("                ");
   lcd.setCursor(0,1);
   lcd.print("                ");
   Serial.println("High Turbidity");
  }
  
}
