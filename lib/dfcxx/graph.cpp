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

    void Graph::addChannel(DFVariable *source, DFVariable *target) {
        Node foundSource = findNode(source);
        Node foundTarget = findNode(target);
        Channel newChannel(foundSource, foundTarget);
        outputs_[foundSource].insert(newChannel);
        inputs_[foundTarget].insert(newChannel);
    }

    GraphHelper::GraphHelper(Graph &graph, VarBuilder &builder, KernStorage &storage) : graph_(graph), builder_(builder), storage_(storage) {}

    void GraphHelper::addNode(DFVariable *var, OpType type, uint16_t offset) {
        graph_.addNode(var, type, offset);
    }

    void GraphHelper::addChannel(DFVariable *source, DFVariable *target) {
        graph_.addChannel(source, target);
    }
}