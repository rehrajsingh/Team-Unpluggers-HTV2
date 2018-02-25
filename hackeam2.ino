//Fingerprint
#include <Adafruit_Fingerprint.h>
#include <SoftwareSerial.h>

int getFingerprintIDez();

SoftwareSerial mySerial(2, 3);
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

//GSM
SoftwareSerial mySerial1(10,11); //(RX,TX)
char sendmessage;

#include <LiquidCrystal.h>
LiquidCrystal lcd(8,9,4,5,6,7);


void setup()  
{
lcd.begin(16, 2);
mySerial1.begin(9600);
 Serial.begin(9600);
  
  //Fingerprint
  while (!Serial);  // For Yun/Leo/Micro/Zero/...
  
  Serial.begin(9600);
  Serial.println("Adafruit finger detect test");

  finger.begin(57600);
  
  if (finger.verifyPassword()) {
    Serial.println("Found fingerprint sensor!");
    
  } else {
    Serial.println("Did not find fingerprint sensor :(");
    while (1);
  }
  Serial.println("Waiting for valid finger...");
  lcd.setCursor(0,0);
  lcd.print("Waiting");  
}


void loop()                     
{
  getFingerprintIDez();
  delay(50);    
    
}

  uint8_t getFingerprintID() {
 
 //Fingerprint
  uint8_t p = finger.getImage();
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image taken");
     break;
    case FINGERPRINT_NOFINGER:
      Serial.println("No finger detected");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return p;
    case FINGERPRINT_IMAGEFAIL:
      Serial.println("Imaging error");
      return p;
    default:
      Serial.println("Unknown error");
      return p;
  }

  //success!

  p = finger.image2Tz();
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image converted");
      break;
    case FINGERPRINT_IMAGEMESS:
      Serial.println("Image too messy");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return p;
    case FINGERPRINT_FEATUREFAIL:
      Serial.println("Could not find fingerprint features");
      return p;
    case FINGERPRINT_INVALIDIMAGE:
      Serial.println("Could not find fingerprint features");
      return p;
    default:
      Serial.println("Unknown error");
      return p;
  }
  
  //converted!
  p = finger.fingerFastSearch();
  if (p == FINGERPRINT_OK) {
    Serial.println("Found a print match!");
    
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    Serial.println("Communication error");
    return p;
  } else if (p == FINGERPRINT_NOTFOUND) {
    Serial.println("Did not find a match");
    return p;
  } else {
    Serial.println("Unknown error");
    return p;
  }   
  
  // found a match!
  Serial.print("Found ID #"); Serial.print(finger.fingerID); 
  //lcd.print("Found ID"); lcd.print(finger.fingerID);
  Serial.print(" with confidence of "); Serial.println(finger.confidence);
  //lcd.print(" with confidence of "); lcd.print(finger.confidence);
   if (finger.fingerID == 27){
      Serial.println("Authority(1)");
     lcd.setCursor(0,0);
     lcd.print("Authority(1)");
     delay(3000);
     lcd.setCursor(0,0);
     lcd.print("                 ");
     
     return finger.fingerID;

      
   }
   
   else if (finger.fingerID == 16) {
     Serial.println("Authority(2)");
     lcd.setCursor(0,1);
     lcd.print("Authority(2)");
     delay(3000);
     lcd.setCursor(0,1);
     lcd.print("                 ");
     return finger.fingerID;
   } 
   
   else if (finger.fingerID == 44) {
      Serial.println("Authority(3)");
     lcd.setCursor(0,1);
     lcd.print("Authority(3)");
     delay(3000);
     lcd.setCursor(0,1);
     lcd.print("                 ");
     return finger.fingerID;
   } 
   
 lcd.clear();
 
} 

// returns -1 if failed, otherwise returns ID #
int getFingerprintIDez() {
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.image2Tz();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK)  return -1;
  
  // found a match!
  Serial.print("Found ID #"); Serial.print(finger.fingerID);
  
  lcd.print("Found ID"); lcd.print(finger.fingerID); 
  lcd.clear();
  Serial.print(" with confidence of "); Serial.println(finger.confidence);
  if (finger.fingerID == 27){
      Message();
     Serial.println("Authority(1)");
     lcd.setCursor(0,1);
     lcd.print("Authority(1)");
     delay(3000);
     lcd.setCursor(0,1);
     lcd.print("                 ");
     
     return finger.fingerID;

   
   } 
   
   else if (finger.fingerID == 16) {
     Message1();
     Serial.println("Authority(2)");
     lcd.setCursor(0,1);
     lcd.print("Authority(2)");
     delay(3000);
     lcd.setCursor(0,1);
     lcd.print("                 ");
     return finger.fingerID;
   } 
   
   else if (finger.fingerID == 44) {
     Message2();
      Serial.println("Authority(3)");
     lcd.setCursor(0,1);
     lcd.print("Authority(3)");
     delay(3000);
     lcd.setCursor(0,1);
     lcd.print("                 ");
     return finger.fingerID;
   } 
 lcd.clear();
}
//GSM
void Message()
{
  mySerial1.println("AT+CMGF=1");
  Serial.println("AT+CMGF=1");//Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial1.println("AT+CMGS=\"+918800108284\"\r"); // Replace x with mobile number
  Serial.println("AT+CMGS=\"+918800108284\"\r");
  delay(1000); 
  mySerial1.println("Snow Removed ; Date - 21/02/18 ; Area : Montrea, Quebec ");// The SMS text you want to send
  delay(1000);
  mySerial1.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
          
          
 //if (mySerial.available()>0)
   //Serial.write(mySerial.read());
  Serial.println("");
  Serial.println("Message Sent");
  lcd.print("Message Sent");
 
 }


void Message1()
{
  mySerial1.println("AT+CMGF=1");
  Serial.println("AT+CMGF=1");//Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial1.println("AT+CMGS=\"+918800108284\"\r"); // Replace x with. mobile number
  Serial.println("AT+CMGS=\"+918800108284\"\r");
  delay(1000); 
  mySerial1.println("Snow Removed ; Date - 21/02/18 ; Area :  Sherbrooke, Quebec ");// The SMS text you want to send
  delay(1000);
  mySerial1.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
          
          
 //if (mySerial.available()>0)
   //Serial.write(mySerial.read());
  Serial.println("");
  Serial.println("Message Sent");
  lcd.print("Message Sent");
 
 }


void Message2()
{
  mySerial1.println("AT+CMGF=1");
  Serial.println("AT+CMGF=1");//Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial1.println("AT+CMGS=\"+918800108284\"\r"); // Replace x with mobile number
  Serial.println("AT+CMGS=\"+918800108284\"\r");
  delay(1000); 
  mySerial1.println(" ");// The SMS text you want to send
  delay(1000);
  mySerial1.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
          
          
 //if (mySerial.available()>0)
   //Serial.write(mySerial.read());
  Serial.println("Snow Removed ; Date - 21/02/18 ; Area :  Gatineau, Quebec ");
  Serial.println("Message Sent");
  lcd.print("Message Sent");
 
 }

