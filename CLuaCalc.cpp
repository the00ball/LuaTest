/*
 * CLuaCalc.cpp
 *
 *  Created on: 5 de dez de 2016
 *      Author: sirineo
 */

#include "CLuaCalc.h"

const char CLuaCalc::className[] = "Calc";

#define method(class, name) {#name, class::name}

const luaL_Reg CLuaCalc::methods[]= {
		method(CLuaCalc, GetI),
		method(CLuaCalc, SetI),
		method(CLuaCalc, GetN),
		method(CLuaCalc, SetN),
		method(CLuaCalc, SetPv),
		method(CLuaCalc, GetPv),
		method(CLuaCalc, CalcPmt),
		{0,0}
};

CCalc* CLuaCalc::CheckCCalc(lua_State* L, int narg)
{
	luaL_checktype(L, narg, LUA_TUSERDATA);
	void *ud = luaL_checkudata(L, narg, className);
	if(!ud)
	{
		lua_pushliteral(L, "Invalid userdata");
		lua_error(L);
	}
	return *(CCalc**)ud;
}

int CLuaCalc::CreateCCalc(lua_State* L)
{
	int n = luaL_checkinteger(L, 1);
	double i = luaL_checknumber(L, 2);
	double pv = luaL_checknumber(L, 3);

	CCalc *calc = new CCalc(n,i,pv);
	(*(CCalc**)lua_newuserdata(L, sizeof(CCalc *))) = calc;

	luaL_getmetatable(L, className);
	lua_setmetatable(L, -2);

	return 1;
}

int CLuaCalc::GetI(lua_State* L)
{
	CCalc *calc = CheckCCalc(L, 1);
	double i = calc->GetI();
	lua_pushnumber(L,i);
	return 1;
}

int CLuaCalc::SetI(lua_State* L)
{
	CCalc *calc = CheckCCalc(L, 1);
	double i = luaL_checknumber(L, 2);
	calc->SetI(i);
	return 0;
}

int CLuaCalc::GetN(lua_State* L)
{
	CCalc *calc = CheckCCalc(L, 1);
	int n = calc->GetN();
	lua_pushinteger(L, n);
	return 1;
}

int CLuaCalc::SetN(lua_State* L)
{
	CCalc *calc = CheckCCalc(L, 1);
	int n = luaL_checkinteger(L, 2);
	calc->SetN(n);
	return 0;
}

int CLuaCalc::GetPv(lua_State* L)
{
	CCalc *calc = CheckCCalc(L, 1);
	double pv = calc->GetPv();
	lua_pushnumber(L, pv);
	return 1;
}

int CLuaCalc::SetPv(lua_State* L)
{
	CCalc *calc = CheckCCalc(L, 1);
	double pv = luaL_checknumber(L, 2);
	calc->SetPv(pv);
	return 0;
}

int CLuaCalc::CalcPmt(lua_State* L)
{
	CCalc *calc = CheckCCalc(L, 1);
	double pmt = calc->CalcPmt();
	lua_pushnumber(L, pmt);
	return 1;
}

int CLuaCalc::GcCCalc(lua_State* L)
{
	CCalc *calc = CheckCCalc(L, 1);
	delete calc;
	return 0;
}

void CLuaCalc::Register(lua_State* L)
{
	lua_newtable(L);
	int methodtable = lua_gettop(L);
	luaL_newmetatable(L, className);
	int metatable   = lua_gettop(L);

	lua_pushliteral(L, "__metatable");
	lua_pushvalue(L, methodtable);
	lua_settable(L, metatable);  // hide metatable from Lua getmetatable()

	lua_pushliteral(L, "__index");
	lua_pushvalue(L, methodtable);
	lua_settable(L, metatable);

	lua_pushliteral(L, "__gc");
	lua_pushcfunction(L, GcCCalc);
	lua_settable(L, metatable);

	lua_pop(L, 1);  // drop metatable

	luaL_setfuncs(L, methods, 0);  // fill methodtable
	lua_pop(L, 1);  // drop methodtable

	lua_register(L, className, CreateCCalc);
}
