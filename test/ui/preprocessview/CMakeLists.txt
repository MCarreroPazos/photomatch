set(test_filename tst_preprocessview.cpp)
get_filename_component(test_name ${test_filename} NAME_WE)

include_directories(${CMAKE_SOURCE_DIR}/src)

set(test_kind test)
set(test_KIND TEST)

set(the_target "${test_kind}_${test_name}")
add_executable(${the_target}
    ${test_filename}
    ${CMAKE_SOURCE_DIR}/src/photomatch/ui/PreprocessView.cpp
    ${CMAKE_SOURCE_DIR}/src/photomatch/ui/PreprocessView.h
    ${CMAKE_SOURCE_DIR}/src/photomatch/ui/Preprocess.h
    ${CMAKE_SOURCE_DIR}/src/photomatch/ui/mvp.h
    )

target_link_libraries(${the_target} PRIVATE
                      tl_core
                      libcore
                      libwidgets
                      Qt5::Core
                      Qt5::Widgets
                      Qt5::Test
                      Qt5::Concurrent
                      ${OpenCV_LIBS})

target_link_libraries(${the_target} PRIVATE ${Boost_FILESYSTEM_LIBRARY} ${Boost_SYSTEM_LIBRARY})


set_property(TARGET ${the_target} PROPERTY FOLDER "test/preprocess_view")

set_target_properties(${the_target} PROPERTIES
  OUTPUT_NAME ${the_target}
  PROJECT_LABEL "(${test_KIND}) ${test_name}")

if(ENABLE_SOLUTION_FOLDERS)
  set_target_properties(${the_target} PROPERTIES FOLDER "test/preprocess_view")
endif()

add_test(NAME ${the_target} COMMAND $<TARGET_FILE:${the_target}>)
