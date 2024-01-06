int analogPin = A5;
int val = 0;
int Vin = 5;
float Vout = 0;
float R1 = 1000;
float R2 = 0;
float buffer = 0;

void setup()
{
  Serial.begin(9600);
  Serial.println("Arduino Ohmmetter");
  delay(1500);
}

void loop()
{
  val = analogRead(analogPin);
  if (val)
  {
    buffer = val * Vin;
    Vout = (buffer) / 1024.0;
    buffer = (Vin / Vout) - 1;
    R2 = R1 * buffer;
    Serial.println(R2);
    if(R2>1000000){
      Serial.println("Поставете резистор");
    }
    else if(R2>1000){
      R2=R2/1000;
      Serial.print(R2);
      Serial.println("Kohm");
    }
    else{
    Serial.print("R2: ");
    Serial.println(R2); 
    }
        delay(1000);
  }
}
