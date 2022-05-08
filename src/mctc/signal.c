/*
 *  --- taken from the internet ---
 *
 *  It overrides the FORTRAN intrinsic signal routine
 *  and gives the possibility to use custom signal
 *  handlers instead of the standard ones, pretty simple
 *  code but actually impossible to do with FORTRAN only.
 */
#include <signal.h>
#if defined(_WIN32) || defined(_WIN64)

#include <windows.h>
void fix_console_cp()
{
   SetConsoleOutputCP(65001);
}

#endif

typedef void (*sighandler_t)(int);

void
xtb_signal_handler(int signum, sighandler_t handler)
{
   signal(signum, handler);
}
