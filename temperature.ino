void setup() {
  Serial.begin(9600);
  analogReference(EXTERNAL);
}

void loop () {
  analogRead(0);
  delay(100); // wait until line settles
  int reading = analogRead(0);
  delay(20);
  reading = reading + analogRead(0);
  delay(20);
  reading = reading + analogRead(0);
  
  analogRead(1);
  delay(100);
  int light = analogRead(1);
  delay(20);
  light = light + analogRead(1);
  delay(20);
  light = light + analogRead(1);
  light = light / 3;
  
  analogRead(2);
  delay(100);
  reading = reading + analogRead(2);
  delay(20);
  reading = reading + analogRead(2);
  delay(20);
  reading = reading + analogRead(2);
  
  float voltage = ((reading * 3.3) /6.0 ) / 1024.0;
  float temperature = (voltage-0.5) * 100;
  Serial.print("Temp: ");
  Serial.println(temperature);
  Serial.print("Light: ");
  Serial.println(light);
  delay(700);
}
