#include <Windows.h>
#include <iostream>
extern "C" {
#include "Lua/lua.h"
#include "Lua/lauxlib.h"
#include "Lua/lualib.h"
#include "Lua/lopcodes.h"
#include "Lua/lobject.h"
#include "Lua/ldo.h"
#include "Lua/lstate.h"
}

void print_item(lua_State* L, int stack) {
	switch (lua_type(L, stack)) {
	case LUA_TSTRING:
		std::cout << stack << " STRING: " << lua_tolstring(L, stack, 0) << std::endl;
		break;
	case LUA_TNUMBER:
		std::cout << stack << " NUMBER: " << lua_tonumber(L, stack) << std::endl;
		break;
	case LUA_TBOOLEAN:
		std::cout << stack << " BOOLEAN: " << lua_toboolean(L, stack) << std::endl;
		break;
	case LUA_TTHREAD:
		std::cout << stack << " THREAD" << std::endl;
		break;
	case LUA_TNIL:
		std::cout << stack << " NIL" << std::endl;
		break;
	case LUA_TFUNCTION:
		std::cout << stack << " FUNCTION" << std::endl;
		break;
	case LUA_TTABLE:
		std::cout << stack << " TABLE" << std::endl;
	default: break;
	}
}

void print_stack(lua_State* L) {
	for (int i = -1; i > -(lua_gettop(L) + 1); i--) { print_item(L, i); }
}
