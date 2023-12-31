set(TARGET_NAME qdbusxml2cpp-fix)
set(BIN_NAME ${TARGET_NAME}${DTK_VERSION_MAJOR})

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS DBus)

add_executable(${BIN_NAME}
  qdbusxml2cpp.cpp
)

target_link_libraries(
  ${BIN_NAME} PRIVATE
  Qt${QT_VERSION_MAJOR}::DBus
  Qt${QT_VERSION_MAJOR}::Core
  Qt${QT_VERSION_MAJOR}::DBusPrivate
)

set_target_properties(
  ${BIN_NAME} PROPERTIES
  OUTPUT_NAME ${TARGET_NAME}
  EXPORT_NAME Xml2Cpp
)

install(
  TARGETS ${BIN_NAME}
  EXPORT Dtk${DTK_VERSION_MAJOR}ToolsTargets
  DESTINATION ${TOOL_INSTALL_DIR}
)

install(
  EXPORT Dtk${DTK_VERSION_MAJOR}ToolsTargets
  FILE Dtk${DTK_VERSION_MAJOR}ToolsTargets.cmake
  NAMESPACE Dtk${DTK_VERSION_MAJOR}::
  DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/Dtk${DTK_VERSION_MAJOR}Tools"
)
