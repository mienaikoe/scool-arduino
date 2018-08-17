
#include "Action.h"
#include "Condition.h"


namespace Scool {
  namespace Core {

    Action::Action(char packet[])
    : Message::Message(packet) {
      //
    }

    void Action::go(bool reverse){
      bool canContinue = true;
      for( const Condition &condition : this->conditions ){
        if( !condition.check() ){
          condition.handle();
          canContinue = false;
          break;
        }
      }
      if( canContinue ){
        this->routine.go(reverse);
      }
    }



  }
}
