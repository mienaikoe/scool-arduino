
#include "MoveAction.h"
#include "ObstacleCondition.h"


namespace Scool {
  namespace Core {

    MoveAction::MoveAction(char *packet)
    : Action::Action(packet){
      this->xLatest = 0;
      this->yLatest = 0;

      this->xmin = (uint16_t)packet[0];
      this->xmax = (uint16_t)packet[2];
      this->ymin = (uint16_t)packet[4];
      this->ymax = (uint16_t)packet[6];
      
      Condition conditions[1];
      this->conditions = conditions;
    }




    bool MoveAction::isFinished(){
      // take sensor readings
      this->xLatest = 0;
      this->yLatest = 0;

      // if current location is within bounds, return true;
      return 
        this->xLatest >= this->xmin && this->yLatest >= this->ymin &&
        this->xLatest <= this->xmax && this->yLatest <= this->ymax;
    }

    void MoveAction::doForward(){
      // -find vector between current position and closest vertex of bounds
      // -rotate until heading is parallel within a few degrees
      // -accelerate
    }

    void MoveAction::doBackward(){
      // 1. Point in the direction of the historical starting point
      // Step should include a condition based on sensor data

      // 2. Move in that direction
      // 2a. every few milliseconds, read sensor data to make sure robot is not approaching an obstacle
      // 2aa. if an obstacle is found, broadcast location of obstacle, then rotate slowly until the robot is no longer stuck, then continue.
      // 2b. If the destination is reached, finish
      // 2bb. If the destination cannot be solved, finish

      // 3. Finish
    }




  }
}
