#include <Arduino.h>
#include <Route.h>



void stop(){
  digitalWrite(RELAY_POWER_LEFT,   LOW);
  digitalWrite(RELAY_POWER_RIGHT,  LOW);
  digitalWrite(RELAY_DIRECTION_LEFT,  LOW);
  digitalWrite(RELAY_DIRECTION_RIGHT, LOW);
}

void advance(uint8_t duration){
  digitalWrite(RELAY_DIRECTION_LEFT,  LOW);
  digitalWrite(RELAY_DIRECTION_RIGHT, LOW);
  digitalWrite(RELAY_POWER_LEFT,   HIGH);
  digitalWrite(RELAY_POWER_RIGHT,  HIGH);
  delay(duration);
  stop();
}


// 1 = 45, 2 = 90... -1=-45, -2=-90
void spin( int angle, uint8_t duration ){
  if( angle > 0 ){
    digitalWrite(RELAY_DIRECTION_LEFT,  LOW);
    digitalWrite(RELAY_DIRECTION_RIGHT, HIGH);
    digitalWrite(RELAY_POWER_LEFT,   HIGH);
    digitalWrite(RELAY_POWER_RIGHT,  HIGH);
  } else if( angle < 0 ){
    digitalWrite(RELAY_DIRECTION_LEFT,  HIGH);
    digitalWrite(RELAY_DIRECTION_RIGHT, LOW);
    digitalWrite(RELAY_POWER_LEFT,   HIGH);
    digitalWrite(RELAY_POWER_RIGHT,  HIGH);
  }

  uint8_t turningDelay = abs(angle) * 20; // TODO: This is an estimate only
  delay( turningDelay );
  stop();
  delay( duration - turningDelay );
}






Route::Route(){
  steps = new step_action_t[20];
  length = 0;
  cursor = 0;
}

void Route::add( step_action_t step ){
  int steps_size = sizeof(steps)/sizeof(step_action_t);
  if( length >= steps_size ){
    step_action_t *newSteps = new step_action_t[length * 2];
    for( int i = 0; i < length; i++ ){
      newSteps[i] = steps[i];
    }
    delete [] steps;
    steps = newSteps;
  }

  steps[length++] = step;
}

void Route::next(void){
  switch(steps[cursor++]){
    case STEP_STILL:
      pause();
      delay(200);
    break;
    case STEP_FORE:
      advance(100);
      delay(100);
    break;
    case STEP_FORE_RIGHT:
      spin( 1, 100 );
      advance(100);
    break;
    case STEP_RIGHT:
      spin( 2, 100 );
      advance(100);
    break;
    case STEP_BACK_RIGHT:
      spin( 3, 100 );
      advance(100);
    break;
    case STEP_BACK:
      spin( 4, 100 );
      advance(100);
    break;
    case STEP_BACK_LEFT:
      spin( -3, 100 );
      advance(100);
    break;
    case STEP_LEFT:
      spin( -2, 100 );
      advance(100);
    break;
    case STEP_FORE_LEFT:
      spin( -1, 100 );
      advance(100);
    break;
  }
}

void Route::back(void){
  switch(steps[cursor--]){
    case STEP_STILL:
      pause();
      delay(200);
    break;
    case STEP_FORE:
      advance(100);
      delay(100);
    break;
    case STEP_FORE_RIGHT:
      spin( 1, 100 );
      advance(100);
    break;
    case STEP_RIGHT:
      spin( 2, 100 );
      advance(100);
    break;
    case STEP_BACK_RIGHT:
      spin( 3, 100 );
      advance(100);
    break;
    case STEP_BACK:
      spin( 4, 100 );
      advance(100);
    break;
    case STEP_BACK_LEFT:
      spin( -3, 100 );
      advance(100);
    break;
    case STEP_LEFT:
      spin( -2, 100 );
      advance(100);
    break;
    case STEP_FORE_LEFT:
      spin( -1, 100 );
      advance(100);
    break;
  }
}

void Route::pause(){
  if( !paused ){
    stop();
    paused = true;
  }
}

bool Route::hasNext(){
  return cursor < length;
}

bool Route::hasBack(){
  return cursor > 0;
}
