#include "dfcxx/constant.h"

namespace dfcxx {
    using TypeKind = dfcxx::DFConstant::TypeKind;
    using ConstantValue = dfcxx::DFConstant::ConstantValue;

    Constant::Constant(Graph &graph, VarBuilder &builder, KernStorage &storage) :
                                                                      graph_(graph),
                                                                      helper_(graph, builder, storage),
                                                                      builder_(builder),
                                                                      storage_(storage) {}

    DFVariable &Constant::var(const DFType &type, int64_t value) {
        DFVariable *var = builder_.buildConstant(helper_, type, TypeKind::INT, ConstantValue{.int_ = value});
        storage_.addVariable(var);
        graph_.addNode(var, OpType::CONST, NodeData{});
        return *var;
    }

    DFVariable &Constant::var(const DFType &type, uint64_t value) {
        DFVariable *var = builder_.buildConstant(helper_, type, TypeKind::UINT, ConstantValue{.uint_ = value});
        storage_.addVariable(var);
        graph_.addNode(var, OpType::CONST, NodeData{});
        return *var;
    }

    DFVariable &Constant::var(const DFType &type, double value) {
        DFVariable *var = builder_.buildConstant(helper_, type, TypeKind::FLOAT, ConstantValue{.double_ = value});
        storage_.addVariable(var);
        graph_.addNode(var, OpType::CONST, NodeData{});
        return *var;
    }
}