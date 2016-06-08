/* sensor_de_molhamento.ino
  __  _       _      ___   ___  _  _    __
 / / | | __ _| |__  ( _ ) / _ \| || |   \ \
/ /  | |/ _` | '_ \ / _ \| | | | || |_   \ \
\ \  | | (_| | |_) | (_) | |_| |__   _|  / /
 \_\ |_|\__,_|_.__/ \___/ \___/   |_|   /_/
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

int waterSensor(int analogueReadPin);

LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE);

const int waterSensorPin = A0;

int sensorReadingVal;

String message;

void setup()
{
	// LCD setup
	lcd.begin(16, 2);
	lcd.setBacklight(HIGH);
	// humidity sensor setup
	pinMode(waterSensorPin, INPUT);
	Serial.begin(9600);

}

void loop()
{
	//message
	message = "wet: ";
	sensorReadingVal = waterSensor(waterSensorPin);
	message += sensorReadingVal;
	
	//LCD printing
	lcd.setCursor(0, 0);
	lcd.print(message);

	// serial monitor
	Serial.println(message);
	
	delay(1000);
	
}

int waterSensor(int analogueReadPin)
{
	//check if there's water on top of the sensor
	if (analogRead(analogueReadPin) > 50)
	{
		return 1;
	} 
	return 0;
}