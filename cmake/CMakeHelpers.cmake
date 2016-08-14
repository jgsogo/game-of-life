


# Adds the given folder_name into the source files of the current project. 
# Use this macro when your module contains .cpp and .h files in several subdirectories.
# Your sources variable needs to be WSPP_SOURCE_FILES and headers variable WSPP_HEADER_FILES.
#   - Credit: https://github.com/zaphoyd/websocketpp/blob/master/cmake/CMakeHelpers.cmake
macro(add_source_folder folder_name)
    file(GLOB H_FILES_IN_FOLDER_${folder_name} ${folder_name}/*.hpp ${folder_name}/*.h)
    file(GLOB CPP_FILES_IN_FOLDER_${folder_name} ${folder_name}/*.cpp ${folder_name}/*.c)
    source_group("Header Files\\${folder_name}" FILES ${H_FILES_IN_FOLDER_${folder_name}})
    source_group("Source Files\\${folder_name}" FILES ${CPP_FILES_IN_FOLDER_${folder_name}})
    set(WSPP_HEADER_FILES ${WSPP_HEADER_FILES} ${H_FILES_IN_FOLDER_${folder_name}})
    set(WSPP_SOURCE_FILES ${WSPP_SOURCE_FILES} ${CPP_FILES_IN_FOLDER_${folder_name}})
endmacro()




#  - Credit: https://github.com/zaphoyd/websocketpp/blob/master/cmake/CMakeHelpers.cmake
macro (include_subdirs PARENT)
    file (GLOB SDIRS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "${PARENT}/*")
    foreach (SUBDIR ${SDIRS})
        if (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${SUBDIR}/CMakeLists.txt")
            add_subdirectory ("${CMAKE_CURRENT_SOURCE_DIR}/${SUBDIR}")
        endif ()
    endforeach ()
endmacro()

