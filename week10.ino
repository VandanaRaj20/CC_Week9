// Week 9: Multi Input and Multi Output
const int ldrPin1 = A0;
const int ldrPin2 = A1;
const int potPin = A2;
const int ledPin1 = 9;
const int ledPin2 = 10;

void setup() {
  Serial.begin(9600); 
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}

void loop() {
  int ldrValue1 = analogRead(ldrPin1);
  int ldrValue2 = analogRead(ldrPin2);
  int potValue = analogRead(potPin);

  // Since potentiometer accepts values between 0 and 255, we map the LED brightness from 0 to 255
  // I am mapping analog values to the LED brightness range (0-255)
  int brightness1 = map(ldrValue1, 0, 1023, 0, 255);
  int brightness2 = map(ldrValue2, 0, 1023, 0, 255);

  // Here, I use potentiometer value to control LED brightness
  analogWrite(ledPin1, brightness1);
  analogWrite(ledPin2, brightness2);

  // We print the values here to get insights from LED 1 and LED 2 as well as potentiometer values
  Serial.print("LDR 1 Value: ");
  Serial.print(ldrValue1);
  Serial.print("\tLDR 2 Value: ");
  Serial.print(ldrValue2);
  Serial.print("\tPotentiometer Value: ");
  Serial.println(potValue);

  delay(500); // Delay for readability
}

