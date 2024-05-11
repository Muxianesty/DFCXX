#include "movingsum.h"

int main(int argc, char **argv) {
  MovingSum kernel;
  DFLatencyConfig config = {
          {dfcxx::ADD_INT, 2},
          {dfcxx::MUL_INT, 3}
  };
  kernel.compile(config, dfcxx::Linear);
}