/*
 * LuaTest.cc
 *
 *  Created on: 2 de dez de 2016
 *      Author: sirineo
 */

#ifdef __cplusplus
# include <lua5.3/lua.hpp>
#else
# include <lua5.3/lua.h>
# include <lua5.3/lualib.h>
# include <lua5.3/lauxlib.h>
#endif
#include "CLuaCalc.h"

using namespace std;

int main(int argc, char **argv)
{
	lua_State *L = luaL_newstate();

	luaopen_base(L);
	luaopen_table(L);
	luaopen_io(L);
	luaopen_string(L);
	luaopen_math(L);
	luaopen_debug(L);

	CLuaCalc::Register(L);

	if(argc > 1)
    	luaL_dofile(L, argv[1]);

    lua_close(L);
    return 0;
}


