#ifndef DFCXX_GRAPH_H
#define DFCXX_GRAPH_H

#include <unordered_map>
#include <unordered_set>

#include "dfcxx/vars/var.h"

#include "dfcxx/node.h"
#include "dfcxx/channel.h"

namespace dfcxx {

    class GraphHelper;
    class Kernel;
    class IO;

    class Graph {
        friend GraphHelper;
        friend Kernel;
        friend IO;
    private:
        std::unordered_set<Node> nodes_;
        std::unordered_set<Node> start_nodes_;
        std::unordered_map<Node, std::unordered_set<Channel>> inputs_;
        std::unordered_map<Node, std::unordered_set<Channel>> outputs_;

        Graph() = default;

        Node findNode(DFVariable *var);
        void addNode(DFVariable *var, OpType type, uint16_t offset);
        void addChannel(DFVariable *source, DFVariable *target);
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

        void addNode(DFVariable *var, OpType type, uint16_t offset);
        void addChannel(DFVariable *source, DFVariable *target);
    };

}

#endif // DFCXX_GRAPH_H
