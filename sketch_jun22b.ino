//Include used libraries

#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
//-------------------------------------
//Define all pins for used devices
#define SS_PIN 10 
#define RST_PIN 9

#define ACCESS_GRANTED_LED 2
#define ACCESS_DENIED_LED 3

MFRC522 mfrc522(SS_PIN, RST_PIN);
LiquidCrystal_I2C lcd(0x27, 16, 2); 
byte readCard[4];
String MasterTag = "47C17B4A";
String tagID = "";
//----------------------------------------
//Initialize rfid and lcd
void setup() {
  pinMode(ACCESS_GRANTED_LED, OUTPUT);
  pinMode(ACCESS_DENIED_LED, OUTPUT);

  Serial.begin(9600);

  SPI.begin();

  mfrc522.PCD_Init();
  delay(4);

  mfrc522.PCD_DumpVersionToSerial();

  lcd.init();
  lcd.backlight();

  Serial.println(" Access Control ");
  Serial.println("Scan Your Card>>");
  lcd.setCursor(0, 0);
  lcd.print(" Access Control ");
  lcd.setCursor(0, 1);
  lcd.print("Scan Your Card>>");
}
//------------------------------------------
//Loop function. Main piece of code. Provide authentication via key or card, and the appropriate response. References 'getID' function
void loop() {
  while (getID()) {
    if (tagID == MasterTag) {
      Serial.println(" Access Granted!");
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(" Access Granted! ");
      digitalWrite(ACCESS_GRANTED_LED, HIGH);
    } else {
      Serial.println(" Access Denied!");
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(" Access Denied!  ");
      digitalWrite(ACCESS_DENIED_LED, HIGH);
    }

    delay(2000);
    digitalWrite(ACCESS_GRANTED_LED, LOW);
    digitalWrite(ACCESS_DENIED_LED, LOW);

    Serial.println(" Access Control ");
    Serial.println("Scan Your Card>>");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(" Access Control ");
    lcd.setCursor(0, 1);
    lcd.print("Scan Your Card>>");
  }
}
//----------------------------------------------
//getId function. Cleare previous tag and utilize the mfrc522 library to recieve the new one.
boolean getID() {
  if (!mfrc522.PICC_IsNewCardPresent()) {
    return false;
  }

  if (!mfrc522.PICC_ReadCardSerial()) {
    return false;
  }

  tagID = "";

  for (uint8_t i = 0; i < 4; i++) {
    tagID.concat(String(mfrc522.uid.uidByte[i], HEX));
  }

  tagID.toUpperCase();

  mfrc522.PICC_HaltA();

  return true;
}
//-------------------------------------------------
