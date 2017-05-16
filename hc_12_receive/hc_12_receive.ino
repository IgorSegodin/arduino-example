//HC-12 Button Receive

#include <SoftwareSerial.h>

SoftwareSerial hc_srl(2, 3); // RX, TX

byte LED_PIN = 12;

long unsigned led_sgl_millis = 0;

byte SGL_DELAY_MILLIS = 30;

void setup() {
  hc_srl.begin(9600);
  pinMode(LED_PIN, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  if (hc_srl.available() > 1) {
    int input = hc_srl.parseInt();
    if (input == 5) {
      led_sgl_millis = millis();
      Serial.println("receive");
    }
  }
  // clear the serial buffer for unwanted inputs
  hc_srl.flush();

  if (millis() - led_sgl_millis < SGL_DELAY_MILLIS) {
    Serial.println("enable");
    digitalWrite(LED_PIN, HIGH);
  } else {
    Serial.println("disable");
    digitalWrite(LED_PIN, LOW);
  }
  
  
  // delay little for better serial communication
  delay(20);
}

