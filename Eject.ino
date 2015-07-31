void eject (String command) {

  digitalWrite(13, HIGH);
  digitalWrite(getTube(command), LOW);

  int ref = analogRead(PIN_ANALOG_IN);
  int counter = 500;
  int a;
  int transitions = 2;

  while (counter > 0) {
    counter--;
    a = analogRead(PIN_ANALOG_IN);
//    Serial.print("    RD: ");
//    Serial.print(a);
//    Serial.print(" --  REF: ");
//    Serial.print(ref);
//    Serial.print("  Delta:");
//    Serial.println(abs(ref - a));

    if (abs(ref - a) >= 18) {
      transitions --;
      ref = analogRead(PIN_ANALOG_IN);
//      Serial.println("Transition !!");
      if (transitions == 0) {
        break;
      }
    }
    delay (5);
  }
  Serial.println("OK");

//  Serial.print("    RD: ");
//  Serial.print(a);
//  Serial.print(" --  REF: ");
//  Serial.print(ref);
//  Serial.print(" --  C: ");
//  Serial.print(counter);
//  Serial.print("  Delta:");
//  Serial.println(abs(ref - a));
//  digitalWrite(13, LOW);
//  digitalWrite(2, HIGH);
//  Serial.println (" [OK]");



  digitalWrite(getTube(command), HIGH);
  digitalWrite(13, LOW);

}

