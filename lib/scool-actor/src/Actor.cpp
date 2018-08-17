
using namespace Scool;
#include <Node.h>

Adafruit_BLE_UART BTLEserial = Adafruit_BLE_UART(
  ADAFRUITBLE_REQ, ADAFRUITBLE_RDY, ADAFRUITBLE_RST
);


class Node::Node() {
  BTLEserial.begin();
}

Node::loop(){
  // 1. Listen for new actions or interruptions
  this.listen();

  // 2.
}


Node::listen(){
  BTLEserial.pollACI();
  aci_evt_opcode_t status = BTLEserial.getState();
  if (status == ACI_EVT_CONNECTED) {
    uint8_t packet[20];
    for( int ix=0; BTLEserial.available() ; ix++ ){
      packet[ix] = BTLEserial.read();
    }
    if( packet[ix] )
  }
  if( status != lastStatus ){
    if( status == ACI_EVT_DISCONNECTED ){
      mode = STEP_PAUSE;
    }
    lastStatus = status;
  }
}
