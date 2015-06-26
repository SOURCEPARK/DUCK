String waitForCommand() {
  if (Serial.available() > 0) {
    String cmd;
    cmd = Serial.readStringUntil('.');
    return cmd;
  }
  return "A";
}





