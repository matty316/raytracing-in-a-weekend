workspace "Raytracing"
    configurations { "Debug", "Release" }
    platforms { "Win64" }

project "Raytracing"
    kind "ConsoleApp"
    language "C++"
    targetdir "bin/%{cfg.buildcfg}"

    files { "include/**.h", "src/**.c", "src/**.cpp" }

    includedirs { "include" }
    includedirs { "src" }

    filter "configurations:Debug"
    defines { "DEBUG" }
    symbols "On"

    filter "configurations:Release"
    defines { "NDEBUG" }
    optimize "On"