#include "Motor.h"
#include "Sender.h"
#include "DistanceSensor.h"
#include "PINS.h"

#define numRecords 80

Sender sender;
Motor motor(M_STEP, M_DIR, M_EN);
DistanceSensor TFLuna(TF_RX, TF_TX, Serial1);

void setup() {
  sender.begin("gLIDAR", "12345678", 1234);
  motor.setDirection(1);
  motor.setVelocity(500);
}

void loop() {
  sender.checkIPs();
  TFLuna.collectData(motor, numRecords);
  motor.rotate();
  if(motor.checkRevolution()){
    sender.sendParameters(TFLuna.getData());
  }
}
