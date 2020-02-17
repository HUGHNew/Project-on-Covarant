+ The Source Tree contains:  
    + CMake input files (CmakeLists.txt)  
    + Program source files (hello.cc)  
    + Program header files (hello.h)  
## Basic Concepts
+ CMAKE_MODULE_PATH  
    + Path to where the CMake modules are located  
+ CMAKE_INSTALL_PREFIX  
    + Where to put files when calling 'make install'
+ CMAKE_BUILD_TYPE
    + Type of build (Debug, Release, ...)
+ BUILD_SHARED_LIBS
    + Switch between shared and static libraries
## Using CMake
mkdir build ; cd build  
cmake [options] <source_tree>  
(make ;) make install  

## Hello World for CMake
```
Top-level project directory:
– CMakeLists.txt
– Sub-directory Hello:
● CMakeLists.txt
● hello.h
● hello.cc
– Sub-directory Test:
● CMakeLists.txt
● test.cc
```
### Top-Level CmakeLists.txt
```CMake
PROJECT( HELLO )
ADD_SUBDIRECTORY( Hello )
ADD_SUBDIRECTORY( Test )
```
### CmakeLists.txt in Hello dir
```CMake
# Adds a library called Hello (libHello.a under Linux) from the source file hello.cc
ADD_LIBRARY( Hello hello )
```
### CmakeLists.txt in Test dir
```cmake
# Make sure the compiler can find include files from our Hello library.
INCLUDE_DIRECTORIES(${HELLO_SOURCE_DIR}/Hello)
# Add binary called "helloWorld" that is built from the source file "test.cc".
# The extension is automatically found.
ADD_EXECUTABLE(helloWorld test)
# Link the executable to the Hello library.
TARGET_LINK_LIBRARIES(helloWorld Hello)
```
## Very simple syntax:
+ # This is a comment
+ Commands syntax: COMMAND( arg1 arg2 ... )
+ Lists A;B;C # semi-colon separated values
+ Variables ${VAR}
+ Conditional constructs
    + IF() ... ELSE()/ELSEIF() ... ENDIF()
+ Very useful: IF( APPLE ); IF( UNIX ); IF( WIN32 )
  + WHILE() ... ENDWHILE()
  + FOREACH() ... ENDFOREACH()
+ Regular expressions

### some command
+ INCLUDE_DIRECTORIES( “dir1” “dir2” ... )  
+ AUX_SOURCE_DIRECTORY( “source” )  
+ ADD_EXECUTABLE
+ ADD_LIBRARY
+ ADD_CUSTOM_TARGET
+ ADD_DEPENDENCIES( target1 t2 t3 ) target1 depends on t2 and t3
+ ADD_DEFINITIONS( “-Wall -ansi -pedantic”)
+ TARGET_LINK_LIBRARIES( target-name lib1 lib2 ...) Individual settings for each target
+ LINK_LIBRARIES( lib1 lib2 ...) All targets link with the same set of libs
+ SET_TARGET_PROPERTIES( ... ) lots of properties... OUTPUT_NAME, VERSION, ....
+ MESSAGE( STATUS|FATAL_ERROR “message” )
+ INSTALL( FILES “f1” “f2” “f3” DESTINATION . )
  + DESTINATION relative to ${CMAKE_INSTALL_PREFIX}
+ SET( VAR value [CACHE TYPE DOCSTRING [__FORCE__]])
+ LIST( APPEND|INSERT|LENGTH|GET|REMOVE_ITEM|REMOVE_AT|SORT ...)
+ STRING( TOUPPER|TOLOWER|LENGTH|SUBSTRING|REPLACE|REGEX ...)
+ SEPARATE_ARGUMENTS( VAR ) convert space separated string to list
+ FILE( WRITE|READ|APPEND|GLOB|GLOB_RECURSE|REMOVE|MAKE_DIRECTORY ...)
+ FIND_FILE
+ FIND_LIBRARY
+ FIND_PROGRAM
+ FIND_PACKAGE
+ EXEC_PROGRAM( bin [__work_dir__] ARGS <..> [OUTPUT_VARIABLE var] [RETURN_VALUE var] )
+ OPTION( OPTION_VAR “description string” [initial value] )