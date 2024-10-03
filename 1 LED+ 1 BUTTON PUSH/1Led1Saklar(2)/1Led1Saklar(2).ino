const int pinTombol = 2;  // pin tombol
const int pinLED = 8;    // pin LED

bool statusAkhirTombol = LOW;
bool statusLED = LOW;

void setup() {
  pinMode(pinLED, OUTPUT);
  pinMode(pinTombol, INPUT);
}

void loop() {
  bool statusTombol = digitalRead(pinTombol);
  if (statusTombol != statusAkhirTombol) {
    statusAkhirTombol = statusTombol;
    if (statusTombol == LOW) {
      statusLED = (statusLED == HIGH) ? LOW: HIGH;
      digitalWrite(pinLED, statusLED);
    }
  }
}
