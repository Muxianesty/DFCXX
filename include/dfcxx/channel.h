#ifndef DFCXX_CHANNEL_H
#define DFCXX_CHANNEL_H

#include "dfcxx/node.h"

namespace dfcxx {
    struct Channel {
        Node source_;
        Node target_;
        unsigned op_ind_;

        Channel(Node source, Node target, unsigned op_ind);

        bool operator== (const Channel &channel) const;
    };
}

template<>
struct std::hash<dfcxx::Channel> {
    size_t operator() (const dfcxx::Channel &ch) const noexcept {
        return std::hash<dfcxx::DFVariable *>()(ch.source_.var_) * std::hash<dfcxx::DFVariable *>()(ch.target_.var_);
    }
};

#endif // DFCXX_CHANNEL_H
