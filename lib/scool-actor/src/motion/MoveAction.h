#ifndef SCOOL_CORE_MOVE_ACTION_H
#define SCOOL_CORE_MOVE_ACTION_H

#include "../lib/scool-core/src/actions/Action.h"

namespace Scool {
  namespace Core {

    class MoveAction : public Action {
      private:
        uint16_t xmin;
        uint16_t xmax;
        uint16_t ymin;
        uint16_t ymax;
        uint16_t xLatest;
        uint16_t yLatest;

      protected:
        void doForward();
        void doBackward();

      public:
        MoveAction(char *packet);
        bool isFinished();

    };

  }
}

#endif
