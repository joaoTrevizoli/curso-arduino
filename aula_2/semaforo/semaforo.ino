//semaforo.ino

/*
  __  _       _      ___   ___  _  _    __
 / / | | __ _| |__  ( _ ) / _ \| || |   \ \
/ /  | |/ _` | '_ \ / _ \| | | | || |_   \ \
\ \  | | (_| | |_) | (_) | |_| |__   _|  / /
 \_\ |_|\__,_|_.__/ \___/ \___/   |_|   /_/
*/

const int redPin = 13;
const int yellowPin = 12;
const int greenPin = 11;

int yellowDelay = 2000;
int redGreenDelay = 5000;

void setup()
{
	pinMode(redPin, OUTPUT);
	pinMode(yellowPin, OUTPUT);
	pinMode(greenPin, OUTPUT);
}

void loop()
{
	digitalWrite(redPin, HIGH);
	delay(redGreenDelay);

	digitalWrite(yellowPin, HIGH);
	delay(yellowDelay);

	digitalWrite(greenPin, HIGH);
	digitalWrite(redPin, LOW);
	digitalWrite(yellowPin, LOW);
	delay(redGreenDelay);

	digitalWrite(yellowPin, HIGH);
	digitalWrite(greenPin, LOW);
	delay(yellowDelay);

	digitalWrite(yellowPin, LOW);
}