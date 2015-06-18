extern "C" {
  #include "resdefs.h"
  #define DEV_res
  #include "resitf.h"
}

#define info	 RESinfo
#define INSTANCE RESinstance
#define MODEL	 RESmodel

#define SPICE_LETTER "R"
#define DEVICE_TYPE "spice_res"
#define MIN_NET_NODES 2
#define MAX_NET_NODES 2
#define INTERNAL_NODES 0
#define MODEL_TYPE "r"

static std::string port_names[] = {"p", "n"};
static std::string state_names[] = {};
