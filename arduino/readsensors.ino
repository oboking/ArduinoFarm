#include <dht.h>
dht DHT;

#include <LiquidCrystal_I2C.h>

#include <Wire.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // run ic2_scanner sketch and get the IC2 address, which is 0x3f in my case,it could be 0x3f in many cases

#define DHT11_PIN 7

int photocellPin = 3;     // the cell and 10K pulldown are connected to a3
int photocellReading;

int hum;  //Stores humidity value
int temp; //Stores temperature value

void setup() {
  // put your setup code here, to run once:
  lcd.init();                      // initialize the lcd 
  Serial.begin(9600);  
}

void loop() {
  // put your main code here, to run repeatedly:
  photocellReading = analogRead(photocellPin);
  
  int chk = DHT.read11(DHT11_PIN);
  
  // set cursor to first line
  lcd.setCursor(0, 0);
  // Print a message to the LCD.
  lcd.backlight();
  temp = DHT.temperature;
  hum = DHT.humidity;
  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.print(" ");
  lcd.print((char)223);
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print("Hum: ");
  lcd.print(hum);
  lcd.print(" %");
 
  Serial.println(photocellReading);
  Serial.println(temp);
  Serial.println(hum);
  
  delay(360000);
}
