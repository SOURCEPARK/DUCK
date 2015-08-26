void eject (String command) {

  int row = getRow(command);
  int col = getCol(command);
  int analog_pin = analogs[row];
  
  digitalWrite(13, HIGH);
  digitalWrite(rows[row], LOW);
  digitalWrite(cols[col], LOW);
  //Serial.print ("Zeile: ");
  //Serial.println (cols[col]);

  int ref = analogRead(analog_pin);
  int counter = 500;
  int a;
  int transitions = 2;
  
//  while (counter > 0) {
//    counter--;
//    a = analogRead(analog_pin);
//
//    if (abs(ref - a) >= 18) {
//      transitions --;
//      ref = analogRead(analog_pin);
//
//      if (transitions == 0) {
//        break;
//      }
//    }
//    delay (5);
//  }

  delay(2000);
  digitalWrite(rows[row], HIGH);
  digitalWrite(cols[col], HIGH);
  
  Serial.println("OK");

  digitalWrite(13, LOW);

}

