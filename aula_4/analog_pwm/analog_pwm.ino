/* analog_pwm.ino
  __  _       _      ___   ___  _  _    __
 / / | | __ _| |__  ( _ ) / _ \| || |   \ \
/ /  | |/ _` | '_ \ / _ \| | | | || |_   \ \
\ \  | | (_| | |_) | (_) | |_| |__   _|  / /
 \_\ |_|\__,_|_.__/ \___/ \___/   |_|   /_/

*/

const int led = 9;

void setup() {
  pinMode(led, OUTPUT); 
}

void loop() {

  for(int i=0; i<255; i++){
      analogWrite(led, i);
      delay(10);

  }
  for(int i=255; i>0; i--){
      analogWrite(led, i);
      delay(10);
  }
}
