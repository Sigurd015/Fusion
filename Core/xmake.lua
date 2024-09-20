VULKAN_SDK = os.getenv("VULKAN_SDK")

if not VULKAN_SDK then
    print("VULKAN_SDK is not installed, https://vulkan.lunarg.com/sdk/home")
    os.exit(1)
end

add_requires("glm", "glfw")

target("Core")
    set_kind("static")
    set_pcheader("src/pch.h")
    add_headerfiles("src/**.h")
    add_files("src/**.cpp")
    add_packages("glm", "glfw")
    add_includedirs(VULKAN_SDK .. "/Include")
    add_linkdirs(VULKAN_SDK .. "/Lib")
    add_links("vulkan-1")