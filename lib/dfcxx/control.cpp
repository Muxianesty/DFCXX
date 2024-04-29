#include "dfcxx/control.h"

#include "dfcxx/vars/vars.h"

namespace dfcxx {
    using Direction = dfcxx::DFVariable::Direction;
    using ConstantValue = dfcxx::DFConstant::ConstantValue;

    Control::Control(Graph &graph, VarBuilder &builder, KernStorage &storage) :
                                                                    graph_(graph),
                                                                    helper_(graph, builder, storage),
                                                                    builder_(builder),
                                                                    storage_(storage) {}

    DFVariable &Control::mux(DFVariable &ctrl, DFVariable &var1, DFVariable &var2) {
        if (var1.getType() != var2.getType()) { throw std::exception(); }
        DFVariable *var = nullptr;
        if (var1.isConstant()) {
            var = helper_.builder_.buildConstant(helper_, var1.getType(), ((DFConstant&)(var1)).getKind(), ConstantValue{});
        } else if (var1.isScalar()) {
            var = helper_.builder_.buildScalar("", Direction::NONE, helper_, var1.getType());
        } else if (var1.isStream()) {
            var = helper_.builder_.buildStream("", Direction::NONE, helper_, var1.getType());
        }

        storage_.addVariable(var);
        graph_.addNode(var, OpType::MUX, NodeData{.mux_id_ = 0});
        graph_.addChannel(&ctrl, var, 0, false);
        graph_.addChannel(&var1, var, 1, false);
        graph_.addChannel(&var2, var, 2, false);
        return *var;
    }
}