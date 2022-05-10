#include <iostream>

#include <emscripten.h>

extern "C"
{
    #include <lua.h>
    #include <lauxlib.h>
    #include <lualib.h>
}

extern "C"
{

EMSCRIPTEN_KEEPALIVE
void execute_lua(char const *code)
{
    lua_State *L = luaL_newstate();
    luaL_openlibs(L);

    auto error = luaL_loadstring(L, code) || lua_pcall(L, 0, 0, 0);
    if (error) {
        fprintf(stderr, "%s\n", lua_tostring(L, -1));
        lua_pop(L, 1); /* pop error message from the stack */
    }

    lua_close(L);
}

}
