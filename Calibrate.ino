void calibrate (String s) {
  
  Serial.println (" *** Calibrating");
  Serial.println ("          Powering drive 1");
 
  int counter = 2500;
  int a;

  int row = getRow(s);
  int col = getCol(s);
  int analog_pin = analogs[row]; 
  int ref = analogRead(analog_pin);
  
  digitalWrite(13, HIGH);
  digitalWrite(row, LOW);
  digitalWrite(col, LOW);
  
  while (counter > 0) {
    counter--;
    a = analogRead(analog_pin);
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
  digitalWrite(row, HIGH);
  digitalWrite(col, HIGH);
  Serial.println (" [OK]");
}


