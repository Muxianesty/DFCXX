#include "dfcxx/IRbuilders/builder.h"

namespace dfcxx {
    std::stack<Node> DFCIRBuilder::topSortNodes(Graph *graph) {
        std::stack<Node> result;

        std::unordered_map<Node, size_t> checked;
        std::stack<Node> stack;

        for (Node node : graph->start_nodes_) {
            stack.push(node);
            checked[node] = 0;
        }

        while (!stack.empty()) {
            Node node = stack.top();
            size_t count = graph->outputs_[node].size();
            size_t curr;
            bool flag = true;
            for (curr = checked[node]; flag && curr < count; ++curr) {
                Channel next = graph->outputs_[node][curr];
                if (!checked[next.target_]) {
                    stack.push(next.target_);
                    flag = false;
                }
                ++checked[node];
            }

            if (flag) {
                stack.pop();
                result.push(node);
            }
        }
        return result;
    }

    void DFCIRBuilder::translate(dfcxx::Node node, dfcxx::Graph *graph, mlir::OpBuilder &builder) {
        auto loc = builder.getUnknownLoc();

        const auto &ins = graph->inputs_[node];
        const auto &outs = graph->outputs_[node];

        auto name_attr = mlir::StringAttr::get(&ctx_, node.var_->getName());

        switch (node.type_) {
            case OFFSET: {
                Node in = ins[0].source_;
                auto no_sign = mlir::IntegerType::get(builder.getContext(), 64, mlir::IntegerType::Signless);
                auto attr = mlir::IntegerAttr::get(no_sign, node.data_.offset_);
                auto newOp = builder.create<mlir::dfcir::OffsetOp>(loc, conv_[in.var_], map_[in], attr);
                map_[node] = newOp.getResult();
                break;
            }
            case IN: {
                if (node.var_->isStream()) {
                    auto newOp = builder.create<mlir::dfcir::InputOp>(loc, conv_[node.var_], name_attr, nullptr);
                    map_[node] = newOp.getResult();
                } else {
                    auto newOp = builder.create<mlir::dfcir::ScalarInputOp>(loc, conv_[node.var_], name_attr);
                    map_[node] = newOp.getResult();
                }
                break;
            }
            case OUT: {
                if (node.var_->isStream()) {
                    auto newOp = builder.create<mlir::dfcir::OutputOp>(loc, conv_[node.var_], name_attr, nullptr, nullptr);
                    map_[node] = newOp.getResult();
                } else {
                    auto newOp = builder.create<mlir::dfcir::ScalarOutputOp>(loc, conv_[node.var_], name_attr, nullptr);
                    map_[node] = newOp.getResult();
                }
                break;
            }
            case CONST: {
                auto constant = (DFConstant *)(node.var_);
                int64_t val;
                mlir::IntegerType attr_type;
                unsigned width = constant->getType().getTotalBits();
                switch (constant->getKind()) {
                    case DFConstant::INT:
                        val = constant->getInt();
                        attr_type = mlir::IntegerType::get(builder.getContext(), width, mlir::IntegerType::Signed);
                        break;
                    case DFConstant::UINT: {
                        auto tmpU = constant->getUInt();
                        memcpy(&val, &tmpU, sizeof(val));
                        attr_type = mlir::IntegerType::get(builder.getContext(), width, mlir::IntegerType::Unsigned);
                        break;
                    }
                    case DFConstant::FLOAT: {
                        auto tmpD = constant->getDouble();
                        memcpy(&val, &tmpD, sizeof(val));
                        attr_type = mlir::IntegerType::get(builder.getContext(), width, mlir::IntegerType::Signless);
                        break;
                    }
                }
                auto attr = mlir::IntegerAttr::get(attr_type, val);
                auto newOp = builder.create<mlir::dfcir::ConstantOp>(loc, conv_[node.var_], attr);
                map_[node] = newOp.getRes();
                break;
            }
            case MUX: {
                Node ctrl = ins[node.data_.mux_id_].source_;
                // TODO: Test!!!!!
                llvm::SmallVector<mlir::Value> mux;
                for (size_t i = 0; i < ins.size(); ++i) {
                    if (i != node.data_.mux_id_) {
                        mux.push_back(map_[ins[i].source_]);
                    }
                }
                mux_map_[node] = mux;
                auto newOp = builder.create<mlir::dfcir::MuxOp>(loc, conv_[node.var_], map_[ctrl], mux_map_[node]);
                map_[node] = newOp.getRes();
            }
            case ADD: {
                Node first = ins[0].source_;
                Node second = ins[1].source_;
                auto newOp = builder.create<mlir::dfcir::AddOp>(loc, conv_[node.var_], map_[first], map_[second]);
                map_[node] = newOp.getResult();
                break;
            }
            case SUB: {
                Node first = ins[0].source_;
                Node second = ins[1].source_;
                auto newOp = builder.create<mlir::dfcir::SubOp>(loc, conv_[node.var_], map_[first], map_[second]);
                map_[node] = newOp.getResult();
                break;
            }
            case DIV: {
                Node first = ins[0].source_;
                Node second = ins[1].source_;
                auto newOp = builder.create<mlir::dfcir::DivOp>(loc, conv_[node.var_], map_[first], map_[second]);
                map_[node] = newOp.getResult();
                break;
            }
            case MUL: {
                Node first = ins[0].source_;
                Node second = ins[1].source_;
                auto newOp = builder.create<mlir::dfcir::MulOp>(loc, conv_[node.var_], map_[first], map_[second]);
                map_[node] = newOp.getResult();
                break;
            }
        }
        if (graph->connections_.find(node) != graph->connections_.end()) {
            auto con_src = graph->connections_.at(node).source_;
            builder.create<mlir::dfcir::ConnectOp>(loc, map_[node], map_[con_src]);
        }
    }
}