#include "dfcxx/offset.h"

#include "dfcxx/vars/vars.h"

namespace dfcxx {
    using Direction = dfcxx::DFVariable::Direction;
    using ConstantValue = dfcxx::DFConstant::ConstantValue;

    Offset::Offset(Graph &graph, VarBuilder &builder, KernStorage &storage) :
                                                                  graph_(graph),
                                                                  helper_(graph, builder, storage),
                                                                  builder_(builder),
                                                                  storage_(storage) {}

    DFVariable &Offset::operator()(DFVariable &stream, int64_t offset) {
        if (!stream.isStream()) { throw std::exception(); }
        DFVariable *var = builder_.buildStream("", Direction::NONE, helper_, stream.getType());
        storage_.addVariable(var);
        graph_.addNode(var, OpType::OFFSET, NodeData{.offset_ = offset});
        graph_.addChannel(&stream, var, 0, false);
        return *var;
    }

}