#include "main.h"
#include "DServo.h"

Servo servos[12];
bool light = 0;

void setup() {
 pinMode(13,OUTPUT);
 digitalWrite(13,light);
 for (int i = 0; i < 12; i++) {
   servos[i].attach(i);
 }
}

// RawHID packets are always 64 bytes
byte buffer[64];

void loop() {
 int n;
 n = RawHID.recv(buffer, 0); // 0 timeout = do not wait
 if (n > 0) {
   for (int i = 0; i < 12; i++) {
     servos[i].write(buffer[i]);
   }
   light ^= 1;
   digitalWrite(13,light);
 }
}
