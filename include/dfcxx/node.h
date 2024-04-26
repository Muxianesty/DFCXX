#ifndef DFCXX_NODE_H
#define DFCXX_NODE_H

#include "dfcxx/vars/var.h"

namespace dfcxx {

    enum OpType {
        OFFSET = 0,
        IN,
        OUT,
        CONST,
        MUX,
        ADD,
        SUB,
        DIV,
        MUL
    };

    struct Node {
        DFVariable *var_;
        OpType type_;
        uint16_t offset_;

        Node(DFVariable *var, OpType _type, uint16_t offset_);

        bool operator== (const Node &node) const;
    };
}

template<>
struct std::hash<dfcxx::Node> {
    size_t operator() (const dfcxx::Node &node) const noexcept {
        return std::hash<dfcxx::DFVariable *>()(node.var_);
    }
};

#endif // DFCXX_NODE_H
