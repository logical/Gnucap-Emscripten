extern "C" {
  #include "bsim2def.h"
  #define DEV_bsim2
  #include "bsim2itf.h"
}

#define info	 B2info
#define INSTANCE B2instance
#define MODEL	 B2model

#define SPICE_LETTER "M"
#define DEVICE_TYPE "spice_bsim2"
#define MIN_NET_NODES 4
#define MAX_NET_NODES 4
#define INTERNAL_NODES 2
#define MODEL_TYPE "nmos5|pmos5"

static std::string port_names[] = {"d", "g", "s", "b"};
static std::string state_names[] = {"vbd", "vbs", "vgs", "vds", "id",
				    "ibs", "ibd", "gm", "gds", "gmbs",
				    "gbd", "gbs", "qb", "iqb", "qg",
				    "iqg", "qd", "iqd", "cggb", "cgdb",
				    "cgsb", "cbgb", "cbdb", "cbsb", "capbd",
				    "iqbd", "capbs", "iqbs", "cdgb", "cddb",
				    "cdsb", "vono", "vdsato", "qbs", "qbd"};
