#include "addconst.h"

int main(int argc, char **argv) {
  AddConst kernel;
  DFLatencyConfig config = {
          {dfcxx::ADD_INT, 2},
          {dfcxx::MUL_INT, 3}
  };
  kernel.compile(config, dfcxx::Linear);
}