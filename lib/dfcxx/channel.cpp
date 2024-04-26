#include "dfcxx/channel.h"

namespace dfcxx {
    Channel::Channel(Node source, Node target) : source_(source), target_(target) { }

    bool Channel::operator== (const Channel &channel) const {
        return source_ == channel.source_ && target_ == channel.target_;
    }
}