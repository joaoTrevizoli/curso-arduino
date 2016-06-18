//soil_temperature_ds18b20.ino

#include <Wire.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal_I2C.h>

// port for DS18B20 signal pin
const int oneWireBus = 3;

// instantiate oneWire for pin communication
OneWire oneWire(oneWireBus);

//temperatures control
float lastSoilTemp = 999;

// Tell Dallas Temperature Library to use oneWire Library
DallasTemperature sensors(&oneWire);
DeviceAddress sensorSoilTemp;

//LCD screen
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE);



void setup() 
{ 
	//Serial bus
	Serial.begin(9600);
	
	//LCD setup
	lcd.begin(16, 2);
	lcd.setBacklight(HIGH);
	//sensors
	sensors.begin();
	//finding sensors addresses
	Serial.println("Searching for DS18B20 sensors...");
	Serial.print("it was found ");
	Serial.print(sensors.getDeviceCount(), DEC);
	Serial.println(" sensors");
	if (!sensors.getAddress(sensorSoilTemp, 0))
	{
		Serial.println("Any sensors was found");
	}
	Serial.print("Sensor address: ");
	showSensorAddress(sensorSoilTemp);
	Serial.println();
	Serial.println();
}

void loop() 
{
	unsigned long currentMillis = millis();
	float temperatureC = soilDS18B20Reading(sensorSoilTemp);
	
    //LCD stuff    
    if (temperatureC < lastSoilTemp)
    {
    	lcd.clear();
    }
    lcd.setCursor(0, 0);	
    lcd.print("Temp C: ");
    lcd.print(temperatureC);

    lastSoilTemp = temperatureC;

	Serial.print("Temp C: ");
	Serial.println(temperatureC);

    delay(1000);
}

float soilDS18B20Reading(DeviceAddress sensorAddr)
{
	
	sensors.requestTemperatures();
	float temp = sensors.getTempC(sensorAddr);
	return temp;
}

void showSensorAddress(DeviceAddress deviceAddress)
{
	for (uint8_t i = 0; i < 8; i++)
	{
    	// Add zeros if required
    	if (deviceAddress[i] < 16) 
    	{
    		Serial.print("0");
    	}

    	Serial.print(deviceAddress[i], HEX);
    }
}
