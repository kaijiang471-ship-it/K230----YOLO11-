#include <Arduino.h>

// 端口我们用最稳的一组
#define RX_PIN 5
#define TX_PIN 4
HardwareSerial SerialK230(1);



void setup() {
  Serial.begin(9600);
  SerialK230.begin(9600, SERIAL_8N1, RX_PIN, TX_PIN); 
  delay(100);
  Serial.println("ESP32 就绪");

}

void loop() {
  if (SerialK230.available()) {
    String s = SerialK230.readStringUntil('\n');
    s.trim();
    if(s.length()>0){
      Serial.println("正常接收：" + s); // 绝对不乱码
    }
  }
}