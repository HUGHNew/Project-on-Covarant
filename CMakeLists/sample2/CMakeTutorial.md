~~下面代码都经过了Ubuntu18.04的测试,旁边那个txt也有~~
```cmake
#最简单的cmake语法
#内容写到一个名为 CMakeLists.txt 的文件中去
#编译单文件
#得到可执行文件 Tutorial (与 project 无关)
#系统指令不区分大小写
cmake_minimum_required (VERSION 2.6)#VERSION 必须大写
project (Tutorial)#测试了一下，这个东西在Linux不必要
add_executable(Tutorial tutorial.cxx)
```
在有 CMakeLists.txt 的路径下输入指令 
$ cmake .
CMD 也行 , 不得先装 cmake

然后会生成一个 Makefile 输入
$ make 
即开始编译(Windows应该一样的吧)
得到可执行文件


稍微麻烦点的
目录结构:  
+ .  
+ ├── CMakeLists.txt  
+ ├── main.cpp  
+ └── subdir  
    + ├── hello.cpp
    + └── hello.hpp
```cmake
cmake_minimum_required(VERSION 2.8)
set(sub ./subdir)#定义变量
set(CMAKE_CXX_FLAGS "-std=c++11")
add_library(hello STATIC ${sub}/hello.cpp ${sub}/hello.hpp )#生成库
add_executable(first main.cpp) #${sub}/hello.cpp ${sub}/hello.hpp)
target_link_libraries(first hello)#链接库
```
```cmake
#等效写法
cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_FLAGS "-std=c++11")#可要可不要
add_executable(first main.cpp ./subdir/hello.cpp) 
```
如果使用了第三方库
`target_link_libraries(Executable ThirdLib)`  
如上指令来连接第三方库