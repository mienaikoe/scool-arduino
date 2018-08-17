
#ifndef SCOOL_CORE_ACTION_H
#define SCOOL_CORE_ACTION_H

#include "../Message.h"
#include "Routine.h"
#include "Condition.h"

namespace Scool {
  namespace Core {

    class Action : Message {
      Routine routine;
      Condition conditions[];

      protected:
        Action(char packet[]);

      private:
        virtual void go(bool reverse);
    };

  };
};


#endif
