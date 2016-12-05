/*
 * CLuaCalc.h
 *
 *  Created on: 5 de dez de 2016
 *      Author: sirineo
 */

#ifndef CLUACALC_H_
#define CLUACALC_H_

#ifdef __cplusplus
# include <lua5.3/lua.hpp>
#else
# include <lua5.3/lua.h>
# include <lua5.3/lualib.h>
# include <lua5.3/lauxlib.h>
#endif
#include "CCalc.h"

class CLuaCalc {
	static const char className[];
	static const luaL_Reg methods[];

	static CCalc *CheckCCalc(lua_State *L, int narg);
	static int CreateCCalc(lua_State *L);
	static int GetI(lua_State *L);
	static int SetI(lua_State *L);
	static int GetN(lua_State *L);
	static int SetN(lua_State *L);
	static int GetPv(lua_State *L);
	static int SetPv(lua_State *L);
	static int CalcPmt(lua_State *L);
	static int GcCCalc(lua_State *L);
public:
	static void Register(lua_State* L);
};

#endif /* CLUACALC_H_ */
