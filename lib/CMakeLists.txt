add_library(Redef MODULE
  Redefinition.cpp
  RedefPlugin.cpp
)

add_library(Python MODULE
  PythonInterface.cpp
)

target_include_directories(Redef PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../include")

target_include_directories(Python PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../include")
