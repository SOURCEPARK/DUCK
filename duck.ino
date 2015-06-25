int stop = 0;
volatile int j=5;
int oldj=9;
long noprell;

void setup() {
  pinMode(5, OUTPUT);
  pinMode(7, INPUT);
  pinMode(13, OUTPUT);
  //attachInterrupt(2, blink, CHANGE);
  stop = 0;
  Serial.begin(115200);
  Serial.println("Wating for Stop");
  Serial.println(stop);
  digitalWrite(5, LOW);
  digitalWrite(13, HIGH);
}

void loop() {
 
    j = digitalRead(7);
    //Serial.println(j);
    if (j!=oldj && j==HIGH) {
      Serial.println("CHANGE");
      digitalWrite(5, HIGH);
      digitalWrite(13, LOW);
      
    }
    oldj=j;
}

void blink()
{

  stop=1;
}






