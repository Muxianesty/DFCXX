#include "dfcxx/graph.h"

namespace dfcxx {
    GraphHelper::GraphHelper(Graph &graph, VarBuilder &builder, KernStorage &storage) : graph_(graph), builder_(builder), storage_(storage) {}
}