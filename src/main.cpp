#include <Arduino.h>
#include <SPI.h>
#include <Adafruit_BLE_UART.h>

#include "Route.h"


// BLE connection
#define ADAFRUITBLE_REQ 10
#define ADAFRUITBLE_RDY 2     // This should be an interrupt pin, on Uno thats #2 or #3
#define ADAFRUITBLE_RST 9

Adafruit_BLE_UART BTLEserial = Adafruit_BLE_UART(
  ADAFRUITBLE_REQ, ADAFRUITBLE_RDY, ADAFRUITBLE_RST
);

Route route = Route();





void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
    delay(20);
    Serial.println("Starting Setup");

    // Actuation
    pinMode(RELAY_DIRECTION_LEFT, OUTPUT);
    pinMode(RELAY_DIRECTION_RIGHT, OUTPUT);
    pinMode(RELAY_POWER_LEFT, OUTPUT);
    pinMode(RELAY_POWER_RIGHT, OUTPUT);

    // Communication
    BTLEserial.begin();
    digitalWrite(LED_BUILTIN, LOW);
}






mob_mode_t mode = STEP_PAUSE;
aci_evt_opcode_t lastStatus;

void listenForInstruction(){
  BTLEserial.pollACI();
  aci_evt_opcode_t status = BTLEserial.getState();
  if (status == ACI_EVT_CONNECTED) {
    uint8_t action;
    while (BTLEserial.available()) {
      action = BTLEserial.read();
      if( action >= STEP_START ){
        mode = action;
      } else {
        route.add( action );
      }
    }
  }
  if( status != lastStatus ){
    if( status == ACI_EVT_DISCONNECTED ){
      mode = STEP_PAUSE;
    }
    lastStatus = status;
  }
}

void carryOutInstruction(){
  switch( mode ){
    case STEP_START:
      if( route.hasNext() ){
        route.next();
      } else {
        mode = STEP_PAUSE;
      }
      break;
    case STEP_REVERSE:
      if( route.hasBack() ){
        route.back();
      } else {
        mode = STEP_PAUSE;
      }
      break;
    case STEP_PAUSE:
      route.pause();
      break;
  }
}



void loop() {

  // 1. Listen for new instructions and add them to a queue
  listenForInstruction();

  // 2. Carry out one instruction of the set
  carryOutInstruction();

  // 3.TODO: If obstacle encountered, inform master of current surroundings and await further instructions

}
