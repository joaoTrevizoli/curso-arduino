/*rtc.ino
  __  _       _      ___   ___  _  _    __
 / / | | __ _| |__  ( _ ) / _ \| || |   \ \
/ /  | |/ _` | '_ \ / _ \| | | | || |_   \ \
\ \  | | (_| | |_) | (_) | |_| |__   _|  / /
 \_\ |_|\__,_|_.__/ \___/ \___/   |_|   /_/

*/

#include <Wire.h>
#include <RTClib.h>
#include <LiquidCrystal_I2C.h>

void printTimeOnScreen();
String dateTimeNow();
String formatDateTime(int n);

LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE);
RTC_DS1307 rtc;

void setup()
{
  Wire.begin();
  lcd.begin(16, 4);
  rtc.begin();
  lcd.setBacklight(HIGH);
  Serial.begin(9600);
  if(!rtc.isrunning())
  {
    Serial.println("rtc not found");
    // rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
}

void loop()
{
  Serial.println(dateTimeNow());
  printTimeOnScreen();
  delay(1000);
}

String formatDateTime(int n)
{
  String digits = String(n);
  if (digits.length()==1)
  {
    digits = "0" + digits;
  }
  return digits;
}

String dateTimeNow()
{
  DateTime timeStamp = rtc.now();
  String fDateTime = formatDateTime(timeStamp.day()) + "/";
  fDateTime = fDateTime + formatDateTime(timeStamp.month()) + "/";
  fDateTime = fDateTime + timeStamp.year() + " ";
  fDateTime = fDateTime + formatDateTime(timeStamp.hour()) + ":";
  fDateTime = fDateTime + formatDateTime(timeStamp.minute()) + ":";
  fDateTime = fDateTime + formatDateTime(timeStamp.second());
  return fDateTime;
}
void printTimeOnScreen()
{
  DateTime timeStamp = rtc.now();
  lcd.setCursor(0, 0);
  lcd.print(formatDateTime(timeStamp.hour()));
  lcd.print(":");
  lcd.print(formatDateTime(timeStamp.minute()));
  lcd.print(":");
  lcd.print(formatDateTime(timeStamp.second()));
}
