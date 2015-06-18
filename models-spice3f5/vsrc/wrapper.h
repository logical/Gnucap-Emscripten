extern "C" {
  #include "vsrcdefs.h"
  #define DEV_vsrc
  #include "vsrcitf.h"
}

#define info	 VSRCinfo
#define INSTANCE VSRCinstance
#define MODEL	 VSRCmodel

#define SPICE_LETTER "V"
#define DEVICE_TYPE "spice_vsrc"
#define MIN_NET_NODES 2
#define MAX_NET_NODES 2
#define INTERNAL_NODES 1
#define MODEL_TYPE ""

static std::string port_names[] = {"p", "n"};
static std::string state_names[] = {};
