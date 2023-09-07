SET(SOURCES
        CubeCell.cpp
        CubeEdge.cpp
        RubiksCube.cpp
        RubiksCubeApp.cpp
        )

SET(HEADERS
        CubeCell.h
        CubeEdge.h
        RubiksCube.h
        RubiksCubeApp.h
        )

add_library(RubiksCubeLib STATIC ${SOURCES} ${HEADERS})
target_include_directories(RubiksCubeLib PUBLIC ${PROJECT_SOURCE_DIR})
