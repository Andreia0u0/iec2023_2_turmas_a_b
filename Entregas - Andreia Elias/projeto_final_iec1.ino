#include <LiquidCrystal.h>
LiquidCrystal lcd(5,6,8,9,10,11);
  
int redled = 2;
int greenled = 3;
int buzzer = 4;
int sensor = A0;
int gasthreshold = 325;

int switchPin = 7;

int temp_pin = A1;
int temp_input;
double temp;


void setup()
{
pinMode(redled, OUTPUT);
pinMode(greenled,OUTPUT);
pinMode(buzzer,OUTPUT);
pinMode(sensor,INPUT);
pinMode(switchPin, INPUT);
Serial.begin(9600);
lcd.begin(16, 2);
}  


void loop()
{
  float gas; //The amount of gas is normal when it is 90 or less
    gas = analogRead(sensor); 
    Serial.print("Gas:");
    Serial.println(gas);
  Serial.print("Temperature:");
    Serial.print(temp);
    Serial.println("C");
  temp_input = analogRead(A1);
	temp = (double)temp_input / 1024;
	temp = temp * 5;
	temp = temp - 0.5;
	temp = temp * 100;
  int analogValue = analogRead(sensor);
  Serial.print(analogValue);
  if((analogValue >= 100) || (temp > 60) || digitalRead(switchPin))
  {
    digitalWrite(redled,HIGH);
    digitalWrite(greenled,LOW);
    tone(buzzer, 1000, 10000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("PERIGO");
    delay(1000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Gas:");
    lcd.print(gas);
    lcd.setCursor(0, 1);
    lcd.print("Temp:");
    lcd.print(temp);
    delay(1000);
  }
  else 
  {
    digitalWrite(greenled,HIGH);
    digitalWrite(redled,LOW);
    noTone(buzzer);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("SEGURO");
    delay(1000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Gas:");
    lcd.print(gas);
    lcd.setCursor(0, 1);
    lcd.print("Temp:");
    lcd.print(temp);
    delay(1000);
  }
}