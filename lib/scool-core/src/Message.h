#ifndef SCOOL_CORE_MESSAGE_H
#define SCOOL_CORE_MESSAGE_H

namespace Scool {
  namespace Core {

    typedef enum {
      MESSAGE_FIELD     = 0x00, // describes the field - marks a likely obstruction point, defines the field geometry, defines the coordinate system
      MESSAGE_ACTION    = 0x02, // queues an action with priority
      MESSAGE_QUEUE     = 0x04, // methods on the action queue itself pause, resume, clear, clear all
      MESSAGE_NAVIGATE  = 0x06, // methods for navigation - triangulation of location, or simple pings to see who's around
      MESSAGE_DIRECTOR  = 0x08, // methods for assuming direct control of actors. Director broadcast, actor responds, director abducts all the actors it needs, and then releases them when it's done. Directors braodcast with a priority. Lowest priority is assumed to be the birdseye view of the mission, where higher priorities are smaller tasks that are more important to do immediately.
    } scool_message_t;


    class Message {
      protected:
        Message(char packet[]);
    };


  }
}

#endif
