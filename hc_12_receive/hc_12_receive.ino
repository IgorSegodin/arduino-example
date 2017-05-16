//HC-12 Button Receive

#include <SoftwareSerial.h>

SoftwareSerial hc_srl(2, 3); // RX, TX

const byte LED_PIN = 12;

volatile unsigned long led_sgl_millis = 0;

const byte SGL_DELAY_MILLIS = 80;

byte led_state = 0;

void setup() {
  hc_srl.begin(9600);
  pinMode(LED_PIN, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  if (hc_srl.available() > 0) {
    char input = hc_srl.read();
    if (input == '5') {
      led_sgl_millis = millis();
    }
  }

  unsigned long elapsed = millis() - led_sgl_millis;

  if (elapsed < SGL_DELAY_MILLIS) {
    if (led_state != 1) {
      digitalWrite(LED_PIN, HIGH);
      led_state = 1;
    }
  } else {
    if (led_state != 0) {
      digitalWrite(LED_PIN, LOW);
      led_state = 0;
    }
  }
  
  // delay little for better serial communication
  //delay(20);
}

