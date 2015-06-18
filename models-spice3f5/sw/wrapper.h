extern "C" {
  #include "swdefs.h"
  #define DEV_sw
  #include "switf.h"
}

#define info	 SWinfo
#define INSTANCE SWinstance
#define MODEL	 SWmodel

#define SPICE_LETTER "S"
#define DEVICE_TYPE "spice_sw"
#define MIN_NET_NODES 4
#define MAX_NET_NODES 4
#define INTERNAL_NODES 0
#define MODEL_TYPE "sw"

static std::string port_names[] = {"p", "n", "ps", "ns"};
static std::string state_names[] = {};
