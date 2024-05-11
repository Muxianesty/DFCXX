#include "muxmul.h"

int main(int argc, char **argv) {
  MuxMul kernel;
  DFLatencyConfig config = {
          {dfcxx::ADD_INT, 2},
          {dfcxx::MUL_INT, 3}
  };
  kernel.compile(config, dfcxx::Linear);
}