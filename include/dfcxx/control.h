#ifndef DFCXX_CONTROL_H
#define DFCXX_CONTROL_H

#include "dfcxx/graph.h"
#include "dfcxx/varbuilders/builder.h"
#include "dfcxx/kernstorage.h"

namespace dfcxx {

    class Kernel;

    class Control {
        friend Kernel;
    private:
        Graph &graph_;
        GraphHelper helper_;
        VarBuilder &builder_;
        KernStorage &storage_;

        Control(Graph &graph, VarBuilder &builder, KernStorage &storage);

    public:
        DFVariable &mux(DFVariable &ctrl, DFVariable &var1, DFVariable &var2);
    };
}

#endif // DFCXX_CONTROL_H
