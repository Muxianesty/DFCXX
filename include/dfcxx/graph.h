#ifndef DFCXX_GRAPH_H
#define DFCXX_GRAPH_H

#include <unordered_map>
#include <unordered_set>

namespace dfcxx {

    class Graph {

    };

    class IO;
    class VarBuilder;
    class KernStorage;
    class DFVariable;

    class GraphHelper {
        friend IO;
    private:
        Graph &graph_;

        GraphHelper(Graph &graph, VarBuilder &builder, KernStorage &storage);

    public:
        VarBuilder &builder_;
        KernStorage &storage_;

        void addNode(DFVariable &node);
        void addChannel(DFVariable &source, DFVariable &target);
    };

}

#endif // DFCXX_GRAPH_H
