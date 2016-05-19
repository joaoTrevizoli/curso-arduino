//sinalizador_morse.ino

/*
  __  _       _      ___   ___  _  _    __
 / / | | __ _| |__  ( _ ) / _ \| || |   \ \
/ /  | |/ _` | '_ \ / _ \| | | | || |_   \ \
\ \  | | (_| | |_) | (_) | |_| |__   _|  / /
 \_\ |_|\__,_|_.__/ \___/ \___/   |_|   /_/
*/

const int ledPin = 13;

int delayTime = 100; //delay padrão
int dotDelay = 150; // periodo do ponto
int dashDelay = 400; // periodo do traco

void setup()
{
	pinMode(ledPin, OUTPUT);
}

void loop()
 {
 	for(int i=0; i<3; i++)
 	{
 		digitalWrite(ledPin, HIGH);
 		delay(dotDelay);
 		digitalWrite(ledPin, LOW);
 		delay(delayTime);
 	}
 
 	delay(delayTime);

 	for(int i=0; i<3; i++)
 	{
	 	digitalWrite(ledPin, HIGH);
	 	delay(dashDelay);
	 	digitalWrite(ledPin, LOW);
	 	delay(delayTime);   
 	}
 } 