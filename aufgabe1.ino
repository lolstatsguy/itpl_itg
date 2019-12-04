

bool lightA = false;
bool lightB = false;

void setup() {
    pinMode( 4 , OUTPUT);
    pinMode( 3, OUTPUT);
    pinMode(2, OUTPUT);
    pinMode(8, INPUT);
    pinMode(7, INPUT);
    pinMode(6, INPUT);
}
void loop() {
  lightA = digitalRead(8); // 
  lightB = digitalRead(7);
  if (lightA) {
    digitalWrite(4, HIGH);
  }
  else {
    digitalWrite(4, LOW);
  }
  if (lightB) {
    digitalWrite(3, HIGH);
  }
  else {
    digitalWrite(3, LOW);
  }
}
