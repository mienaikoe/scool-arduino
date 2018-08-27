
#ifndef SCOOL_CORE_ACTION_H
#define SCOOL_CORE_ACTION_H

#include "../Message.h"
#include "Condition.h"

namespace Scool {
  namespace Core {

    class Action : Message {
      protected:
        Condition *conditions;
        virtual void doForward();
        virtual void doBackward();
      
      public:
        Action(char *packet);

        virtual bool isFinished();
        bool canContinue();
        
        void forward();
        void backward();
    };

  };
};


#endif
