extern "C" {
  #include "diodefs.h"
  #define DEV_dio
  #include "dioitf.h"
}

#define info	 DIOinfo
#define INSTANCE DIOinstance
#define MODEL	 DIOmodel

#define SPICE_LETTER "D"
#define DEVICE_TYPE "spice_dio"
#define MIN_NET_NODES 2
#define MAX_NET_NODES 2
#define INTERNAL_NODES 1
#define MODEL_TYPE "d"
#define VALUE_NAME "area"

static std::string port_names[] = {"a", "c"};
static std::string state_names[] = {};
