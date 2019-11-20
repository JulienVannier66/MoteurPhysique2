cmake_minimum_required(VERSION 3.12)

set(SOURCE_FOLDER ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(INCLUDE_FOLDER ${CMAKE_CURRENT_SOURCE_DIR}/include)

#Include the whole include directory for this directory
include_directories(${INCLUDE_FOLDER})

#Source files
set(SOURCES ${SOURCE_FOLDER}/main.cpp
			${SOURCE_FOLDER}/Vecteur3D.cpp
			${SOURCE_FOLDER}/Matrix3.cpp
			${SOURCE_FOLDER}/RigidBody.cpp
	        ${SOURCE_FOLDER}/Matrix4.cpp
			${SOURCE_FOLDER}/Quaternion.cpp
			${SOURCE_FOLDER}/RessortGenerator.cpp)

#Headers files (for IntelliSense)
set(HEADERS ${INCLUDE_FOLDER}/main.hpp
			${INCLUDE_FOLDER}/Vecteur3D.hpp
			${INCLUDE_FOLDER}/Test_Vecteur3D.hpp
			${INCLUDE_FOLDER}/Assert.hpp
			${INCLUDE_FOLDER}/Debug.hpp
			${INCLUDE_FOLDER}/Matrix3.hpp
			${INCLUDE_FOLDER}/Test_Matrix3.hpp
			${INCLUDE_FOLDER}/RigidBody.hpp
	        ${INCLUDE_FOLDER}/Matrix4.hpp
	        ${INCLUDE_FOLDER}/Quaternion.hpp
			${INCLUDE_FOLDER}/RessortGenerator.hpp)
#Main exec
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})