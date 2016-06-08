/* analog_change_led_intensity.ino
  __  _       _      ___   ___  _  _    __
 / / | | __ _| |__  ( _ ) / _ \| || |   \ \
/ /  | |/ _` | '_ \ / _ \| | | | || |_   \ \
\ \  | | (_| | |_) | (_) | |_| |__   _|  / /
 \_\ |_|\__,_|_.__/ \___/ \___/   |_|   /_/

*/

const int LED = 13;

int val = 0;

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {

    val = analogRead(0);
	analogWrite(LED, val/4);
	delay(10);
}
