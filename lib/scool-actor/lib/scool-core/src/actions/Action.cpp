
#include "Action.h"
#include "Condition.h"


namespace Scool {
  namespace Core {

    Action::Action(char packet[])
    : Message::Message(packet) {
      //
    }


    bool Action::canContinue(){
      if( this->isFinished() ){
        return false;
      }

      int numConditions = sizeof(this->conditions)/sizeof(*this->conditions);
      for( int ix=0; ix < numConditions; ix++ ){
        Condition &condition = this->conditions[ix];
        if( !condition.checkAndHandle() ){
          return false;
        }
      }
      
      return true;
    }

    void Action::forward(){
      if( this->canContinue() ){
        this->doForward();
      }
    }

    void Action::backward(){
      if( this->canContinue() ){
        this->doBackward();
      }
    }

  }
}
