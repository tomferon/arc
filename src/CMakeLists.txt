add_library(arc)

target_include_directories(arc
  PUBLIC
    "${CMAKE_CURRENT_LIST_DIR}/include"
)

target_sources(arc
  PRIVATE
    lang.cpp

  PUBLIC
    include/arc/lang.h
)
