[example](#example)  
*command*(arg1 arg2 ...) #运行命令  
*set*(var_name var_value) #定义变量,或者给已经存在的变量赋值  
*command*(arg1 ${var_name}) #使用变量  
${name} #使用变量  
#------------------基础配置----------------#  
```cmake
cmake_minimum_required(VERSION num) #CMake最低版本号
project(cur_project_name) #项目信息
set(CMAKE_CXX_FLAGS "xxx") #C++ 编译器信息 如 -std=c++11
set(CMAKE_BUILD_TYPE "xxx") #设定编译模式 如Debug/Release
```
#------------------依赖执行部分----------------# 
```cmake
find_package(lib_name VERSION REQUIRED) #引入外部依赖
add_library(<name> [lib_type] source_list) #生成库
include_directories(${__lib_name_INCLUDE_DIRS__}) #指定include路径,放在add_executable前面
add_executable(cur_project_name x.cpp) #指定生成文件名
target_link_libraries(${__lib_name_LIBRARIES__}) #指定libraries路径,放在add_executable后面
```
#------------------其他辅助部分----------------#
```cmake
function(__func_name__ arg) #定义一个函数
add_subdirectory(dir) #添加一个子目录
AUX_SOURCE_DIRECTORY(. SRC_LIST) #查看当前目录,并保存到SRC_LIST
FOREACH(one_dir ${SRC_LIST})
    MESSAGE(${one_dir})
ENDFOREACH(one_dir)
```
#------------------判断----------------#  
```cmake
if(expresion)
else if(expresion)
else(expresion)
endif(expresion)
```
#---expresion---#
```cmake
if(var)
if(NOT var)
if(var1 AND var2)
if(var1 OR var2)
if(COMMAND dir) #为命令且可调用为真
if(EXISTS dir)
if(EXISTS file_name)
if(IS_DIRECTORY dir_name)
if(file1 IS_NEWER_THAN file2)
if(var MATCHES regex) #符合正则
```
#---循环---#
```cmake
WHILE(condition)
    command
ENDWHILE(condition)
```
#############常用##############
```cmake
add_definitions(-Dfoo)#引入编译宏定义
```
## 也可以用 cmake -D 来引入
```cmake
add_custom_command() #为工程添加一条自定义的构建规则
add_custom_target() #给指定的目标执行指定的命令,该目标没有输出文件,并始终被构建
option(<var>"description"[initial value])
option(
    USE_MY
    "Use tutorial implementation"
    ON
)
add_dependencies() #防止头文件冲突
install(
    TARGETS
    RUNTIME
    LIBRARY
    ARCHIVE
)
TARGET_INCLUDE_DIRECTORIES(<target>[SYSTEM][BEFORE]<INTERFACE|PUBLIC|PRIVATE>[items])
set_target_properties(example
    ARCHIVE_OUTPUT_DIRECTORY xx
    LIBRARY_OUTPUT_DIRECTORY xx
) #设置目标属性来改变构建方式
ENABLE_TESTING() #控制Makefile是否构建test目标
ADD_TEST(testname EXENAMEarg_list)
```

# example  
结构树:  
***build***  
CMakeLists.txt  
***include***  
|--hpp.hpp  
***src***  
|--hpp.cpp  
|--main.cpp
```cmake
cmake_minimum_required(VERSION 2.8.3)
project(test1)
add_compile_option(-std=c++11)
include_directories(include)
add_executable(main xx.cpp)
```
```cmake
cmake_minimum_required(VERSION 2.8.3)
project(test1)
add_compile_option(-std=c++11)
include_directories(include)
add_library(lib STATIC list_cpp list_hpp)
add_executable(main xx.cpp
```