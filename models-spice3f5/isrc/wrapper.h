extern "C" {
  #include "isrcdefs.h"
  #define DEV_isrc
  #include "isrcitf.h"
}

#define info	 ISRCinfo
#define INSTANCE ISRCinstance
#define MODEL	 ISRCmodel

#define SPICE_LETTER "I"
#define DEVICE_TYPE "spice_isrc"
#define MIN_NET_NODES 2
#define MAX_NET_NODES 2
#define INTERNAL_NODES 0
#define MODEL_TYPE ""

static std::string port_names[] = {"p", "n"};
static std::string state_names[] = {};
