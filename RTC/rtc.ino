#include <Wire.h>
#include <RTClib.h>

RTC_DS3231 rtc;  // Use DS3231 (works for DS1307 too)

void setup() {
  Serial.begin(9600);
  Wire.begin();

  // Initialize RTC
  if (!rtc.begin()) {
    Serial.println("Couldn't find RTC!");
    while (1);
  }

  // If RTC lost power or time is not set, uncomment this line once:
  // rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));

  Serial.println("RTC is running...");
  delay(2000);
}

void loop() {
  DateTime now = rtc.now();

  Serial.print("Date: ");
  Serial.print(now.year(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.day(), DEC);

  Serial.print("  Time: ");
  if (now.hour() < 10) Serial.print('0');
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  if (now.minute() < 10) Serial.print('0');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  if (now.second() < 10) Serial.print('0');
  Serial.print(now.second(), DEC);

  Serial.println();
  delay(1000);
}
