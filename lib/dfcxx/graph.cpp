#include "dfcxx/graph.h"

#include <algorithm>

namespace dfcxx {
    Node Graph::findNode(DFVariable *var) {
        return *std::find_if(nodes_.begin(), nodes_.end(), [&]
            (const Node &node) {
                return node.var_ == var;
            });
    }

    void Graph::addNode(DFVariable *var, OpType type, uint16_t offset) {
        nodes_.emplace(var, type, offset);
        if (type == IN || type == CONST) {
            start_nodes_.emplace(var, type, offset);
        }
    }

    void Graph::addChannel(DFVariable *source, DFVariable *target, unsigned op_ind, bool connect) {
        Node foundSource = findNode(source);
        Node foundTarget = findNode(target);
        Channel newChannel(foundSource, foundTarget, op_ind);
        outputs_[foundSource].push_back(newChannel);
        inputs_[foundTarget].push_back(newChannel);
        if (connect) {
            connections_.insert(std::make_pair(foundTarget, newChannel));
            connections_.at(foundTarget) = newChannel;
        }
    }

    GraphHelper::GraphHelper(Graph &graph, VarBuilder &builder, KernStorage &storage) : graph_(graph), builder_(builder), storage_(storage) {}

    void GraphHelper::addNode(DFVariable *var, OpType type, uint16_t offset) {
        graph_.addNode(var, type, offset);
    }

    void GraphHelper::addChannel(DFVariable *source, DFVariable *target, unsigned op_ind, bool connect) {
        graph_.addChannel(source, target, op_ind, connect);
    }
}