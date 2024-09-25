-- Dependencies
add_requires("glfw", "glm")

if is_plat("windows") then
    add_defines("PLATFORM_WINDOWS")
elseif is_plat("macosx") then
    add_defines("PLATFORM_MACOS")
end

target("Examples")
    set_kind("binary")
    add_includedirs("../Core/src")
    add_headerfiles("src/**.h")
    add_files("src/**.cpp")
    add_deps("Core")
    add_packages("glfw", "glm")
    add_defines("GLFW_INCLUDE_NONE")
    if is_plat("windows") then
        add_defines("GLFW_EXPOSE_NATIVE_WIN32", "GLFW_NATIVE_INCLUDE_NONE")
    end 