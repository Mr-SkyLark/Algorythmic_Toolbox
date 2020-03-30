project(Weak3)
#-------------------------------------------------------------------------------
file(GLOB_RECURSE SOURCES "${CMAKE_SOURCE_DIR}/*.cpp")
#-------------------------------------------------------------------------------
foreach(file_path ${SOURCES})
  string( REPLACE ".cpp" "" new_name ${file_path} )
  get_filename_component(filename "${new_name}" NAME)
  add_executable( "${PROJECT_NAME}_${filename}" ${file_path} )
endforeach()
#-------------------------------------------------------------------------------
