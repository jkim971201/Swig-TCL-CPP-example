%module swig_test

%include "typemaps.i"

%{

#include "test.h"

%}

%inline %{

void test_cmd()
{
  swigTest::test();
}

%}
