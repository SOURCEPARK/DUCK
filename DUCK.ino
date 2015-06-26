String cmd[] = {
  "0203040506NNNNNN",
  "0203040506NNNNNN",
  "0203040506NNNNNN",
  "0203040506NNNNNN",
  "0203040506020304",
  "0203040506020304"
};

void setup() {

  Serial.begin(115200);
  pinMode(13, OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(7,INPUT);
  while (!Serial) {
    delay (10);
  }
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(13, LOW);   
  Serial.print("DUCK Ready\r\n>");
}

void loop() {
  String s = waitForCommand();
  if (s != "A") {
    Serial.print("Ejecting row:"); 
    char tmp[] = {
      '\0','\0','\0'        };
    tmp[0] = s[1];
    int row = atoi(tmp);
    Serial.print(row); 
    Serial.print(" tube:"); 
    int col = atoi(&s[2]);
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
  delay(10);
}










