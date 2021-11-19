find_package(PkgConfig REQUIRED)
function(chlover_module name)
    set(PROP_TYPE "LIBRARY")
    if (BUILD_SHARED_LIBS)
        set(PROP_LINKING "SHARED")
    else()
        set(PROP_LINKING "STATIC")
    endif()
    set(PROP_SOURCES "")

    # mode dictates what it's currently modifying
    set(MODE "TYPE")
    # mode type is just meta
    # SINGLE: only 1 value
    # LIST: several values
    # FLAG: no value
    set(MODE_TYPE "SINGLE")
    # previous versions of the previous 2 variables in case they're needed (which they are)
    set(MODE_PREV "SOURCES")
    set(MODE_TYPE_PREV "LIST")

    foreach(arg IN LISTS ARGN)
        if (arg STREQUAL SOURCES OR
            # include directories
            arg STREQUAL INCLUDE OR
            # internal dependencies
            arg STREQUAL DEPENDENCIES OR
            # find_package
            arg STREQUAL DEPENDENCIES_PKG OR
            # pkg_check_modules
            arg STREQUAL DEPENDENCIES_PC)
            set(MODE ${arg})
            set(MODE_TYPE LIST)
            continue()
        elseif(arg STREQUAL TYPE OR
            arg STREQUAL LINKING)
            set(MODE_PREV ${MODE})
            set(MODE_PREV_TYPE ${MODE_TYPE})
            set(MODE ${arg})
            set(MODE_TYPE SINGLE)
        endif()
        if (MODE_TYPE STREQUAL "SINGLE")
            set(PROP_${MODE} ${arg})
            set(MODE ${MODE_PREV})
            set(MODE_TYPE ${MODE_TYPE_PREV})
        elseif(MODE_TYPE STREQUAL "LIST")
            list(APPEND "PROP_${MODE}" ${arg})
        endif()
    endforeach()

    if(PROP_TYPE STREQUAL "LIBRARY")
        add_library(${name} ${PROP_LINKING} ${PROP_SOURCES})
    elseif(PROP_TYPE STREQUAL "EXECUTABLE")
        add_executable(${name} ${PROP_SOURCES})
    endif()

    # Resolve all dependencies
    #   step 1. simple dependencies and includes
    if(DEFINED PROP_DEPENDENCIES)
        list(APPEND DEPENDENCIES ${PROP_DEPENDENCIES})
    endif()
    if(DEFINED PROP_INCLUDE)
        list(APPEND INCLUDE ${PROP_INCLUDE})
    endif()
    #   step 2. find_package dependencies
    if(DEFINED PROP_DEPENDENCIES_PKG)
        foreach(package IN LISTS PROP_DEPENDENCIES_PKG)
            find_package(${package})
            list(APPEND DEPENDENCIES ${${package}_LIBRARIES})
            list(APPEND INCLUDE ${${package}_INCLUDE_DIRS})
        endforeach()
    endif()
    if(DEFINED PROP_DEPENDENCIES_PC OR DEFINED PROP_DEPENDENCIES_PC_OPT)
        pkg_check_modules("modules-${name}-req" REQUIRED ${PROP_DEPENDENCIES_PC})
        list(APPEND DEPENDENCIES ${modules-${name}-req_LIBRARIES})
        list(APPEND LIBRARY_DIRS ${modules-${name}-req_LIBRARY_DIRS})
        list(APPEND INCLUDE ${modules-${name}-req_INCLUDE_DIRS})
    endif()

    #   step 3. add dependencies if found
    if(DEFINED DEPENDENCIES)
        target_link_libraries(${name} ${DEPENDENCIES})
    endif()
    if(DEFINED INCLUDE)
        target_include_directories(${name} PUBLIC ${INCLUDE})
    endif()
    #   also add the rest of the stuff
    if(DEFINED LIBRARY_DIRS)
        target_link_directories(${name} ${LIBRARY_DIRS})
    endif()
endfunction()