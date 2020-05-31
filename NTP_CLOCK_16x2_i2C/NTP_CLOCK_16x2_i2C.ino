/*//////////////////////////////////////
 * library for this project http://arduino.idsl.pl/pliki/LiquidCrystal_I2C-1.1.2.zip 
 * SDA connected to D2 
 * SCL connected to D1
 * VCC conected to 3.3V or 5V pin on your board, 5V is better for refreshing LCD
 * GND connected to GND on your baord
 * 
 * 
*///////////////////////////////////////
#include <NTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h> 

const char *ssid     = "";//enter your network credentials
const char *password = "";

const long utcOffsetInSeconds = 7200;//adjust  UTC offset  for your timezone in milliseconds, timezones pictures are in this ZIP file, remember about summer or winter time 
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};//days of week, you can change this for your language :), [7]-days in the week, [12]-number of months in year
WiFiUDP ntpUDP;//UDP transmition
NTPClient timeClient(ntpUDP, "europe.pool.ntp.org", utcOffsetInSeconds);//enter proper NTP server for your location

LiquidCrystal_I2C lcd(0x27, 16, 2);//enter your lcd size (address on your i2c converter, length, height);

void setup() {
  Serial.begin(115200);
  lcd.init();//initialize your lcd 
  lcd.backlight();
  WiFi.begin(ssid, password);

  while(WiFi.status()!= WL_CONNECTED){//when you are not connected to your network then wait
  delay(500);
  
  Serial.print("Connecting to:");
  Serial.print(ssid);
  
  lcd.setCursor(0, 0);//(X,Y); positioning text or char on display
  lcd.print("Connecting to:");
  lcd.setCursor(0, 1);
  lcd.print(ssid);   
  }
  lcd.clear();
  Serial.print("connected");
  lcd.print("connected");
  lcd.setCursor(0, 0);
  delay(1000);
  lcd.clear();
  timeClient.begin();
  
}
void loop() {
  if(WiFi.status()!= WL_CONNECTED){//when WiFi is gone then print not connected 
    lcd.clear();
    lcd.print("not connected :(");
    Serial.print("not connected");
  }else{
    timeClient.update();//make update after 1000 millisecond = 1 second
    lcd.setCursor(0, 0); 
    lcd.print(timeClient.getFormattedTime());//print formatted time hours:minutes:second 
    lcd.setCursor(0,1);
    lcd.print(daysOfTheWeek[timeClient.getDay()]);//print day from char daysOfTheWeek
    delay(1000);

  }
}
