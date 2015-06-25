void setup() {
  Serial.begin(115200);
   while (!Serial) {
     delay (10);
  }
  Serial.println("DUCK Ready\n>");
}

void loop() {
  String s = waitForCommand();
  if (s != "A") {
    Serial.print("Ejecting row:"); 
    Serial.print(s[1]); 
    Serial.print(" tube:"); 
    Serial.println(s[2]);
  }
  delay(1000);
}








