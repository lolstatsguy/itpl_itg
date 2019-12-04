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
void loop(){
    if (lightGate1 != digitalRead(8) && !lightGate1){
        lightA = !lightA;
    } 
    if (lightGate2 != digitalRead(7) && !lightGate2) {
        lightB = !lightB;
    }
    if (lightGate3 != digitalRead(6) && !lightGate3) {
        lightC = !lightC;
    }
    lightGate1 = digitalRead(8);
    lightGate2 = digitalRead(7);
    lightGate3 = digitalRead(6);
    
    setLights();
}
void setLights(){
    if (lightA) {
        digitalWrite(2,HIGH);
    }
    else {
        digitalWrite(2, LOW);

    }
    if (lightB) {
        digitalWrite(3,HIGH);
    }
    else {
        digitalWrite(3, LOW);
    }
    
    if (lightC) {
        digitalWrite(4,HIGH);
    }
    else {
        digitalWrite(4, LOW);
    }    
    
}