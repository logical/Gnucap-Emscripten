extern "C" {
  #include "bsim1def.h"
  #define DEV_bsim1
  #include "bsim1itf.h"
}

#define info	 B1info
#define INSTANCE B1instance
#define MODEL	 B1model

#define SPICE_LETTER "M"
#define DEVICE_TYPE "spice_bsim1"
#define MIN_NET_NODES 4
#define MAX_NET_NODES 4
#define INTERNAL_NODES 2
#define MODEL_TYPE "nmos4|pmos4"

static std::string port_names[] = {"d", "g", "s", "b"};
static std::string state_names[] = {"vbd","vbs","vgs","vds","id",
				    "ibs","ibd","gm","gds","gmbs",
				    "gbd","gbs","qb","iqb","qg",
				    "iqg","qd","iqd","cggb","cgdb",
				    "cgsb","cbgb","cbdb","cbsb","capbd",
				    "iqbd","capbs","iqbs","cdgb","cddb",
				    "cdsb","vono","vdsato","qbs","qbd"};
