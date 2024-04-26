#ifndef DFCXX_IO_H
#define DFCXX_IO_H

#include "dfcxx/graph.h"
#include "dfcxx/varbuilders/builder.h"
#include "dfcxx/kernstorage.h"

namespace dfcxx {

    class Kernel;

    class IO {
        friend Kernel;
    private:
        Graph &graph_;
        GraphHelper helper_;
        VarBuilder &builder_;
        KernStorage &storage_;

        IO(Graph &graph, VarBuilder &builder, KernStorage &storage);

    public:
        DFVariable &input(const std::string &name, const DFType &type);
        DFVariable &inputScalar(const std::string &name, const DFType &type);
        DFVariable &output(const std::string &name, const DFType &type);
        DFVariable &outputScalar(const std::string &name, const DFType &type);
    };
}

#endif // DFCXX_IO_H
