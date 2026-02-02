---@diagnostic disable: undefined-global, undefined-field
VULKAN_SDK = os.getenv("VULKAN_SDK")

workspace("Cnake")
    configurations({ "Debug", "Release" })
    platforms({ "Win64" })
    location("build")

    project("River")
        kind("StaticLib")
        links{ "glfw3", "vulkan-1" }
        language("C++")
        cppdialect("C++20")
        targetdir("bin/%{cfg.buildcfg}/%{prj.name}")
        includedirs({ "./river/include/", "./river/vendor/glfw-3.4-win64/include/", "%{VULKAN_SDK}/Include/" })
        syslibdirs({ "%{VULKAN_SDK}/Lib/", "./river/vendor/glfw-3.4-win64/lib-vc2022/" })
        files({ "river/**.h", "river/**.c", "river/**.hpp", "river/**.cpp" })

    project("Cnake")
        kind("WindowedApp")
        links("River")
        language("C++")
        cppdialect("C++20")
        targetdir("bin/%{cfg.buildcfg}/%{prj.name}")
        includedirs({ "./river/include/", "./river/vendor/glfw-3.4-win64/include/", "%{VULKAN_SDK}/Include/" })
        syslibdirs({ "%{VULKAN_SDK}/Lib/", "./river/vendor/glfw-3.4-win64/lib-vc2022/" })
        files({ "src/**.h", "src/**.c", "src/**.hpp", "src/**.cpp" })

    filter("configurations:Debug")
        defines("DEBUG")
        symbols("On")
        runtime("Debug")
        ignoredefaultlibraries({ "MSVCRT" })

    filter("configurations:Release")
        defines("NDEBUG")
        runtime("Release")
        optimize("On")

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
