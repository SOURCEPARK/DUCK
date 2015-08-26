
String cmd[] = {
  "3840424446NNNNNNNN",
  "3840424446NNNNNNNN",
  "3840424446NNNNNNNN",
  "3840424446NNNNNNNN",
  "384042444650523436",
  "384042444650523436",
};

int relais[] = { 22,24,26,28,30,32,38,40,42,44,46,48,50,52,34,36 };
int rows [] = { 22,24,26,28,30,32 };
int cols[] = { 38,40,42,44,46,48,50,52,34,36 };
int analogs[] = { A10, A11, A12, A13, A14, A15 };

int PIN_ANALOG_IN = 5;

void setup() {

  Serial.begin(115200);
  pinMode(13, OUTPUT);
  for (int i=0; i<16; i++) {
    pinMode(relais[i],OUTPUT);
    digitalWrite(relais[i], HIGH);
  }
  while (!Serial) {
    delay (10);
  }
  
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










