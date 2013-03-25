#pragma once 

#include <windows.h>
#include <xtreme11\export.h>

namespace xt {

/*
 *
 */
/*extern "C++" */
extern "C" XTREME_EXPORT PCHAR* CommandLineToArgvA(PCHAR CmdLine, int* _argc);

} // namespace xt