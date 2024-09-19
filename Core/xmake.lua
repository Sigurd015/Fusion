add_requires("glm")

target("Core")
    set_kind("static")
    add_headerfiles("src/*.h")
    add_files("src/*.cpp")
    add_packages("glm")