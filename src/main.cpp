#include <iostream>
#include <filesystem>
#include <string>
#include <tcl.h>

extern "C" { extern int Swigtest_Init(Tcl_Interp* interp); }

bool exit_mode = true;
char** cmd_argv;

int sourceTclFile(std::string& filename, Tcl_Interp *interp)
{
  std::string cmd = "source " + filename;

  int code = Tcl_Eval(interp, cmd.c_str() );

  const char* result = Tcl_GetStringResult(interp);
  if( result[0] != '\0')
    std::cout << result << std::endl;

  if(exit_mode)
    exit(0);

  return code;
}

int customTclInit(char** argv, Tcl_Interp* interp)
{
  interp = Tcl_CreateInterp();

  if(Tcl_Init(interp) == TCL_ERROR)
  {
    std::cout << "ERROR - Tcl interpreter \
    is not created successfully" << std::endl;
    return TCL_ERROR;
  }
  else
  {
    Swigtest_Init(interp);
    //std::string cmd = "puts \"Swig Test!\"";
    //Tcl_Eval(interp, cmd.c_str() );

    std::string filename = std::string(argv[1]);

    sourceTclFile(filename, interp);

    return TCL_OK;
  }
}

int tclInitWrapper(Tcl_Interp* interp)
{
  return customTclInit(cmd_argv, interp);
}

int main(int argc, char** argv)
{
  if(argc <  2)
  {
    std::cout << "give input .tcl file" << std::endl;
    exit(0);
  }

  cmd_argv = argv;

  Tcl_Main(1, argv, tclInitWrapper);

  return 0;
}
