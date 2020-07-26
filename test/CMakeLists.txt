include_directories(include)

add_executable(test_${PROJECT_NAME}
   ICSE.cpp)

target_link_libraries(test_${PROJECT_NAME}
   ${PROJECT_NAME})

install(TARGETS test_${PROJECT_NAME}
   RUNTIME DESTINATION ${LIBRARY_INSTALL_DESTINATION}/bin)