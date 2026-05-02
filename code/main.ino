#define LDR 34
#define PIR 4
#define LED 5

int ldrValue;
int motion;

void setup()
{
  pinMode(PIR, INPUT);
  pinMode(LED, OUTPUT);

  Serial.begin(115200);
}

void loop()
{
  ldrValue = analogRead(LDR);   // Read LDR
  motion = digitalRead(PIR);    // Read PIR

  Serial.print("LDR Value: ");
  Serial.println(ldrValue);

  if(motion == HIGH)   // Motion detected
  {
      if(ldrValue > 1500)   // Dark environment
      {
          digitalWrite(LED, HIGH); // LED ON
      }
      else
      {
          digitalWrite(LED, LOW);  // Bright environment → LED OFF
      }
  }
  else
  {
      digitalWrite(LED, LOW); // No motion → LED OFF
  }

  delay(200);
}
