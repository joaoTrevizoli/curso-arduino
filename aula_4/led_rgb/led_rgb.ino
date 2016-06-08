//led_rgb.ino

/*
  __  _       _      ___   ___  _  _    __
 / / | | __ _| |__  ( _ ) / _ \| || |   \ \
/ /  | |/ _` | '_ \ / _ \| | | | || |_   \ \
\ \  | | (_| | |_) | (_) | |_| |__   _|  / /
 \_\ |_|\__,_|_.__/ \___/ \___/   |_|   /_/
*/


#define RED_PIN 9
#define GREEN_PIN 10
#define BLUE_PIN 11

void spectroRGB();
void pulsaCor(int pin, bool acendeApaga);

void setup()
{
	pinMode(RED_PIN, OUTPUT);
	pinMode(BLUE_PIN, OUTPUT);
	pinMode(GREEN_PIN, OUTPUT);
	
	analogWrite(RED_PIN, 255);
	analogWrite(GREEN_PIN, 255);
	analogWrite(BLUE_PIN, 255);
}

void loop()
{
	spectroRGB();
	analogWrite(RED_PIN, 255);
	analogWrite(GREEN_PIN, 255);
	analogWrite(BLUE_PIN, 255);
	delay(5);
}

void spectroRGB()
{
	pulsaCor(RED_PIN, 0);
	pulsaCor(BLUE_PIN, 0);
	pulsaCor(RED_PIN, 1);
	pulsaCor(GREEN_PIN, 0);
	pulsaCor(BLUE_PIN, 1);
	pulsaCor(GREEN_PIN, 1);
}

void pulsaCor(int pin, bool acendeApaga)
{

	
	
	if(acendeApaga)
	{
		for(int i=0; i<255; i++)
		{
			analogWrite(pin, i);
			delay(5);

		}
	}
	else
	{
		for(int i=255; i==0; i--)
		{
			analogWrite(pin, i);
			delay(5);
	
		}
	}
	
}