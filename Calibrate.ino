void calibrate () {
  Serial.println (" *** Calibrating");
  Serial.println ("          Powering drive 1");

  int ref = analogRead(PIN_ANALOG_IN);
  int counter = 2000;
  int a;
  
  digitalWrite(13, HIGH);
  digitalWrite(2, LOW);
  while (counter > 0) {
    counter++;
    a = analogRead(PIN_ANALOG_IN);
    Serial.print(a);
    Serial.print(" A  --  REF: ");
    Serial.println(ref);
    if (a > ref) {
      break;
    }
    delay (10);
  }
  digitalWrite(13, LOW);
  digitalWrite(2, HIGH);
  Serial.println (" [OK]");
}
