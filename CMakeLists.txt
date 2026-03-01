cmake_minimum_required(VERSION 3.13 FATAL_ERROR)
project( BeatEmUp )

set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_EXTENSIONS OFF )
set( CMAKE_CXX_STANDARD_REQUIRED ON )

set( APP_EXECUTABLE BeatEmUp)

include_directories( inc )

ADD_EXECUTABLE(BeatEmUp "inc/BeatEmUp.h" "src/BeatEmUp.cpp" "inc/EarthClass.h" "src/EarthClass.cpp"  "inc/MonsterClass.h" "src/MonsterClass.cpp" #"inc/MetalClass.h" "inc/WaterClass.h" "src/MetalClass.cpp" "src/WaterClass.cpp" "inc/WoodClass.h" "src/WoodClass.cpp" "inc/FireClass.h" "src/FireClass.cpp")
)

target_compile_definitions(BeatEmUp PRIVATE TESTING)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

set_property( DIRECTORY PROPERTY VS_STARTUP_PROJECT ${APP_EXECUTABLE} )

include (CTest)
add_test(${APP_EXECUTABLE}_test ${APP_EXECUTABLE} 1)

find_program(VALGRIND "valgrind")
if(VALGRIND)
	add_custom_target(valgrind
    COMMAND "${VALGRIND}" --tool=memcheck --leak-check=yes --show-reachable=yes --error-exitcode=1 $<TARGET_FILE:${APP_EXECUTABLE}>)
endif()
