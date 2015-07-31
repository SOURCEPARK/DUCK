void calibrate (String s) {
  Serial.println (" *** Calibrating");
  Serial.println ("          Powering drive 1");

  int ref = analogRead(PIN_ANALOG_IN);
  int counter = 2500;
  int a;
  
  digitalWrite(13, HIGH);
  digitalWrite(getTube(s), LOW);
  while (counter > 0) {
    counter--;
    a = analogRead(PIN_ANALOG_IN);
    Serial.print("    RD: ");
    Serial.print(a);
    Serial.print(" --  REF: ");
    Serial.print(ref);
    Serial.print("  Delta:");
    Serial.println(abs(ref-a));
    
    if (abs(ref-a) >= 10) {
      break;
    }
    delay (1);
  }
  
  Serial.print("    RD: ");
  Serial.print(a);
  Serial.print(" --  REF: ");
  Serial.print(ref);
  Serial.print(" --  C: ");
  Serial.print(counter);
  Serial.print("  Delta:");
  Serial.println(abs(ref-a));
  digitalWrite(13, LOW);
  digitalWrite(getTube(s), HIGH);
  Serial.println (" [OK]");
}


