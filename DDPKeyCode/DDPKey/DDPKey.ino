//#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
//const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
//LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int inputPin = A0;
double sensorValue;

void setup() {
  // set up the LCD's number of columns and rows:
  pinMode(13, OUTPUT);
  pinMode(8, INPUT_PULLUP);
  
  Serial.begin(9600);
  //lcd.begin(16, 2);
  // Print a message to the LCD.
  
}

void loop() {
  sensorValue = analogRead(inputPin);
  Serial.println(sensorValue);
  delay(100);
  Serial.println(digitalRead(8));
  if(digitalRead(8)==LOW&&sensorValue<400){
    digitalWrite(13,HIGH);
    delay(6000);
    digitalWrite(13,LOW);
   // Serial.println(digitalRead(8));
  }else{
    digitalWrite(13,LOW);
  }
    
}

