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
            # internal dependencies
            arg STREQUAL DEPENDENCIES OR
            # find_package
            arg STREQUAL DEPENDENCIES_PKG OR
            # pkg_check_modules
            arg STREQUAL DEPENDENCIES_PC)
            set(MODE ${arg})
            set(MODE_TYPE LIST)
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
        add_executable(${name} ${PROP_LINKING} ${PROP_SOURCES})
    endif()
endfunction()