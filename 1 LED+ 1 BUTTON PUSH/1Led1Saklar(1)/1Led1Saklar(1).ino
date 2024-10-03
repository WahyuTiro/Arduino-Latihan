const int pinLAMPU = 13;                   // nomor pin LED
const int pinTOMBOL = 7;                 // nomor pin Tombol

bool statusTombolAkhir = LOW;            // status Tombol terakhir
bool statusLampu = LOW;                    // status LED

void setup() {
  Serial.begin(9600);  
  pinMode(pinLAMPU, OUTPUT);               // LED sebagai output
  pinMode(pinTOMBOL, INPUT);             // Tombol sebagai input
}
void loop() {
  bool statusTombol = digitalRead(pinTOMBOL);    // cek status Tombol
  if (statusTombol != statusTombolAkhir) {       // jika status Tombol berubah dari sebelumnya
    if (statusTombol == HIGH) {                  // jika Tombol berubah ke status LOW (dilepas)
      if (statusLampu == LOW) {                    // jika status LED hidup
        digitalWrite(pinLAMPU, HIGH);              // maka LED dimatikan
        statusLampu = HIGH;
        Serial.println("LED Nyala");        
      } else {                                   // jika status LED mati
        digitalWrite(pinLAMPU, LOW);               // maka LED dihidupkan
        statusLampu = LOW;
        Serial.println("LED Padam");         
      }
    }
  }  
  statusTombolAkhir = statusTombol;               // simpan status Tombol untuk loop1 selanjutnya
  delay(100); 
}
