/* semaforo_pedestre.ino
  __  _       _      ___   ___  _  _    __
 / / | | __ _| |__  ( _ ) / _ \| || |   \ \
/ /  | |/ _` | '_ \ / _ \| | | | || |_   \ \
\ \  | | (_| | |_) | (_) | |_| |__   _|  / /
 \_\ |_|\__,_|_.__/ \___/ \___/   |_|   /_/
*/

void changeLights();

const int carRed = 8;
const int carYellow = 9;
const int carGreen = 10;
const int pedRed = 5;
const int pedGreen = 6;
const int button = 7;
const int crossTime = 5000;

unsigned long changeTime;

void setup()
{
	pinMode(carRed, OUTPUT);
	pinMode(carYellow, OUTPUT);
	pinMode(carGreen, OUTPUT);
	pinMode(pedRed, OUTPUT);
	pinMode(pedGreen, OUTPUT);
	pinMode(button, INPUT);
	digitalWrite(carGreen, HIGH);
	digitalWrite(pedRed, HIGH);
}

void loop()
{
	int state = digitalRead(button);
	if (state == HIGH && (millis() - changeTime) > 5000)
	{
		changeLights();
	}
}

void changeLights()
{
	digitalWrite(carGreen, LOW);
	digitalWrite(carYellow, HIGH);
	delay(2000);

	digitalWrite(carYellow, LOW);
	digitalWrite(carRed, HIGH);
	delay(1000);

	digitalWrite(pedRed, LOW);
	digitalWrite(pedGreen, HIGH);
	delay(crossTime);

	for(int i=0; i<10; i++){
	    digitalWrite(pedGreen, HIGH);
	    delay(250);
	    digitalWrite(pedGreen, LOW);
	    delay(250);
	}

	digitalWrite(pedRed, HIGH);
	delay(500);

	digitalWrite(carYellow, HIGH);
	digitalWrite(carRed, LOW);
	delay(1000);
	digitalWrite(carGreen, HIGH);
	digitalWrite(carYellow, LOW);

	changeTime = millis();
}
