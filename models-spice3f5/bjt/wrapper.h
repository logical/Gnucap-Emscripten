extern "C" {
  #include "bjtdefs.h"
  #define DEV_bjt
  #include "bjtitf.h"
}

#define info	 BJTinfo
#define INSTANCE BJTinstance
#define MODEL	 BJTmodel

#define SPICE_LETTER "Q"
#define DEVICE_TYPE "spice_bjt"
#define MIN_NET_NODES 3
#define MAX_NET_NODES 4
#define INTERNAL_NODES 3
#define MODEL_TYPE "npn|pnp|npn1|pnp1"
#define UNCONNECTED_NODES uGROUND
#define VALUE_NAME "area"

static std::string port_names[] = {"c", "b", "e", "s"};
static std::string state_names[] = {};
