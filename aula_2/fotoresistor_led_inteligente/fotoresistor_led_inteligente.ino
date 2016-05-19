//photoresistor_analog_read.ino

/*
  __  _       _      ___   ___  _  _    __
 / / | | __ _| |__  ( _ ) / _ \| || |   \ \
/ /  | |/ _` | '_ \ / _ \| | | | || |_   \ \
\ \  | | (_| | |_) | (_) | |_| |__   _|  / /
 \_\ |_|\__,_|_.__/ \___/ \___/   |_|   /_/
*/

const int ldrPin = A0;
const int ledPin = 2;

int ldrRead;

int readLDR(int pin);

void setup()
{
	Serial.begin(9600);
	pinMode(ldrPin, INPUT);
	pinMode(ledPin, OUTPUT);
}

void loop()
{
    ldrRead = readLDR(ldrPin);
    analogWrite(ledPin, ldrRead);
    Serial.println(ldrRead);
    delay(100);
}

int readLDR(int pin)
{
	int analogueWriteVal = analogRead(pin);
	analogueWriteVal = map(analogueWriteVal, 65, 1000, 0, 255);
	if (analogueWriteVal < 0)
		analogueWriteVal = 0;

	return analogueWriteVal;
}
