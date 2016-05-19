//farol_interativo.ino

/*
  __  _       _      ___   ___  _  _    __
 / / | | __ _| |__  ( _ ) / _ \| || |   \ \
/ /  | |/ _` | '_ \ / _ \| | | | || |_   \ \
\ \  | | (_| | |_) | (_) | |_| |__   _|  / /
 \_\ |_|\__,_|_.__/ \___/ \___/   |_|   /_/
*/

int carRed = 8;
int carYellow = 9;
int carGreen = 10;
int pedRed = 5;
int pedGreen = 6;
int button = 7;
int crossTime = 5000;
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
	digitalWrite(carGreen, LOW); // apaga verde
	digitalWrite(carYellow, HIGH); // acende amarelo
	delay(2000);

	digitalWrite(carYellow, LOW); // apaga amarelo
	digitalWrite(carRed, HIGH); // acende vermelho
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
