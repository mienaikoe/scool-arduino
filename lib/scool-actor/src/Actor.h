
#ifndef SCOOL_NODE_H
#define SCOOL_NODE_H

#include <Scool.h>


namespace Scool {



  typedef enum {

  }


  class Node {
    Action* actions;

    public:
      Node();
      void loop();

    private:
      void listen();
  };

};




#endif
