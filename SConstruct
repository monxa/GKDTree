#!/usr/bin/env python
import os
import sys

try:
    Import('env')
except:
    env = SConscript("godot-cpp/SConstruct").Clone()


# For reference:
# - CCFLAGS are compilation flags shared between C and C++
# - CFLAGS are for C-specific compilation flags
# - CXXFLAGS are for C++-specific compilation flags
# - CPPFLAGS are for pre-processor flags
# - CPPDEFINES are for pre-processor defines
# - LINKFLAGS are for linking flags

def recursive_glob(sourcedir, suffix):
    result = []
    for root, dirs, files in os.walk(sourcedir):
        for file in files:
            if file.endswith(suffix):
                result.append(os.path.join(root, file))
    return result
# tweak this if you want to use different folders, or more folders, to store your source code in.
env.Append(CPPPATH=["src"])
env.Append(CFLAGS=['-g', '-pg'])
env["symbols_visibility"] = "visible"
sources = ["KDTree.cpp", "GKDTree.cpp", "GKDTree_binder.cpp"]

doc_data = env.GodotCPPDocData("godot-cpp/src/gen/doc_data.gen.cpp", source=Glob("doc_classes/*.xml"))
sources.append(doc_data)

lib_output_path = f'godot_project/addons/gkdtree/bin/libgkdtree{env["SHLIBSUFFIX"]}'

if env["platform"] in ["ios", "android"]:
    lib_output_path = f'godot_project/addons/gkdtree/bin/libgkdtree.{env["platform"]}{env["SHLIBSUFFIX"]}'

library = env.SharedLibrary(
        lib_output_path,
        source=sources,
)

Default(library)
