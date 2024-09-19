-- Dependencies
add_requires("glfw", {configs = {shared = false}})

target("Test")
    set_kind("binary")
    add_includedirs("../Core/src")
    add_headerfiles("src/*.h")
    add_files("src/*.cpp")
    add_deps("Core")
    add_packages("glfw")
    add_packages("glm")
    add_defines("GLFW_INCLUDE_NONE")