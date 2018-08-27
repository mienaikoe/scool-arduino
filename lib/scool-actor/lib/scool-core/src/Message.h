#ifndef SCOOL_CORE_MESSAGE_H
#define SCOOL_CORE_MESSAGE_H

#include <stdint.h>

namespace Scool {
  namespace Core {

    /*
      Describes a GAP advertising data set to be used to broadcast
      to other actor(s) and director(s)
    */

    typedef enum {
      // methods for assuming direct control of actors.
      // Actors advertise themselves,
      // Director scans for actors, actor responds,
      // director abducts all the actors it needs,
      // and then releases them when it's done.
      // Director abduction has priority.
      // Lowest priority is assumed to be the birdseye view
      // of the mission, where higher priorities are smaller
      // tasks that are more important to do immediately.
      MSG_ACTOR_ADVERTISE   = 0x00,
      MSG_DIRECTOR_REQUEST  = 0x02,
      MSG_DIRECTOR_RESPONSE = 0x04,

      // queues an action with priority
      // actions are the main part of scool. They describe
      // higher-level actions that the director calls for.
      MSG_ACTION_QUEUE      = 0x10,
      MSG_ACTION_CLEAR      = 0x12,
      MSG_ACTION_PLAY       = 0x16,
      MSG_ACTION_PAUSE      = 0x18,

       // methods for navigation - setting of field constraints,
      // triangulation of location, notification of obstructions
      MSG_BOUNDS            =0x20,
      MSG_OBSTRUCTION       =0x22,
      MSG_NAVIGATE          =0x24,
      MSG_PATROL            =0x26
    } message_t;

    class Message {
      private:
        message_t messageType;
        const char *payload;
        uint8_t length;

      public:
        Message(
          message_t messageType, const char *payload, uint8_t length
        );
        Message(const char packet[]);
        uint8_t getLength() const;
        void * toPacket() const;

    };


  }
}

#endif
