/* higrometro.ino
  __  _       _      ___   ___  _  _    __
 / / | | __ _| |__  ( _ ) / _ \| || |   \ \
/ /  | |/ _` | '_ \ / _ \| | | | || |_   \ \
\ \  | | (_| | |_) | (_) | |_| |__   _|  / /
 \_\ |_|\__,_|_.__/ \___/ \___/   |_|   /_/
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

float hygrometer(int hygrometerPin);

const int analogSoilMoisturePin = A1;
const int pinoVerm = 13;
const int pinoVerd = 12;

//LCD screen
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE);


float soilMoisture;


void setup()
{
	Serial.begin(9600);
	//LCD setup
	lcd.begin(16, 2);
	lcd.setBacklight(HIGH);
  
  //Pinos  
  pinMode(pinoVerm, OUTPUT);
  pinMode(pinoVerd, OUTPUT);
}

void loop()
{
  soilMoisture = hygrometer(analogSoilMoisturePin);
  
  // Escrita na tela LCD
  lcd.setCursor(0, 0);
  lcd.print("Umidade em:");
  lcd.setCursor(0, 1);
  lcd.print(soilMoisture);
  lcd.print(" %");

  //Escrita no monitor serial
  Serial.print("Umidade em:")
  Serial.print(soilMoisture);
  Serial.print(" %\n");

  //Led para indicar solo seco ou umido
  if(soilMoisture < 20)
  {
	  digitalWrite(pinoVerm, HIGH);
    digitalWrite(pinoVerd, LOW);
  }
  else
  {
    digitalWrite(pinoVerm, LOW);
    digitalWrite(pinoVerd, HIGH);
  }
  
  delay(500);
  lcd.clear();

}

float hygrometer(int hygrometerPin)
{
  int readSoilMoisture = analogRead(hygrometerPin);
  readSoilMoisture = map(readSoilMoisture, 1023, 0, 0, 20000);
  float moisture = static_cast<float>(readSoilMoisture)/100.0;
  return moisture;
}
