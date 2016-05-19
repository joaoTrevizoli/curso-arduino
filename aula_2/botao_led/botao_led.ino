//botao_led.ino

/*
  __  _       _      ___   ___  _  _    __
 / / | | __ _| |__  ( _ ) / _ \| || |   \ \
/ /  | |/ _` | '_ \ / _ \| | | | || |_   \ \
\ \  | | (_| | |_) | (_) | |_| |__   _|  / /
 \_\ |_|\__,_|_.__/ \___/ \___/   |_|   /_/
*/

const int LED = 12;
const int BUTTON = 7;

int val = 0;
int old_val = 0;
int state = 0;

void setup()
{
	pinMode(LED, OUTPUT);
	pinMode(BUTTON, INPUT);
}

void loop()
{
	val = digitalRead(BUTTON);

	if ((val == HIGH) && (old_val == LOW))
	{
		state = 1 - state;
		delay(50);
	}

	old_val = val;

	if (state == 1)
	{
		digitalWrite(LED, HIGH);
	}
	else
	{
		digitalWrite(LED, LOW);
	}
}
