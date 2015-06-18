extern "C" {
  #include "tradefs.h"
  #define DEV_tra
  #include "traitf.h"
}

#define info	 TRAinfo
#define INSTANCE TRAinstance
#define MODEL	 TRAmodel

#define SPICE_LETTER "T"
#define DEVICE_TYPE "spice_tra"
#define MIN_NET_NODES 4
#define MAX_NET_NODES 4
#define INTERNAL_NODES 2
#define MODEL_TYPE ""

static std::string port_names[] = {"t1", "b1", "t2", "b2"};
static std::string state_names[] = {};
