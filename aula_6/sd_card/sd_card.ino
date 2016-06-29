/*sd_card.ino
  __  _       _      ___   ___  _  _    __
 / / | | __ _| |__  ( _ ) / _ \| || |   \ \
/ /  | |/ _` | '_ \ / _ \| | | | || |_   \ \
\ \  | | (_| | |_) | (_) | |_| |__   _|  / /
 \_\ |_|\__,_|_.__/ \___/ \___/   |_|   /_/

*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SD.h>
#include <String.h>

void sdStart();
void writeFileHeader(File &f, String logHeader);
void writeToFile(File &f, int logValue)

LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE);

const int waterSensorPin = A0;

const int chipSelectPin = 4;

int sensorReadingVal;
int lastReadingVal;

String message;
File logFile;


void setup()
{


	// LCD setup
	lcd.begin(16, 2);
	lcd.setBacklight(HIGH);

	// humidity sensor setup
	pinMode(waterSensorPin, INPUT);
	Serial.begin(9600);

	//SD card Setup
	pinMode(chipSelectPin, OUTPUT);
	sdStart();
	writeFileHeader(logFile, "Umido\n");
}

void loop()
{
	//message
	sensorReadingVal = waterSensor(waterSensorPin);

	//LCD printing
	lcd.setCursor(0, 0);
	if(lastReadingVal == 0)
	{
		lcd.clear();
	}
	lcd.print(message);
	writeToFile(logFile, sensorReadingVal);
	lastReadingVal = sensorReadingVal;

	//debugging
	// Serial.println(analogRead(waterSensorPin));

	delay(1000);


}

//read water sensor
int waterSensor(int analogueReadPin)
{
	//check if there's water on top of the sensor
	if (analogRead(analogueReadPin) > 50)
	{
		return 1;
	}
	return 0;

}

//SD card Setup
void sdStart()
{
  if (!SD.begin(chipSelectPin))
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("SD card");
    lcd.setCursor(0, 1);
    lcd.print("not found");
    Serial.println("SD card not found!");
    delay(2000);
    sdStart();
    }
}

bool checkFileExists()
{
  if (SD.exists("/logFile.csv"))
  {
    return true;
  }else
  {
    return false;
  }
}

void writeFileHeader(File &f, String logHeader)
{

  if (!checkFileExists())
  {
    f = SD.open("logFile.csv", FILE_WRITE);
    if(f)
    {
      f.print(logHeader);
      Serial.print(logHeader);
      if (!logHeader.endsWith("\n"))
      {
        f.print("\n");
        Serial.println();
      }
    }
    f.close();
  }
}

void writeToFile(File &f, int logValue)
{
	f = SD.open("logFile.txt", FILE_WRITE);
	if(f)
	{
		Serial.println("logging");
		f.println(logMessage);
		f.close();
	}
}
