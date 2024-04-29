#ifndef DFCXX_NODE_H
#define DFCXX_NODE_H

#include "dfcxx/vars/var.h"

namespace dfcxx {

    enum OpType : uint8_t {
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

    union NodeData {
        int64_t offset_;
        uint64_t mux_id_;
    };

    struct Node {
        DFVariable *var_;
        OpType type_;
        NodeData data_;


        Node(DFVariable *var, OpType _type, NodeData data_);

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
