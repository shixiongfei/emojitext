solution ( "emoji-text" )
  configurations { "Release", "Debug" }
  platforms { "x64" }

  if _ACTION == "clean" then
    os.rmdir(".vs")
    os.rmdir("bin")
    os.rmdir("temp")
    os.remove("emoji-text.VC.db")
    os.remove("emoji-text.sln")
    os.remove("emoji-text.vcxproj")
    os.remove("emoji-text.vcxproj.filters")
    os.remove("emoji-text.vcxproj.user")
    os.remove("emoji-text.make")
    os.remove("Makefile")
    return
  end

  -- A project defines one build target
  project ( "emoji-text" )
  kind ( "ConsoleApp" )
  language ( "C++" )
  targetname ("emoji-text")
  includedirs { "./3rd/utf8" }
  files { "./src/*.h", "./src/*.cpp",
          "./3rd/utf8/utf8.h", "./3rd/utf8/utf8.c" }
  defines { "_UNICODE" }
  staticruntime "On"

  configuration ( "Release" )
    optimize "On"
    objdir ( "./temp" )
    targetdir ( "./bin" )
    defines { "NDEBUG", "_NDEBUG" }

  configuration ( "Debug" )
    symbols "On"
    objdir ( "./temp" )
    targetdir ( "./bin" )
    defines { "DEBUG", "_DEBUG" }

  configuration ( "vs*" )
    defines { "WIN32", "_WIN32", "_WINDOWS",
              "_CRT_SECURE_NO_WARNINGS", "_CRT_SECURE_NO_DEPRECATE",
              "_CRT_NONSTDC_NO_DEPRECATE", "_WINSOCK_DEPRECATED_NO_WARNINGS" }

  configuration ( "gmake" )
    warnings  "Default" --"Extra"
    defines { "LINUX_OR_MACOSX" }
    links { "iconv" }

  configuration { "gmake", "macosx" }
    defines { "__APPLE__", "__MACH__", "__MRC__", "macintosh" }

  configuration { "gmake", "linux" }
    defines { "__linux__" }
