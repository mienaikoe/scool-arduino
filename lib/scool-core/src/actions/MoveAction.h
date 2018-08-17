#ifndef SCOOL_CORE_MOVE_ACTION_H
#define SCOOL_CORE_MOVE_ACTION_H

#include "Action.h"


namespace Scool {
  namespace Core {

    class MoveAction : public Action {
      int startTime;

      protected:
        MoveAction(char packet[]);

      private:
        void start(int startTime);
        void forward();
        void backward();
    };

  }
}

#endif
