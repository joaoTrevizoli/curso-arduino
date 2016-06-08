/* photoresistor_serial_com.ino
  __  _       _      ___   ___  _  _    __
 / / | | __ _| |__  ( _ ) / _ \| || |   \ \
/ /  | |/ _` | '_ \ / _ \| | | | || |_   \ \
\ \  | | (_| | |_) | (_) | |_| |__   _|  / /
 \_\ |_|\__,_|_.__/ \___/ \___/   |_|   /_/
*/

const int SENSOR = A0; // input serial pin

int val = 0; //sensor reading

void setup() {

  Serial.begin(9600); // serial port oppening
}

void loop() {
	val = analogRead(SENSOR);
	Serial.println(val);

	delay(100);
}
