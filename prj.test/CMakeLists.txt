enable_testing()

add_executable(test_complex test_complex.cpp)
target_link_libraries(test_complex complex)
add_test(NAME test_complex COMMAND test_complex)

add_executable(test_rational test_rational.cpp)
target_link_libraries(test_rational rational)
add_test(NAME test_rational COMMAND test_rational)

add_executable(test_dynarr test_dynarr.cpp)
target_link_libraries(test_dynarr dynarr)
add_test(NAME test_dynarr COMMAND test_dynarr)

add_executable(test_stackarr test_stackarr.cpp)
target_link_libraries(test_stackarr stackarr)
add_test(NAME test_stackarr COMMAND test_stackarr)

add_executable(test_stacklst test_stacklst.cpp)
target_link_libraries(test_stacklst stacklst)
add_test(NAME test_stacklst COMMAND test_stacklst)

add_executable(test_queuelst test_queuelst.cpp)
target_link_libraries(test_queuelst queuelst)
add_test(NAME test_queuelst COMMAND test_queuelst)

add_executable(test_queuearr test_queuearr.cpp)
target_link_libraries(test_queuearr queuearr)
add_test(NAME test_queuearr COMMAND test_queuearr)

add_executable(test_queuelstpr test_queuelstpr.cpp)
target_link_libraries(test_queuelstpr queuelstpr)
add_test(NAME test_queuelstpr COMMAND test_queuelstpr)

add_executable(test_bitset test_bitset.cpp)
target_link_libraries(test_bitset bitset)
add_test(NAME test_bitset COMMAND test_bitset)

add_executable(test_stackarrt test_stackarrt.cpp)
target_link_libraries(test_stackarrt stackarrt)
add_test(NAME test_stackarrt COMMAND test_stackarrt)
