#include "dfcxx/graph.h"

#include <algorithm>

namespace dfcxx {

Node Graph::findNode(DFVariable *var) {
  return *std::find_if(nodes.begin(), nodes.end(),
                       [&](const Node &node) {
                         return node.var == var;
                       });
}

void Graph::addNode(DFVariable *var, OpType type, NodeData data) {
  nodes.emplace(var, type, data);
  if (type == IN || type == CONST) {
    startNodes.emplace(var, type, data);
  }
}

void Graph::addChannel(DFVariable *source, DFVariable *target, unsigned opInd,
                       bool connect) {
  Node foundSource = findNode(source);
  Node foundTarget = findNode(target);
  Channel newChannel(foundSource, foundTarget, opInd);
  outputs[foundSource].push_back(newChannel);
  inputs[foundTarget].push_back(newChannel);
  if (connect) {
    connections.insert(std::make_pair(foundTarget, newChannel));
    connections.at(foundTarget) = newChannel;
  }
}

GraphHelper::GraphHelper(Graph &graph, TypeBuilder &typeBuilder, VarBuilder &varBuilder,
                         KernStorage &storage) : graph(graph), typeBuilder(typeBuilder),
                         varBuilder(varBuilder), storage(storage) {}

void GraphHelper::addNode(DFVariable *var, OpType type, NodeData data) {
  graph.addNode(var, type, data);
}

void
GraphHelper::addChannel(DFVariable *source, DFVariable *target, unsigned opInd,
                        bool connect) {
  graph.addChannel(source, target, opInd, connect);
}

} // namespace dfcxx