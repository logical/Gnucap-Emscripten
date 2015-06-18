extern "C" {
  #include "mos6defs.h"
  #define DEV_mos6
  #include "mos6itf.h"
}

#define info	 MOS6info
#define INSTANCE MOS6instance
#define MODEL	 MOS6model

#define SPICE_LETTER "M"
#define DEVICE_TYPE "spice_mos6"
#define MIN_NET_NODES 4
#define MAX_NET_NODES 4
#define INTERNAL_NODES 2
#define MODEL_TYPE "nmos6|pmos6"

static std::string port_names[] = {"d", "g", "s", "b"};
static std::string state_names[] = {};
