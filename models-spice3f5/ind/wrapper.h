extern "C" {
  #include "inddefs.h"
  #define DEV_ind
  #include "inditf.h"
}

#define info	 INDinfo
#define INSTANCE INDinstance
#define MODEL	 INDmodel

#define SPICE_LETTER "L"
#define DEVICE_TYPE "spice_ind"
#define MIN_NET_NODES 2
#define MAX_NET_NODES 2
#define INTERNAL_NODES 1
#define MODEL_TYPE ""

static std::string port_names[] = {"p", "n"};
static std::string state_names[] = {};
