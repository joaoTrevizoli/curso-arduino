/* bmp180 test circuit
  __  _       _      ___   ___  _  _    __
 / / | | __ _| |__  ( _ ) / _ \| || |   \ \
/ /  | |/ _` | '_ \ / _ \| | | | || |_   \ \
\ \  | | (_| | |_) | (_) | |_| |__   _|  / /
 \_\ |_|\__,_|_.__/ \___/ \___/   |_|   /_/

*/
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Adafruit_BMP085.h>

LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE);

Adafruit_BMP085 bmp180;

void setup()
{
	Serial.begin(9600);
	lcd.begin(16, 2);
	if(!bmp180.begin())
	{
		Serial.println("The sensor wasn't not found");
		while(1){}
	}
}

void loop()
{
	Serial.print(bmp180.readAltitude());
	Serial.print(" ");
	Serial.print(bmp180.readTemperature());
	Serial.print(" ");
	Serial.println(bmp180.readPressure());

	delay(1000);
}
