-- Set project name
set_project("Template")

-- Set language version
set_languages("cxx20")

-- Specify toolchains for different platforms
if is_plat("windows") then
    set_toolchains("msvc")
    set_config("vs", "2022")
elseif is_plat("macosx") then
    set_toolchains("clang")
elseif is_plat("linux") then
    set_toolchains("gcc")
end

-- Custom build rules
add_rules("mode.Debug")
add_rules("mode.Release")
add_rules("mode.Dist")

rule("mode.Debug")
    on_config(function (target)
        if is_mode("Debug") then
            if not target:get("symbols") then
                target:set("symbols", "debug")
            end

            if not target:get("optimize") then
                target:set("optimize", "none")
            end

            if is_plat("windows") then
                target:add("cxflags", "/MDd")
            elseif is_plat("macosx") or is_plat("linux") then
                target:add("ldflags", "-static")
            end

            target:add("defines", "DEBUG")
        end
    end)
rule_end()

rule("mode.Release")
    on_config(function (target)
        if is_mode("Release") then
            if not target:get("symbols") then
                target:set("symbols", "debug")
            end

            if not target:get("optimize") then
                target:set("optimize", "fastest")
            end

            if is_plat("windows") then
                target:add("cxflags", "/MD")
            elseif is_plat("macosx") or is_plat("linux") then
                target:add("ldflags", "-static")
            end

            target:add("defines", "RELEASE")
        end
    end)
rule_end()

rule("mode.Dist")
    on_config(function (target)
        if is_mode("Dist") then
            if not target:get("symbols") then
                target:set("symbols", "hidden")
            end

            if not target:get("optimize") then
                target:set("optimize", "fastest")
            end

            if is_plat("windows") then
                target:add("cxflags", "/MT")
            elseif is_plat("macosx") or is_plat("linux") then
                target:add("ldflags", "-static")
            end

            target:add("defines", "DIST")
        end
    end)
rule_end()

-- Set default build mode to 'Dist'
set_defaultmode("Dist")

-- Windows specific configuration
if is_plat("windows") then
    add_cxxflags("/EHsc")
    add_cxxflags("/Zc:preprocessor")
    add_cxxflags("/Zc:__cplusplus")
end

add_rules("mode.Debug", "mode.Release", "mode.Dist")

includes("Core")
includes("App")