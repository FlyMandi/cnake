---@diagnostic disable: undefined-global, undefined-field
VULKAN_SDK = os.getenv("VULKAN_SDK")

workspace("Cnake")
    configurations({ "Debug", "Release" })
    platforms({ "Win64" })
    location("build")

project("Cnake")
    kind("WindowedApp")
    language("C++")
    cppdialect("C++20")
    targetdir("bin/%{cfg.buildcfg}")
    includedirs({ "./river/include/", "./river/vendor/glfw-3.4-win64/include/", "%{VULKAN_SDK}/Include/" })
    syslibdirs({ "%{VULKAN_SDK}/Lib/", "./river/vendor/glfw-3.4-win64/lib-vc2022/" })
    files({ "**.h", "**.c", "**.hpp", "**.cpp" })

filter("configurations:Debug")
    defines({ "DEBUG" })
    symbols("On")
    ignoredefaultlibraries({ "MSVCRT" })

filter("configurations:Release")
    defines({ "NDEBUG" })
    optimize("On")

filter("platforms:Win64")
    system("Windows")
    architecture("x86_64")

filter("action:vs*")
    linkoptions({ "vulkan-1.lib", "glfw3.lib" })

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
