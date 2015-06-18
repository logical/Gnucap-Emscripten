extern "C" {
  #include "mesdefs.h"
  #define DEV_mes
  #include "mesitf.h"
}

#define info	 MESinfo
#define INSTANCE MESinstance
#define MODEL	 MESmodel

#define SPICE_LETTER "Z"
#define DEVICE_TYPE "spice_mes"
#define MIN_NET_NODES 3
#define MAX_NET_NODES 3
#define INTERNAL_NODES 2
#define MODEL_TYPE "nmf|pmf|nmf1|pmf1"

static std::string port_names[] = {"d", "g", "s"};
static std::string state_names[] = {};
