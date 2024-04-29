#ifndef DFCXX_OFFSET_H
#define DFCXX_OFFSET_H

#include "dfcxx/graph.h"
#include "dfcxx/varbuilders/builder.h"
#include "dfcxx/kernstorage.h"

namespace dfcxx {

    class Kernel;

    class Offset {
        friend Kernel;
    private:
        Graph &graph_;
        GraphHelper helper_;
        VarBuilder &builder_;
        KernStorage &storage_;

        Offset(Graph &graph, VarBuilder &builder, KernStorage &storage);

    public:
        DFVariable &operator()(DFVariable &stream, int64_t offset);
    };
}

#endif // DFCXX_OFFSET_H