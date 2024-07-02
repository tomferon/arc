#pragma once

#include <string>

namespace arc {

class Term {
public:
  virtual ~Term() {}
  virtual std::string format() const = 0;
};

class Expression {
public:
  Expression(const std::string&);

  std::string format() const;
  Expression evaluate() const;
  bool operator==(const Expression&) const;

private:
  Term term;
};

}
