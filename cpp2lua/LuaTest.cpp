extern "C"{
  #include <lua5.2/lua.h>
  #include <lua5.2/lualib.h>
  #include <lua5.2/lauxlib.h>
}


int main(int argc ,char * argv[]){

  lua_State *L = luaL_newstate();
  luaL_openlibs(L);
  int retLoad = luaL_loadfile(L, "cpp2lua/Test.lua");

  if(retLoad == 0){
    printf("load file sucesss \n");
  }else{
    printf("load file error \n");
    return -1;
  }
  //必须先运行起来 坑。。。
  lua_pcall(L, 0, 0, 0);


  lua_settop(L,0);

  lua_getglobal(L, "na");
  lua_getglobal(L, "ag");

  int age = lua_tointeger(L, -1);
  const char *name = lua_tostring(L, -2);
  printf("name = %s \n", name);
  printf("age = %d \n", age);

  lua_close(L);


  return 0;
}
