#include "dfcxx/node.h"

namespace dfcxx {
    Node::Node(DFVariable *var, OpType type, NodeData data) : var_(var),
                                                                type_(type),
                                                                data_(data) { }

    bool Node::operator==(const dfcxx::Node &node) const {
        return var_ == node.var_;
    }
}
