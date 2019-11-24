#ifdef _WIN32
  #define IS_TTY_EXPORT __declspec (dllexport)
#else
  #define IS_TTY_EXPORT
#endif

#ifdef __cplusplus
extern "C" {
#endif

IS_TTY_EXPORT int luaopen_is_tty (lua_State *L);

#ifdef __cplusplus
}
#endif