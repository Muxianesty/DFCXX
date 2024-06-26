#ifndef DFCXX_IO_H
#define DFCXX_IO_H

#include "dfcxx/graph.h"
#include "dfcxx/kernstorage.h"
#include "dfcxx/typebuilders/builder.h"
#include "dfcxx/varbuilders/builder.h"

namespace dfcxx {

class Kernel;

class IO {
  friend Kernel;
private:
  Graph &graph;
  GraphHelper helper;
  VarBuilder &varBuilder;
  KernStorage &storage;

  IO(Graph &graph, TypeBuilder &typeBuilder, VarBuilder &builder, KernStorage &storage);

public:
  DFVariable &input(const std::string &name, const DFType &type);

  DFVariable &inputScalar(const std::string &name, const DFType &type);

  DFVariable &output(const std::string &name, const DFType &type);

  DFVariable &outputScalar(const std::string &name, const DFType &type);
};

} // namespace dfcxx

#endif // DFCXX_IO_H
