-- Dependencies
add_requires("glfw", "glm")

target("Examples")
    set_kind("binary")
    add_includedirs("../Core/src")
    add_headerfiles("src/**.h")
    add_files("src/**.cpp")
    add_deps("Core")
    add_packages("glfw", "glm")
    add_defines("GLFW_INCLUDE_NONE")