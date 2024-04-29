#include "dfcxx/IRbuilders/converter.h"

namespace dfcxx {
    DFCIRTypeConverter::DFCIRTypeConverter(mlir::MLIRContext *ctx) : ctx_(ctx) { }

    mlir::Type DFCIRTypeConverter::operator[](dfcxx::DFVariable *var) {
        const DFType &type = var->getType();
        mlir::Type newInnerType;

        if (type.isFixed()) {
            const FixedType &casted = (const FixedType &)(type);
            newInnerType = mlir::dfcir::DFCIRFixedType::get(ctx_, casted.isSigned(), casted.getIntBits(), casted.getFracBits());
        } else if (type.isFloat()) {
            const FloatType &casted = (const FloatType &)(type);
            newInnerType = mlir::dfcir::DFCIRFloatType::get(ctx_, casted.getExpBits(), casted.getFracBits());
        } else {
            return nullptr;
        }

        if (var->isStream()) {
            return mlir::dfcir::DFCIRStreamType::get(ctx_, newInnerType);
        } else if (var->isScalar()) {
            return mlir::dfcir::DFCIRScalarType::get(ctx_, newInnerType);
        } else if (var->isConstant()) {
            return mlir::dfcir::DFCIRConstantType::get(ctx_, newInnerType);
        }
        return nullptr;
    }
}