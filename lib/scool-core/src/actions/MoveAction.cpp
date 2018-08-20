
#include "Action.h"
#include "MoveAction.h"


namespace Scool {
  namespace Core {

    MoveAction::MoveAction(char packet[])
    : Action::Action(packet){
      this->routine = new MoveRoutine();
      this->conditions = {
        new ObstacleCondition(),
        new DestinationCondition()
      };
    }

    void MoveAction::start( int startTime ){
      this->startTime = startTime;
    }

    void MoveAction::forward(){
      // 1. Point in the direction
      // Step should include a condition based on sensor data

      // 2. Move in that direction
      // 2a. every few milliseconds, read sensor data to make sure robot is not approaching an obstacle
      // 2aa. if an obstacle is found, broadcast location of obstacle, then rotate slowly until the robot is no longer stuck, then continue.
      // 2b. If the destination is reached, finish
      // 2bb. If the destination cannot be solved, finish

      // 3. Finish
    }

    void MoveAction::backward(){
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
