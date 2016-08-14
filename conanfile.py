from conans import ConanFile, CMake

class GameOfLifeCPP(ConanFile):
    name = "game-of-life"
    version = "0.1"
    requires = "spdlog/0.9.0@memsharded/stable"
    generators = "cmake"
    settings = "os", "compiler", "build_type", "arch"
    exports = "conanfile.py", "CMakeLists.txt", "game-of-life/*" , "tests/*"
    url = "https://github.com/jgsogo/game-of-life"

    def imports(self):
        self.copy("*.dll", dst="bin", src="bin") # From bin to bin
        self.copy("*.dylib*", dst="bin", src="lib") # From lib to bin
      
    def build(self):
        cmake = CMake(self.settings)
        self.run('cmake %s %s' % (self.conanfile_directory, cmake.command_line))
        self.run("cmake --build . %s" % cmake.build_config)

    def package(self):
        self.copy("*.h", dst="include")
        self.copy("*.lib", dst="lib", src="lib")
        self.copy("*.a", dst="lib", src="lib")

    def package_info(self):
        #self.cpp_info.libs = ["game-of-life"]  # Do not generates .lib
        pass
