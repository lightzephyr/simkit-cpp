# Refer to: https://eb2.co/blog/2015/06/driving-boost.test-with-cmake/

function(add_boost_test SRC_TEST SRC_FILES)
	get_filename_component(TEST_EXECUTABLE_NAME ${SRC_TEST} NAME_WE)

	add_executable(${TEST_EXECUTABLE_NAME} ${SRC_TEST} ${SRC_FILES})
	target_link_libraries(${TEST_EXECUTABLE_NAME} ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

	file(READ "${SRC_TEST}" SOURCE_FILE_CONTENTS)
	string(REGEX MATCHALL "BOOST_AUTO_TEST_CASE\\( *([A-Za-z_0-9]+) *\\)" FOUND_TESTS ${SOURCE_FILE_CONTENTS})

	foreach(HIT ${FOUND_TESTS})
			string(REGEX REPLACE ".*\\( *([A-Za-z_0-9]+) *\\).*" "\\1" TEST_NAME ${HIT})
			add_test(NAME "${TEST_EXECUTABLE_NAME}.${TEST_NAME}" COMMAND ${TEST_EXECUTABLE_NAME} --run_test=${TEST_NAME} --catch_system_error=yes)
	endforeach()
endfunction()

function(add_boost_test_linked SRC_TEST SRC_FILES DEPENDENCY_LIB)
	get_filename_component(TEST_EXECUTABLE_NAME ${SRC_TEST} NAME_WE)
	add_boost_test(SRC_TEST SRC_FILES)
	target_link_libraries(${TEST_EXECUTABLE_NAME} ${DEPENDENCY_LIB} ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
endfunction()
