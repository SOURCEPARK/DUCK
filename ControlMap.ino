int getTube(String command) {
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
        int pin = atoi(tmp);
        Serial.print("Pin calculated: ");
        Serial.println(pin);
        return pin;
      }
      else {
        Serial.println("INDEXERROR");
      }
    }
    return -1;
}

