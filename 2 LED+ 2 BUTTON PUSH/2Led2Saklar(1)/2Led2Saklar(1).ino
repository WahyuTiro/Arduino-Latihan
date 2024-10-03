const int pinLED1 = 8; //  nomor pin LED 1
const int pinLED2 = 9; //  nomor pin LED 2
const int pinTombol1 = 2; // nomor pin Tombol 1
const int pinTombol2 = 3; // nomor pin Tombol 2


bool statusAkhirTombol1 = LOW;  // status Tombol 1 terakhir 
bool statusAkhirTombol2 = LOW;  // status Tombol 2 terakhir
bool statusLED1 = LOW;         // status LED 1
bool statusLED2 = LOW;         // status LED 2


void setup() {
  Serial.begin(9600);
  pinMode(pinLED1, OUTPUT);    // LED 1 sebagai output
  pinMode(pinLED2, OUTPUT);    // LED 2 sebagai output
  pinMode(pinTombol1, INPUT);  // Tombol 1 sebagai input
  pinMode(pinTombol2, INPUT);  // Tombol 2 sebagai input
}


void loop() {
  // LED 1
  bool statusTombol1 = digitalRead(pinTombol1);  // cek status Tombol
  if (statusTombol1 != statusAkhirTombol1) {       // jika status Tombol berubah dari sebelumnya
    if (statusTombol1 == HIGH) {                  // jika Tombol berubah ke status LOW (dilepas)
      if (statusLED1 == LOW) {          // jika status LED hidup
        digitalWrite(pinLED1, HIGH); // maka LED dimatikan
        statusLED1 = HIGH;
        Serial.println("LED 1 Nyala");
      } else {                        // jika status LED mati
        digitalWrite(pinLED1, LOW);  // maka LED dihidupkan
        statusLED1 = LOW;
        Serial.println("LED 1 Mati");
      }
    }
    delay(1);  // waktu jeda
  }  
  statusAkhirTombol1 = statusTombol1;  // simpan status Tombol untuk loop1 selanjutnya


  //LED 2
  bool statusTombol2 = digitalRead(pinTombol2);  // cek status Tombol
  if (statusTombol2 != statusAkhirTombol2) {       // jika status Tombol berubah dari sebelumnya
    if (statusTombol2 == HIGH) {                  // jika Tombol berubah ke status LOW (dilepas)
      if (statusLED2 == LOW) {          // jika status LED hidup
        digitalWrite(pinLED2, HIGH); // maka LED dimatikan
        statusLED2 = HIGH;
        Serial.println("LED 2 Nyala");
      } else {                        // jika status LED mati
        digitalWrite(pinLED2, LOW);  // maka LED dihidupkan
        statusLED2 = LOW;
        Serial.println("LED 2 Mati");        
      }
    }
    delay(1);  // waktu jeda
  }  
  statusAkhirTombol2 = statusTombol2;  // simpan status Tombol untuk loop1 selanjutnya
}