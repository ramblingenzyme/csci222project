cmake_minimum_required(VERSION 2.6)

project (backend CXX)

set(BACKEND_HEADERS backend.h database_connection.h return_types.h)

set(PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(BACKEND_CODEGEN_DIR "${PROJECT_BINARY_DIR}/codegen")

PREPEND(BACKEND_HEADERS_PATHS ${PROJECT_SOURCE_DIR} ${BACKEND_HEADERS})

CODEGEN_FILES(BACKEND_CODEGEN_SOURCES ${BACKEND_CODEGEN_DIR} ${BACKEND_HEADERS})

add_custom_command(OUTPUT ${BACKEND_CODEGEN_SOURCES}
    COMMAND ${NGREST_BIN_PATH}ngrestcg -i "${PROJECT_SOURCE_DIR}" -o ${BACKEND_CODEGEN_DIR} -t service ${BACKEND_HEADERS}
    DEPENDS ${BACKEND_HEADERS_PATHS}
)

file(GLOB BACKEND_SOURCES ${PROJECT_SOURCE_DIR}/*.cpp)

list(APPEND BACKEND_SOURCES ${BACKEND_CODEGEN_SOURCES})

include_directories(${PROJECT_SOURCE_DIR} $ENV{NGREST_EXT_INCLUDES})

add_library(backend MODULE ${BACKEND_SOURCES})

set_target_properties(backend PROPERTIES PREFIX "")
set_target_properties(backend PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SERVICES_DIR}"
)

target_link_libraries(backend ngrestutils ngrestcommon ngrestjson ngrestengine pqxx $ENV{NGREST_EXT_LIBS})
