#ifndef SCOOL_OBSTACLE_CONDITION_H
#define SCOOL_OBSTACLE_CONDITION_H

#include "../lib/scool-core/src/actions/Condition.h"

namespace Scool {
  namespace Core {
    class ObstacleCondition : public Scool::Core::Condition {
      public:
        bool checkAndHandle();
    };
  }
}

#endif
