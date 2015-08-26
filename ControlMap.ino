int getRow(String command) {
    char tmp[] = {
      '\0','\0','\0'        };
    tmp[0] = command[1];
    int row = atoi(tmp);
//    Serial.print(row); 
//    Serial.print(" tube:"); 
    int col = atoi(&command[2]);
//    Serial.println(col);
    return row;
}

int getCol (String command) {
    char tmp[] = {
      '\0','\0','\0'        };
    tmp[0] = command[1];
    int row = atoi(tmp);
//    Serial.print(row); 
//    Serial.print(" tube:"); 
    int col = atoi(&command[2]);
//    Serial.println(col);
    return col;
}

