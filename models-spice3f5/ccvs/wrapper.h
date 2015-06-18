extern "C" {
  #include "ccvsdefs.h"
  #define DEV_ccvs
  #include "ccvsitf.h"
}

#define info	 CCVSinfo
#define INSTANCE CCVSinstance
#define MODEL	 CCVSmodel

#define SPICE_LETTER "H"
#define DEVICE_TYPE "spice_ccvs"
#define MIN_NET_NODES 3
#define MAX_NET_NODES 3
#define INTERNAL_NODES 1
#define MODEL_TYPE ""

static std::string port_names[] = {"p", "n", "in"};
static std::string state_names[] = {};
