/* lm35dz_sensor.ino
  __  _       _      ___   ___  _  _    __
 / / | | __ _| |__  ( _ ) / _ \| || |   \ \
/ /  | |/ _` | '_ \ / _ \| | | | || |_   \ \
\ \  | | (_| | |_) | (_) | |_| |__   _|  / /
 \_\ |_|\__,_|_.__/ \___/ \___/   |_|   /_/

*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int lm35dzPin = A2;

float lm35dzTemp;

//LCD screen
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE);

void setup()
{
	Wire.begin();
	Serial.begin(9600);
	lcd.begin(16, 2);

}

void loop()
{
	lm35dzTemp = lm35dzTempReading(lm35dzPin); 

	lcd.setCursor(0, 0);
	lcd.print(lm35dzTemp);

	Serial.println(lm35dzTemp);

	delay(2000);

	lcd.clear();
}

float lm35dzTempReading(int lm35dzSensorPin)
{
	/* 
	O arduino fornece 5v em seu pino de potencia e possui uma resolucao de 10bits, 
	ou seja 1024 pontos, para saber o valor da temperatura devemos calcular o intervalo
	de voltagem que o arduino e capaz de ler e converter cada 10 milivolts para 1 C
	*/

	float temperature = (static_cast<float>(analogRead(lm35dzSensorPin))*5/(1023))/0.01;
	return temperature;
}