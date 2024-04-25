#ifndef DFCXX_TYPEDEFS_H
#define DFCXX_TYPEDEFS_H

#include <unordered_map>

namespace dfcxx {

    enum Ops {
        ADD_INT = 1,
        ADD_FLOAT,
        MUL_INT,
        MUL_FLOAT
    };

    enum Scheduler {
        Linear = 0,
        Dijkstra
    };

} // namespace dfcxx

typedef std::unordered_map<dfcxx::Ops, unsigned> DFCXXLatencyConfig;

#endif // DFCXX_TYPEDEFS_H
