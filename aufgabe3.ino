int startWert = -8;
bool lightA = false;
bool lightB = false;
bool lightC = false;
bool lightGate1 = false;
bool lightGate2 = false;
bool lightGate3 = false;

void setup() {
    pinMode( 4 , OUTPUT);
    pinMode( 3, OUTPUT);
    pinMode(2, OUTPUT);
    pinMode(8, INPUT);
    pinMode(7, INPUT);
    pinMode(6, INPUT);
}
int add(int x) {
    return  x + x;
}
int mul(int x) {
    return x*0.5;
}
int neg(int x) {
    return x * -1;
}
void loop(){
    
    if (lightGate1 != digitalRead(8) && !lightGate1){
         startWert = add(startWert);
    } 
    if (lightGate2 != digitalRead(7) && !lightGate2) {
       startWert = mul(startWert);
    }
    if (lightGate3 != digitalRead(6) && !lightGate3) {
        startWert = neg(startWert);
    }
    lightGate1 = digitalRead(8);
    lightGate2 = digitalRead(7);
    lightGate3 = digitalRead(6);
    
    setLights();
}
void setLights() {
if (startWert < 0) {
    digitalWrite(4, HIGH);
  }
  else {
    digitalWrite(4, LOW);
  }
  if (startWert >= 0) {
    digitalWrite(3, HIGH);
  }
  else {
    digitalWrite(3, LOW);
  }
  if (startWert % 5 == 0) {
    digitalWrite(2, HIGH);
  }
  else {
    digitalWrite(2, LOW);
  }
}