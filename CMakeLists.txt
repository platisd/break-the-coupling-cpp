cmake_minimum_required(VERSION 3.13)
project(BreakTheDependency)

set(CMAKE_CXX_STANDARD 20)
add_compile_options(
        -Wcast-align
        -Wpedantic
        -Wcast-qual
        -Wconversion
        -Wctor-dtor-privacy
        -Wnon-virtual-dtor
        -Wmissing-include-dirs
        -Wdisabled-optimization
        -Winit-self
        -Wnon-virtual-dtor
        -Wold-style-cast
        -Woverloaded-virtual
        -Wparentheses
        -Wredundant-decls
        -Wshadow
        -Wsign-promo
        -Wstrict-aliasing
        -Wall
        -Wextra
        -Werror
)

add_subdirectory(external)
add_subdirectory(src)

enable_testing()
add_subdirectory(di_polymorphism)
add_subdirectory(di_template)
add_subdirectory(di_factory)
add_subdirectory(link_switch)
add_subdirectory(link_switch_template)
