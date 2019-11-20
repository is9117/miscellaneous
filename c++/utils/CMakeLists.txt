# required CMake minimal version
CMAKE_MINIMUM_REQUIRED ( VERSION 2.8 )

# project info
PROJECT ( strutils )
SET ( PROJECT_VERSION_MAJOR 0 )
SET ( PROJECT_VERSION_MINOR 1 )



# build configuration
IF ( NOT CMAKE_BUILD_TYPE )
    MESSAGE ( "CMAKE_BUILD_TYPE not set. default is Debug" )
    SET ( CMAKE_BUILD_TYPE Debug )                          # -DCMAKE_BUILD_TYPE=Release|Debug
    SET ( CMAKE_VERBOSE_MAKEFILE true )
ENDIF ( NOT CMAKE_BUILD_TYPE )



SET ( BASE_SRC_FILES
        src/strutils.cpp
        )
# https://gitlab.kitware.com/cmake/community/wikis/doc/tutorials/How-To-Write-Platform-Checks
IF ( UNIX )

    MESSAGE ( "linux platform" )

    # build binary & source file
    SET ( TEST_OUT 
            test.out 
            )

    SET ( TEST_SRC_FILES
            ${BASE_SRC_FILES}
            src/test/strutils_test.cpp
            )

    # compiler
    SET ( CMAKE_C_COMPILER g++ )

    # 공통 컴파일 옵션, 링크 옵션
    ADD_COMPILE_OPTIONS ( -std=c++11 )

    IF ( CMAKE_BUILD_TYPE MATCHES Debug )

        ADD_COMPILE_OPTIONS ( -Wall -g -DDEBUG -DC_FLAGS )
        # ADD_COMPILE_OPTIONS ( -w -g -DDEBUG -DC_FLAGS )
        SET ( CMAKE_EXE_LINKER_FLAGS "-DDEBUG -DLINKER_FLAGS" )

    ELSEIF ( CMAKE_BUILD_TYPE MATCHES Release )

        ADD_COMPILE_OPTIONS ( -w -O3 -DRELEASE -DC_FLAGS )
        SET ( CMAKE_EXE_LINKER_FLAGS "-DRELEASE -DLINKER_FLAGS" )

    ENDIF ()

    # 전처리 추가
    ADD_DEFINITIONS ( -DPLATFORM_LINUX )
    ADD_DEFINITIONS ( -DLIBDPKG_VOLATILE_API=1 )    # for libdpdk

    # common library (-l)
    LINK_LIBRARIES ( )

    # common library (-L)
    CMAKE_POLICY ( SET CMP0015 NEW )                # to use relative path in cmake
    LINK_DIRECTORIES (  )

    # include path
    INCLUDE_DIRECTORIES ( src lib/catch/include )



ELSEIF ( MSYS )

    MESSAGE ( "windows platform" )


ELSE ()

    MESSAGE ( FATAL_ERROR "unsupported platform" )

ENDIF ()



# 출력 디렉토리
SET ( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BUILD_TYPE} )
SET ( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BUILD_TYPE}/lib )
SET ( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BUILD_TYPE}/lib )

ADD_EXECUTABLE ( ${TEST_OUT} ${TEST_SRC_FILES} )

