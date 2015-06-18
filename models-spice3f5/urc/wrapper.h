extern "C" {
  #include "urcdefs.h"
  #define DEV_urc
  #include "urcitf.h"
}

#define info	 URCinfo
#define INSTANCE URCinstance
#define MODEL	 URCmodel

#define SPICE_LETTER "U"
#define DEVICE_TYPE "spice_urc"
#define MIN_NET_NODES 3
#define MAX_NET_NODES 3
#define INTERNAL_NODES 2
#define MODEL_TYPE ""

static std::string port_names[] = {"t1", "t2", "ref"};
static std::string state_names[] = {};
