# NTP CLOCK
This example shows you how to get time from NTP server and display it on lcd 16x2 using libraries like: 

>NTPClient.h - **this library being used for get time from NTP servers**

>ESP8266WiFi.h - **this library being used for connect to your network**

>WiFiUdp.h - **this library being used for UDP connection to NTP servers**

>Wire.h - **this library being used for communicate with I2C / TWI devices** 

>LiquidCrystal_I2C.h - **this library being used for controlling your display with i2c**

## Installing ESP8266 on arduino IDE
1. Open your arduino IDE and copy this http://arduino.esp8266.com/stable/package_esp8266com_index.json and paste in file-->preferences-->click small button on right side.

![alt text](https://github.com/maciokeks/ESP8266-NTP-on-lcd-16x2/blob/master/additional%20photos/button.PNG)

2. Go to Tools-->board:.....-->board manager-->select correct library and click install button
![alt text](https://github.com/maciokeks/ESP8266-NTP-on-lcd-16x2/blob/master/additional%20photos/ESP8266%20library.PNG)

3. When you are done with installing you can select your board and you are ready to upload your code 👍
![alt text](https://github.com/maciokeks/ESP8266-NTP-on-lcd-16x2/blob/master/additional%20photos/board%20manager.png)

## Solder your lcd and ESP8266
To connect this you need solder iron and some tin or you can use breadboard. You need to solder 4 wires to your ESP8266. Look on your i2c converter connected to lcd and there is GND, Vcc, SDA, SCL. Solder this pin using 4 wires like this:

> SDA---D2 or GPIO4

> SCL---D1 or GPIO5

> GND---GND

> Vcc---5V or 3.3V

![alt text](https://github.com/maciokeks/ESP8266-NTP-on-lcd-16x2/blob/master/additional%20photos/solder.PNG)

## Prepare your code for run
1. Write your network credentials to this field:
```
const char *ssid     = "xx";
const char *password = "xx";
```
2. Adjust your time zone UTC offset in this line of code `const long utcOffsetInSeconds = 7200;`, remember about summer and winter time
e.g. 
> For UTC -5.00 : -5 * 60 * 60 : -18000

> For UTC +1.00 : 1 * 60 * 60 : 3600

> For UTC +0.00 : 0 * 60 * 60 : 0

![alt text](https://github.com/maciokeks/ESP8266-NTP-on-lcd-16x2/blob/master/additional%20photos/Timezones2008_UTC-5.png)

3. Change your NTP server in ```NTPClient timeClient(ntpUDP, "europe.pool.ntp.org", utcOffsetInSeconds);```
e.g.
> Worldwide	pool.ntp.org

> Asia	asia.pool.ntp.org

> Europe	europe.pool.ntp.org

> North America	north-america.pool.ntp.org

> Oceania	oceania.pool.ntp.org

> South America	south-america.pool.ntp.org

4. Change your lcd properties in ```LiquidCrystal_I2C lcd(0x27, 16, 2)``` where (address on your i2c converter, length, height); 

<h2 align="center"># GOOD LUCK :smile::+1::smile::+1:</h2>

