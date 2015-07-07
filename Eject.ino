void eject (String command) {
    Serial.print("Ejecting row:"); 
    char tmp[] = {
      '\0','\0','\0'        };
    tmp[0] = command[1];
    int row = atoi(tmp);
    Serial.print(row); 
    Serial.print(" tube:"); 
    int col = atoi(&command[2]);
    Serial.println(col);

    if (row>5 || row<0 || col>7||col<0) {
      Serial.println("RANGEERROR");
    }
    else {
      String line = cmd[row]; 

      tmp[0] = line[col*2];
      tmp[1] = line[col*2+1];
      if (String(tmp).compareTo("NN")!=0) {
        Serial.println(tmp);
        int pin = atoi(tmp);

        Serial.print(" signaling pin: ");
        Serial.println(pin);
        Serial.println(line);
        Serial.println(line[col]);
        digitalWrite(13, HIGH);

        digitalWrite(pin, LOW);
        delay(2000);    
        digitalWrite(pin, HIGH);
        digitalWrite(13, LOW);    
      }
      else {
        Serial.println("INDEXERROR");
      }
    }
}
