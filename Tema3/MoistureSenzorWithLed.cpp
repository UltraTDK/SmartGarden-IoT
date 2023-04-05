// C++ code
#include <Adafruit_LiquidCrystal.h>
int moistureValue;
float moisture_percentage;


Adafruit_LiquidCrystal lcd_1(0);

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  lcd_1.begin(16, 2);
  Serial.begin(9600);
}

void loop()
{
  moistureValue = analogRead(A0);
  moisture_percentage = ((moistureValue/539.00)*100);
  Serial.print("\nMoisture Value : ");
  Serial.print(moisture_percentage);
  Serial.print("%");
  lcd_1.clear();
  if (moisture_percentage < 10.00) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    lcd_1.print("Dry Soil");
    delay(1000); // Wait for 1000 millisecond(s)
  }
  if (moisture_percentage > 10.00 && moisture_percentage < 30.00) {
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    lcd_1.print("Wet Soil");
    delay(1000); // Wait for 1000 millisecond(s)
  }
  if (moisture_percentage > 30.00 && moisture_percentage < 60.00)
  {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    lcd_1.print("Almost Mud");
    delay(1000); // Wait for 1000 millisecond(s)
  }
  if (moisture_percentage > 60.00) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    lcd_1.print("Muddy");
    delay(1000); // Wait for 1000 millisecond(s)
  }
    
}