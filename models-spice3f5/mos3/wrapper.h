extern "C" {
  #include "mos3defs.h"
  #define DEV_mos3
  #include "mos3itf.h"
}

#define info	 MOS3info
#define INSTANCE MOS3instance
#define MODEL	 MOS3model

#define SPICE_LETTER "M"
#define DEVICE_TYPE "spice_mos3"
#define MIN_NET_NODES 4
#define MAX_NET_NODES 4
#define INTERNAL_NODES 2
#define MODEL_TYPE "nmos3|pmos3"

static std::string port_names[] = {"d", "g", "s", "b"};
static std::string state_names[] = {};
