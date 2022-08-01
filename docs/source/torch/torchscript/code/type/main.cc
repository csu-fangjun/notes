#include "torch/script.h"

static void TestTypeKind() {
  // https://github.com/pytorch/pytorch/blob/master/aten/src/ATen/core/jit_type_base.h
  torch::TypeKind k = torch::TypeKind::AnyType;
  TORCH_CHECK(torch::typeKindToString(k) == std::string("AnyType"));

  // NamedType is not a member of TypeKind
}

static void TestNumberType() {
  // torch::NumberType::get() returns a static object!
  // so p and q are actually the same
  torch::NumberTypePtr p = torch::NumberType::get();
  torch::NumberTypePtr q = torch::NumberType::get();

  TORCH_CHECK(p.get() == q.get());

  TORCH_CHECK(p->str() == "Scalar");
  TORCH_CHECK(p->kind() == torch::NumberType::Kind);
  TORCH_CHECK(p->kind() == torch::TypeKind::NumberType);
}

static void TestIntType() {
  torch::IntTypePtr p = torch::IntType::get();
  TORCH_CHECK(p->str() == "int");
  TORCH_CHECK(p->kind() == torch::TypeKind::IntType);
  TORCH_CHECK(p->kind() == torch::IntType::Kind);
  TORCH_CHECK(p->isSubtypeOf(torch::NumberType::get()) == true);
}

static void TestFloatType() {
  torch::FloatTypePtr p = torch::FloatType::get();
  TORCH_CHECK(p->str() == "float");
  TORCH_CHECK(p->kind() == torch::TypeKind::FloatType);
  TORCH_CHECK(p->kind() == torch::FloatType::Kind);
  TORCH_CHECK(p->isSubtypeOf(torch::NumberType::get()) == true);
  TORCH_CHECK(p->isSubtypeOf(torch::IntType::get()) == false);
}

static void TestBoolType() {
  torch::BoolTypePtr p = torch::BoolType::get();
  TORCH_CHECK(p->str() == "bool");
  TORCH_CHECK(p->kind() == torch::TypeKind::BoolType);
  TORCH_CHECK(p->kind() == torch::BoolType::Kind);
  TORCH_CHECK(p->isSubtypeOf(torch::NumberType::get()) == true);
  TORCH_CHECK(p->isSubtypeOf(torch::IntType::get()) == false);
}

static void TestNamedType() {
  // torch::Type is an abstract class!
  //
  // torch::NamedType is an abstract class!
  //
  // torch::NamedType t(torch::TypeKind::AnyType, "foo.bar"); // error
  // TORCH_CHECK(t.name()->qualifiedName() == "foo.bar");
}

static void TestAnyType() {
  torch::AnyTypePtr p = torch::AnyType::get();
  TORCH_CHECK(p->Kind == torch::TypeKind::AnyType);
  TORCH_CHECK(p->kind() == torch::TypeKind::AnyType);
  TORCH_CHECK(p->str() == "Any");
  TORCH_CHECK(p->requires_grad() == false);

  TORCH_CHECK(p == torch::AnyType::get());

  // available in newer versions of PyTorch
  // TORCH_CHECK(p->equals(torch::AnyType::get()));

  TORCH_CHECK(torch::toString(p) == "Any");
}

int main() {
  TestTypeKind();
  TestNumberType();
  TestIntType();
  TestFloatType();
  TestNamedType();
  TestAnyType();
  return 0;
}
