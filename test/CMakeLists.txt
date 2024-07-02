add_executable(arc_tests)

target_link_libraries(arc_tests
  PRIVATE
    arc
    Catch2::Catch2WithMain
)

target_sources(arc_tests
  PRIVATE
    lang_test.cpp
)

include(Catch)
catch_discover_tests(arc_tests)
