#ifndef SCOOL_CONDITION_H
#define SCOOL_CONDITION_H


namespace Scool {
  namespace Core {
    class Condition {
      public:
        virtual bool checkAndHandle();
    };
  }
}

#endif
