struct lager {
    int capa = 20;
    int belegung;
    int speicherArray[20];
    //lager() {
    //  speicherArray = new int[10];
    //}
} wareneingang, sperrlager, hauptlager, warenausgang;

bool lightA = false;
bool lightB = false;
bool lightC = false;
bool lightGate1 = false;
bool lightGate2 = false;
bool lightGate3 = false;
int prodNr;
//Legt fest, ob eine Ware ein oder ausgelagert wird

bool einlagern = true;



void setup() {
    wareneingang.belegung = 0;
    sperrlager.belegung = 0;
    hauptlager.belegung = 0;
    warenausgang.belegung = 0;
    pinMode( 4 , OUTPUT);
    pinMode( 3, OUTPUT);
    pinMode(2, OUTPUT);
    pinMode(8, INPUT);
    pinMode(7, INPUT);
    pinMode(6, INPUT);
    Serial.begin(9600);
}
void loop(){
if (einlagern) {
    //Erste Lichtschranke vom Rand aus gesehen
    if (lightGate3 != digitalRead(6) && !lightGate3) {
            if(wareneingang.capa > wareneingang.belegung) {
                prodNr = rand();
                wareneingang.speicherArray[wareneingang.belegung] = prodNr;
                wareneingang.belegung++;
                Serial.print("Ware mit Produktnummer");
                Serial.print(prodNr);
                Serial.println("wurde im Wareneingang verbucht");
            }
        }
    if (lightGate2 != digitalRead(7) && !lightGate2) {
            if(wareneingang.belegung > 0 && hauptlager.belegung <= hauptlager.capa) {
            hauptlager.speicherArray[hauptlager.belegung] = wareneingang.speicherArray[wareneingang.belegung-1];
            
            wareneingang.speicherArray[wareneingang.belegung-1] = 0;
            wareneingang.belegung--;
            hauptlager.belegung++;
            Serial.print("Ware mit Produktnummer");
            Serial.print(hauptlager.speicherArray[hauptlager.belegung-1]);
            Serial.println("wurde im Hauptlager verbucht");
            }
    }
    if (lightGate2 != digitalRead(8) && !lightGate2) {
            if(wareneingang.belegung > 0 && sperrlager.belegung <= sperrlager.capa) {
            sperrlager.speicherArray[sperrlager.belegung] = wareneingang.speicherArray[wareneingang.belegung-1];
            wareneingang.speicherArray[wareneingang.belegung-1] = 0;
            wareneingang.belegung--;
            sperrlager.belegung++;
            Serial.print("Ware mit Produktnummer");
            Serial.print(sperrlager.speicherArray[sperrlager.belegung-1]);
            Serial.println("wurde im Sperrlager verbucht");
            }
}
}
else {
    //Erste vom Rand temporär keine auf
    if (lightGate3 != digitalRead(6) && !lightGate3) {
        
    }
    if (lightGate2 != digitalRead(7) && !lightGate2) {
       Serial.print("Ware mit Produktnummer");
        Serial.print(warenausgang.speicherArray[0]);
        Serial.println("wurde vom LKW abgeholt");
       for(int x = 0; x <= warenausgang.belegung-1;x++){
            if(x == warenausgang.capa -1) {
                warenausgang.speicherArray[x] = 0;
                break;
            }
            warenausgang.speicherArray[x] = warenausgang.speicherArray[x+1]; 
            warenausgang.belegung--;
            }
        }

    }
    if (lightGate2 != digitalRead(8) && !lightGate1) {
    if(hauptlager.belegung>0) {
        int tempNr = hauptlager.speicherArray[0];
        for(int x = 0; x <= hauptlager.belegung-1; x++){
            if(x == hauptlager.capa -1) {
                hauptlager.speicherArray[x] = 0;
                break;
            }
            hauptlager.speicherArray[x] = hauptlager.speicherArray[x+1]; 
            }
        hauptlager.belegung--;
        warenausgang.speicherArray[warenausgang.belegung] = tempNr;
        Serial.print("Ware mit Produktnummer");
        Serial.print(tempNr);
        Serial.println("wurde im warenausgang verbucht");
        warenausgang.belegung++;
        }
    }
}
 

lightGate1 = digitalRead(8);
lightGate2 = digitalRead(7);
lightGate3 = digitalRead(6);
}
void setLights() {
    if (wareneingang.belegung == 0) {
         digitalWrite(3, HIGH);
    }
    else {
         digitalWrite(3, HIGH);
    }
    if (wareneingang.belegung > 0 && wareneingang.belegung<wareneingang.capa) {
         digitalWrite(2, HIGH);
    }
    else {
        digitalWrite(2, HIGH);
    }
    if (wareneingang.belegung == wareneingang.capa) {
    digitalWrite(4, HIGH);
    } else {
    digitalWrite(4, LOW);
    }

}



