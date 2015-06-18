extern "C" {
  #include "asrcdefs.h"
  #define DEV_asrc
  #include "asrcitf.h"
}

#define info	 ASRCinfo
#define INSTANCE ASRCinstance
#define MODEL	 ASRCmodel

#define SPICE_LETTER "B"
#define DEVICE_TYPE "spice_asrc"
#define MIN_NET_NODES 2
#define MAX_NET_NODES 2
#define INTERNAL_NODES 0
#define MODEL_TYPE ""

static std::string port_names[] = {"p", "n"};
static std::string state_names[] = {};
