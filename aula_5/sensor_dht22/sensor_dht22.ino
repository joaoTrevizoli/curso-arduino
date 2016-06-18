/* DHT 22 sensor
  __  _       _      ___   ___  _  _    __
 / / | | __ _| |__  ( _ ) / _ \| || |   \ \
/ /  | |/ _` | '_ \ / _ \| | | | || |_   \ \
\ \  | | (_| | |_) | (_) | |_| |__   _|  / /
 \_\ |_|\__,_|_.__/ \___/ \___/   |_|   /_/

*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

//sensor instancing, pin and type
DHT dht22(10, DHT22);

//dht sensor temoperature and humidity
float temp, humidity;


//LCD screen
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE);

void setup()
{
	Serial.begin(9600);
	//LCD setup
	lcd.begin(16, 2);
	lcd.setBacklight(HIGH);
	//sensors
	dht22.begin();
}

void loop()
{
	temp = dht22.readTemperature();
	humidity = dht22.readHumidity();
	lcd.setCursor(0, 0);

	Serial.print("T: ");
	Serial.print(temp);
	Serial.print(" H: ");
	Serial.print(humidity);

	lcd.print("T: ");
	lcd.print(temp);
	lcd.print(" H: ");
	lcd.println(humidity);


	delay(1000);
}
