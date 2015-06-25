String waitForCommand() {
  if (Serial.available() > 0) {
    char cmd[4];
    cmd[0] = Serial.read();
    cmd[1] = Serial.read();
    cmd[2] = Serial.read();
    cmd[3] = '\0';
    return cmd;
  }
  return "A";
}





