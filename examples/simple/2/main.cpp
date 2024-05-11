#include "simple.h"

int main(int argc, char **argv) {
  SimpleKernel kernel;
  DFLatencyConfig config = {
          {dfcxx::ADD_INT, 8},
          {dfcxx::MUL_INT, 15}
  };
  kernel.compile(config, dfcxx::Linear);
}