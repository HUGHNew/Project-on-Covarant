#在下注释
#代码经过测试过,本地没问题！
cmake_minimum_required(VERSION 2.8)#cmake最低版本要求
set(lib ...)#要链接的第三方库
set(lib_path ...)#库路径
project(FirsTest)#项目名，似乎必要，但没有太大的用
set(CMAKE_CXX_STANDARD 11)#设置编译信息
add_subdirectory(${lib_path})
add_executable(main test.cpp)#生成可执行文件，第一个参数为可执行文件名，后续参数为源文件
target_link_libraries(main ${lib})#链接第三方库 效果类似于 g++ -l(lower L)