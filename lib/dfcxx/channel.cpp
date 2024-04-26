#include "dfcxx/channel.h"

namespace dfcxx {
    Channel::Channel(Node source, Node target, unsigned op_ind) : source_(source),
                                                                  target_(target),
                                                                  op_ind_(op_ind) { }

    bool Channel::operator== (const Channel &channel) const {
        return source_ == channel.source_ && target_ == channel.target_ && op_ind_ == channel.op_ind_;
    }
}