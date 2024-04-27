#ifndef DFCXX_GRAPH_H
#define DFCXX_GRAPH_H

#include <vector>
#include <unordered_map>
#include <unordered_set>

#include "dfcxx/vars/var.h"

#include "dfcxx/node.h"
#include "dfcxx/channel.h"

namespace dfcxx {

    class GraphHelper;
    class Kernel;
    class IO;
    class DFCIRBuilder;

    class Graph {
        friend GraphHelper;
        friend Kernel;
        friend IO;
        friend DFCIRBuilder;
    private:
        std::unordered_set<Node> nodes_;
        std::unordered_set<Node> start_nodes_;
        std::unordered_map<Node, std::vector<Channel>> inputs_;
        std::unordered_map<Node, std::vector<Channel>> outputs_;
        std::unordered_map<Node, Channel> connections_;

        Graph() = default;

        Node findNode(DFVariable *var);
        void addNode(DFVariable *var, OpType type, NodeData data);
        void addChannel(DFVariable *source, DFVariable *target, unsigned op_ind, bool connect);
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

        void addNode(DFVariable *var, OpType type, NodeData data);
        void addChannel(DFVariable *source, DFVariable *target, unsigned op_ind, bool connect);
    };

}

#endif // DFCXX_GRAPH_H
