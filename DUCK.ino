String cmd[] = {
  "0203040506NNNNNN",
  "0203040506NNNNNN",
  "0203040506NNNNNN",
  "0203040506NNNNNN",
  "0203040506020304",
  "0203040506020304"
};

int PIN_ANALOG_IN = 5;

void setup() {

  Serial.begin(115200);
  pinMode(13, OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  while (!Serial) {
    delay (10);
  }
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(13, LOW);
  
  pinMode(A5, INPUT_PULLUP);
  
  Serial.print("DUCK Ready\r\n");
}

void loop() {
  String s = waitForCommand();
  if (s[0] != 'A') {
  switch(s[0]) {
    case 'e': eject (s);
              break;
    case 'c': calibrate(s);
              break;
    case 's': oneStep(s);
              break;
    default: Serial.print (" ### Error ### Unknown command received: ");
        Serial.println(s);
  }
  }
  delay(10);
}










