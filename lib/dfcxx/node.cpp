#include "dfcxx/node.h"

namespace dfcxx {

Node::Node(DFVariable *var, OpType type, NodeData data) : var(var),
                                                          type(type),
                                                          data(data) {}

bool Node::operator==(const dfcxx::Node &node) const {
  return var == node.var;
}

} // namespace dfcxx
