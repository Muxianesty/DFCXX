#ifndef DFCXX_CONTROL_H
#define DFCXX_CONTROL_H

#include "dfcxx/graph.h"
#include "dfcxx/kernstorage.h"
#include "dfcxx/varbuilders/builder.h"

namespace dfcxx {

class Kernel;

class Control {
  friend Kernel;
private:
  Graph &graph;
  GraphHelper helper;
  VarBuilder &builder;
  KernStorage &storage;

  Control(Graph &graph, VarBuilder &builder, KernStorage &storage);

public:
  DFVariable &mux(DFVariable &ctrl, DFVariable &var1, DFVariable &var2);
};

} // namespace dfcxx

#endif // DFCXX_CONTROL_H
