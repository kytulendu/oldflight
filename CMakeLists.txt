cmake_minimum_required(VERSION 3.0)

project(flight)

set(NAME flight)

# Set a default build type if none was specified
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
	message("Setting build type to 'RelWithDebInfo' as none was specified.")
	set(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING "Choose the type of build." FORCE)
	# Set the possible values of build type for cmake-gui
	set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release"
		"MinSizeRel" "RelWithDebInfo")
endif()

set(SRCS
	b747.c  
	color.c  
	draw_logo.c  
	f16.c   
	f18.c     
	graph.c   
	main.c   
	meters.c  
	p38.c   
	uflight.c
	c150.c  
	demo.c   
	f15.c        
	f16w.c  
	flight.c  
	irisgl.c  
	maths.c  
	object.c  
	p38w.c
)

set(HEADERS
	bitmap.h  
	demo.h      
	f16_points.h  
	graph.h   
	main.h   
	meters.h   
	p38.h         
	planes.h    
	sgilogo.h
	colors.h  
	f16_defs.h  
	flight.h      
	irisgl.h  
	maths.h  
	objects.h  
	p38_points.h
	uflight.h
	gamestruct.h
)

# Create the executable
add_executable(${NAME} ${SRCS} ${HEADERS})

set_property(TARGET ${NAME} PROPERTY DEBUG_POSTFIX d)

set(OpenGL_GL_PREFERENCE LEGACY)
find_package(OpenGL REQUIRED)
if (OpenGL_OpenGL_FOUND AND OPENGL_GLU_FOUND)
	target_include_directories(flight PUBLIC ${OPENGL_INCLUDE_DIR})
	target_link_libraries (flight ${OPENGL_LIBRARIES})
else()
	message(FATAL_ERROR "opengl and glu not found")
endif()

# Check for external dependency
find_package(GLUT REQUIRED)
if (GLUT_FOUND)
	message(STATUS "add glut dependencies")
	target_include_directories(flight PUBLIC ${GLUT_INCLUDE_DIRS})
	target_link_libraries (flight ${GLUT_LIBRARY})
else()
	message(FATAL_ERROR "glut not found")
endif()

# Set compiler flags
if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
	target_compile_options(${NAME} PRIVATE -Wall PRIVATE -Wno-deprecated-declarations -Wno-switch)
	if(WIN32)
		set(LIBS opengl32 ${LIBS})
	elseif(UNIX AND NOT APPLE)
		set(LIBS GL ${LIBS})
	endif(WIN32)
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	target_compile_options(${NAME} PRIVATE /W4)
	set(LIBS opengl32)
endif()

target_link_libraries(${NAME} ${LIBS}
	m
	glut
)
