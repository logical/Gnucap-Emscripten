extern "C" {
  #include "mos2defs.h"
  #define DEV_mos2
  #include "mos2itf.h"
}

#define info	 MOS2info
#define INSTANCE MOS2instance
#define MODEL	 MOS2model

#define SPICE_LETTER "M"
#define DEVICE_TYPE "spice_mos2"
#define MIN_NET_NODES 4
#define MAX_NET_NODES 4
#define INTERNAL_NODES 2
#define MODEL_TYPE "nmos2|pmos2"

static std::string port_names[] = {"d", "g", "s", "b"};
static std::string state_names[] = {};
