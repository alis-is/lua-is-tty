#if defined(LUA_USE_POSIX) /* { */

#include <unistd.h>
#define stdin_is_tty() isatty(0)
#define stdout_is_tty() isatty(1)
#elif defined(LUA_USE_WINDOWS) /* }{ */
#include <io.h>
#include <windows.h>
#define stdin_is_tty() _isatty(_fileno(stdin))
#define stdout_is_tty() _isatty(_fileno(stdout))
#else                     /* }{ */
/* ISO C definition */
#define stdin_is_tty() 0  /* assume stdin is not a tty */
#define stdout_is_tty() 0 /* assume stdout is not a tty */
#endif                    /* } */

#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

#include "is_tty.h"

int l_stdin_is_tty(lua_State *L)
{
    lua_pushboolean(L, stdin_is_tty());
    return 1;
}

int l_stdout_is_tty(lua_State *L)
{
    lua_pushboolean(L, stdout_is_tty());
    return 1;
}

static const struct luaL_Reg lua_is_tty[] = {
    {"is_stdin_tty", l_stdin_is_tty},
    {"is_stdout_tty", l_stdout_is_tty},
    {NULL, NULL}};

int luaopen_is_tty(lua_State *L)
{
    lua_newtable(L);
    luaL_setfuncs(L, lua_is_tty, 0);

    return 1;
}
