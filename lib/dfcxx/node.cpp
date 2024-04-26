#include "dfcxx/node.h"

namespace dfcxx {
    Node::Node(DFVariable *var, OpType type, uint16_t offset) : var_(var),
                                                                type_(type),
                                                                offset_(offset) { }

    bool Node::operator==(const dfcxx::Node &node) const {
        return var_ == node.var_;
    }
}
