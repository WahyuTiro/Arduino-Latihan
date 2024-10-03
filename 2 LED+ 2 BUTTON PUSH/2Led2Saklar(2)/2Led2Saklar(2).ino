const int pinTombol1 = 2;  // pin tombol 1
const int pinTombol2 = 3;  // pin tombol 2
const int pinLED1 = 8;    // pin LED 1
const int pinLED2 = 9;    // pin LED 2

bool statusAkhirTombol1 = LOW;
bool statusAkhirTombol2 = LOW;
bool statusLED1 = LOW;
bool statusLED2 = LOW;

void setup() {
  pinMode(pinLED1, OUTPUT);
  pinMode(pinLED2, OUTPUT);
  pinMode(pinTombol1, INPUT);
  pinMode(pinTombol2, INPUT);
}

void loop() {
  //LED 1
  bool statusTombol1 = digitalRead(pinTombol1);
  if (statusTombol1 != statusAkhirTombol1) {
    statusAkhirTombol1 = statusTombol1;
    if (statusTombol1 == LOW) {
      statusLED1 = (statusLED1 == HIGH) ? LOW: HIGH; // jika LED 1 saat ini dinyalakan (statusLED1 == HIGH), ditetapkan LOW. Jika LED1 dimatikan (statusLED1 != HIGH), ditetapkan HIGH.
      digitalWrite(pinLED1, statusLED1);
    }
  }

  // LED 2
  bool statusTombol2 = digitalRead(pinTombol2);
  if (statusTombol2 != statusAkhirTombol2) {
    statusAkhirTombol2 = statusTombol2;
    if (statusTombol2 == LOW) {
      statusLED2 = (statusLED2 == HIGH) ? LOW: HIGH;
      digitalWrite(pinLED2, statusLED2);
    }
  }
}
