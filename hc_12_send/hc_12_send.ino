//HC-12 Button Send

#include <SoftwareSerial.h>

SoftwareSerial hc_srl(2, 3); // RX, TX

const byte BTN_PIN = 8;

void setup() {
  pinMode(BTN_PIN, INPUT);
  hc_srl.begin(9600);

  Serial.begin(9600);
  
  pinMode(10, OUTPUT);
  digitalWrite(10, HIGH);
}

void loop() {
  byte btn_state = digitalRead(BTN_PIN);
  if (btn_state == 1) {
    Serial.println("send");
    hc_srl.println(5);
  }
  // delay little for better serial communication
  delay(20);
}

