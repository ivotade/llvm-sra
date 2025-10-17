add_library(Redef MODULE
  Redefinition.cpp
  RedefPlugin.cpp
)

target_include_directories(Redef PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../include")
