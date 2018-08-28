
#include "..\lib\Bluefruit52Lib\src\bluefruit.h"
#include "Actor.h"


// Beacon uses the Manufacturer Specific Data field in the advertising
// packet, which means you must provide a valid Manufacturer ID. Update
// the field below to an appropriate value. For a list of valid IDs see:
// https://www.bluetooth.com/specifications/assigned-numbers/company-identifiers
// 0x004C is Apple (for example)
#define MANUFACTURER_ID   0x004C

#define MANUFACTURER_SPECIFIC_T 0xFF

namespace Scool {

  Actor::Actor() {
    Bluefruit.begin();

    // off Blue LED for lowest power consumption
    Bluefruit.autoConnLed(true);

    // Set max power. Accepted values are: -40, -30, -20, -16, -12, -8, -4, 0, 4
    Bluefruit.setTxPower(0);
    Bluefruit.setName("Scool Actor");


    // Advertising packet
    Bluefruit.Advertising.addFlags(
      BLE_GAP_ADV_FLAGS_LE_ONLY_GENERAL_DISC_MODE
    );

    const uint8_t data[] = {
      Scool::Core::MSG_ACTOR_ADVERTISE
    };

    Bluefruit.Advertising.addData(
      MANUFACTURER_SPECIFIC_T, data, 0
    );
    //Bluefruit.Advertising.addTxPower();

    // Include bleuart 128-bit uuid
    //Bluefruit.Advertising.addService(bleuart);

    // Secondary Scan Response packet (optional)
    // Since there is no room for 'Name' in Advertising packet
    //Bluefruit.ScanResponse.addName();

    /* Start Advertising
     * - Enable auto advertising if disconnected
     * - Interval:  fast mode = 20 ms, slow mode = 152.5 ms
     * - Timeout for fast mode is 30 seconds
     * - Start(timeout) with timeout = 0 will advertise forever (until connected)
     *
     * For recommended advertising interval
     * https://developer.apple.com/library/content/qa/qa1931/_index.html
     */
    Bluefruit.Advertising.restartOnDisconnect(true);
    Bluefruit.Advertising.setInterval(32, 244);    // in unit of 0.625 ms
    Bluefruit.Advertising.setFastTimeout(30);      // number of seconds in fast mode
    Bluefruit.Advertising.start(0);                // 0 = Don't stop advertising after n seconds
  }

  void Actor::loop(){

  }
}
