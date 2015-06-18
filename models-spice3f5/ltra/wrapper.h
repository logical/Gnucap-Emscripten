extern "C" {
  #include "ltradefs.h"
  #define DEV_ltra
  #include "ltraitf.h"
}

#define info	 LTRAinfo
#define INSTANCE LTRAinstance
#define MODEL	 LTRAmodel

#define SPICE_LETTER "O"
#define DEVICE_TYPE "spice_ltra"
#define MIN_NET_NODES 4
#define MAX_NET_NODES 4
#define INTERNAL_NODES 2
#define MODEL_TYPE ""

static std::string port_names[] = {"t1", "b1", "t2", "b2"};
static std::string state_names[] = {};
