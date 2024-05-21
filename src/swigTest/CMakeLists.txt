project(swigTest LANGUAGES CXX)

set(PROJECT_HOME ${CMAKE_CURRENT_SOURCE_DIR})

add_swig(I_FILE    test.i 
         NAME      swigTest 
         NAMESPACE swigTest)

target_include_directories(${PROJECT_NAME}
  PRIVATE
  ${TCL_INCLUDE_PATH}
  ${PROJECT_HOME}
)

target_sources(${PROJECT_NAME}
  PRIVATE
  test.cpp
)
