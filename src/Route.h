#ifndef ROUTE_H
#define ROUTE_H


typedef enum {
  STEP_STILL       =0x00,
  STEP_FORE        =0x01,
  STEP_FORE_RIGHT  =0x02,
  STEP_RIGHT       =0x03,
  STEP_BACK_RIGHT  =0x04,
  STEP_BACK        =0x05,
  STEP_BACK_LEFT   =0x06,
  STEP_LEFT        =0x07,
  STEP_FORE_LEFT   =0x08
} step_action_t;

typedef enum {
  STEP_START       =0xF0,
  STEP_PAUSE       =0xF1,
  STEP_REVERSE     =0xF2
} mob_mode_t;

typedef enum {
  RELAY_DIRECTION_LEFT  =4,
  RELAY_POWER_LEFT      =5,
  RELAY_DIRECTION_RIGHT =6,
  RELAY_POWER_RIGHT     =7
} mob_relay_t;



class Route {
  step_action_t* steps;
  int length;
  int cursor;
  bool paused;
public:
  Route();
  void add( step_action_t step );
  void next(void);
  void back(void);
  void pause(void);
  bool hasNext();
  bool hasBack();
};

#endif
