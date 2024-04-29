#ifndef DFCXX_CONSTANT_H
#define DFCXX_CONSTANT_H

#include "dfcxx/graph.h"
#include "dfcxx/varbuilders/builder.h"
#include "dfcxx/kernstorage.h"

namespace dfcxx {

    class Kernel;

    class Constant {
        friend Kernel;
    private:
        Graph &graph_;
        GraphHelper helper_;
        VarBuilder &builder_;
        KernStorage &storage_;

        Constant(Graph &graph, VarBuilder &builder, KernStorage &storage);

    public:
        DFVariable &var(const DFType &type, int64_t value);
        DFVariable &var(const DFType &type, uint64_t value);
        DFVariable &var(const DFType &type, double value);
    };
}

#endif // DFCXX_CONSTANT_H
