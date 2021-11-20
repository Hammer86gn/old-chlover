option(CHLOVER_BUILD_ASSETS_TOOL "Build the Chlover Assets tool" ON)


if (CHLOVER_BUILD_ASSETS_TOOL)
    chlover_module(assets-tool EXECUTABLE
        INCLUDE assets/include
        DEPENDENCIES engine argh
        SOURCES
        assets/src/Main.cpp
        )
endif()