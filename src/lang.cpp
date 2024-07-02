#include <string>
#include <boost/spirit/home/x3.hpp>

#include <arc/lang.h>

namespace arc {

template <typename T>
class Literal : public Term {
public:
  Literal() {}
  Literal(T val) : value{val} {}

private:
  T value{};
};

class Application : public Term {
};

// class Function : public Term {
// private:
//   std::vector<std::string> argument_names;
//   Expression body;
// };

class BuiltinFunction : public Term {
public:
  enum class BuiltinFunctionName {
    OP_PLUS,
  };

private:
  BuiltinFunctionName name;
};


Term parse(const std::string& expr) {
  namespace x3 = boost::spirit::x3;
  auto grammar = x3::int_;

  Literal<int> result;
  x3::parse(expr.begin(), expr.end(), grammar, result);
  return result;
}

Expression::Expression(const std::string& expr)
  : term{parse(expr)} {
}

std::string Expression::format() const {
  return term.format();
}

Expression Expression::evaluate() const {
  return *this;
}

bool Expression::operator==(const Expression& other) const {
  return true;
}

}
