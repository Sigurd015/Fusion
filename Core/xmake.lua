VULKAN_SDK = os.getenv("VULKAN_SDK")

if not VULKAN_SDK then
    print("VULKAN_SDK is not installed, https://vulkan.lunarg.com/sdk/home")
    os.exit(1)
end

if is_plat("windows") then
    add_defines("FUSION_PLATFORM_WINDOWS")
elseif is_plat("macosx") then
    add_defines("FUSION_PLATFORM_MACOS")
elseif is_plat("linux") then
    add_defines("FUSION_PLATFORM_LINUX")
end

if is_mode("Debug") then
    add_defines("FUSION_DEBUG")
elseif is_mode("Release") then
    add_defines("FUSION_RELEASE")
elseif is_mode("Dist") then
    add_defines("FUSION_DIST")
end

add_requires("glm", "glfw")

target("Core")
    set_kind("static")
    set_pcxxheader("src/pch.h")
    add_headerfiles("src/**.h")
    add_files("src/**.cpp")
    add_packages("glm", "glfw")
    add_includedirs(VULKAN_SDK .. "/Include", "src/RHI")
    add_linkdirs(VULKAN_SDK .. "/Lib")
    add_links("vulkan-1")
    
    add_defines("GLFW_INCLUDE_NONE", "GLM_FORCE_DEPTH_ZERO_TO_ONE")

    if is_plat("windows") then
        add_defines("GLFW_EXPOSE_NATIVE_WIN32", "GLFW_NATIVE_INCLUDE_NONE")
    end 