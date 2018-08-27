#include "Message.h"
#include "actions/Action.h"


namespace Scool {
  namespace Core {

    Message::Message(
      message_t messageType, const char *payload, uint8_t length
    ){
      this->messageType = messageType;
      this->payload = payload;
      this->length = length;
    }

    Message::Message(const char packet[]){
      this->messageType = (message_t)packet[0];
      this->payload = packet+1;
      this->length = sizeof(this->payload) / sizeof(*(this->payload));
    }

    uint8_t Message::getLength() const {
      return this->length;
    }

    void * Message::toPacket() const {
      char *ret = new char[this->length + 2]; //VLAs are permitted in c99
      ret[0] = this->messageType;
      for( int ix=0; ix < this->length; ix++ ){
        ret[ix+1] = this->payload[ix];
      }
      return ret;
    }

  }
}
