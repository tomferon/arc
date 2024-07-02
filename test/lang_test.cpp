#include <catch2/catch_test_macros.hpp>

#include <arc/lang.h>

TEST_CASE("parsing of basic expressions", "[parse]") {
  REQUIRE(arc::Expression{"42"}.format() == "42");
  REQUIRE(arc::Expression{"3 + 1"}.format() == "3 + 1");
}

TEST_CASE("evaluation of basic expressions", "[eval]") {
  REQUIRE(arc::Expression{"42"}.evaluate() == arc::Expression{"42"});
  REQUIRE(arc::Expression{"3 + 1"}.evaluate() != arc::Expression{"3 + 1"});
  REQUIRE(arc::Expression{"3 + 1"}.evaluate() == arc::Expression{"4"});
}
