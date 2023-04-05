// C++ code
//
/*
  Verify Temperature
*/

#include <Adafruit_LiquidCrystal.h>

int initialTemperature = 0;

int celsius = 0;

Adafruit_LiquidCrystal lcd_1(0);

void setup()
{
  lcd_1.begin(16, 2);
  pinMode(A0, INPUT);
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);

  lcd_1.print("Welcome!");
}

void loop()
{
  // Set Initial Temperature
  initialTemperature = 20;
  // Measure Temperature in Celsius
  celsius = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125);
  Serial.print(celsius);
  Serial.print("C");
  // Temperature below 20 C
  if (celsius < initialTemperature) {
    // Toate ledurile pe off
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    lcd_1.setCursor(0, 0);
    lcd_1.clear();
    lcd_1.print("Below 20 C");
    delay(1000); // Wait for 1000 millisecond(s)
  }
  // Temperature between 20-25 C
  if (celsius >= initialTemperature && celsius < initialTemperature + 10) {
    // Green LED on
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    lcd_1.setCursor(0, 0);
    lcd_1.clear();
    lcd_1.print("Cool");
    delay(1000); // Wait for 1000 millisecond(s)
  }
  // Temperature between 25-30 C
  if (celsius >= initialTemperature + 10 && celsius < initialTemperature + 20) {
    // Green, Yellow LEDs on
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    lcd_1.setCursor(0, 0);
    lcd_1.clear();
    lcd_1.print("Warm");
    delay(1000); // Wait for 1000 millisecond(s)
  }
  // Temperature between 30-35 C
  if (celsius >= initialTemperature + 20 && celsius < initialTemperature + 30) {
    // Green, Yellow, Orange LEDs on
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    lcd_1.setCursor(0, 0);
    lcd_1.clear();
    lcd_1.print("Hot");
    delay(1000); // Wait for 1000 millisecond(s)
  }
  // Temperature between 35-40
  if (celsius >= initialTemperature + 30 && celsius < initialTemperature + 40) {
    // Green, Yellow, Orange, Red LEDs on
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    lcd_1.setCursor(0, 0);
    lcd_1.clear();
    lcd_1.print("Very hot!");
    delay(1000); // Wait for 1000 millisecond(s)
  }
  // Temperature above 40 C
  if (celsius >= initialTemperature + 40) {
    // Green, Yellow, Orange, Red LEDs on
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    lcd_1.setCursor(0, 0);
    lcd_1.clear();
    lcd_1.print("Stay inside :|");
    delay(1000); // Wait for 1000 millisecond(s)
  }
}