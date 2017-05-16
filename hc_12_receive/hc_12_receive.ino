//HC-12 Button Receive


#include <SoftwareSerial.h>

SoftwareSerial hc_srl(2, 3); // RX, TX

byte LED_PIN = 12;

void setup() {
  hc_srl.begin(9600);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
   
  if(hc_srl.available() > 1){    
    int input = hc_srl.parseInt();
    if (input == 1111) {
      digitalWrite(LED_PIN, HIGH);
    }
    if(input == 0000){
      digitalWrite(LED_PIN, LOW);
    }
  }
  //clear the serial buffer for unwanted inputs
  hc_srl.flush();
  
  //delay little for better serial communication
  delay(20);
 
}

