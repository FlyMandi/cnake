---@diagnostic disable: undefined-global, undefined-field

include "River"

workspace("Cnake")
    configurations({ "Debug", "Release" })
    platforms({ "Win64" })
    location("build")

    project("Cnake")
        links("River")
        language("C++")
        cppdialect("C++20")
        targetdir("bin/%{cfg.buildcfg}")
        includedirs({ "./include/", "./river/include/", "./river/vendor/glfw-3.4-win64/include/", "%{VULKAN_SDK}/Include/" })
        syslibdirs({ "%{VULKAN_SDK}/Lib/", "./river/vendor/glfw-3.4-win64/lib-vc2022/" })
        files({ "include/**.h", "src/**.c", "include/**.hpp", "src/**.cpp" })

filter("configurations:Debug")
    kind("ConsoleApp")
    defines{"DEBUG"}
    staticruntime("off")
    runtime("Debug")
    symbols("On")
    ignoredefaultlibraries({ "MSVCRT" })

filter("configurations:Release")
    kind("WindowedApp")
    staticruntime("off")
    runtime("Release")
    symbols("Off")
    optimize("Speed")

filter("platforms:Win64")
    system("Windows")
    architecture("x86_64")

newaction({
    trigger = "clean",
    description = "clean the software",
    execute = function()
        print("clean the build...")
        os.rmdir("./build/")
        os.rmdir("./bin/")
        os.remove("BuildRules.xml")
        os.remove("BuildRules.props")
        os.remove("BuildRules.targets")
        print("done.")
    end,
})
