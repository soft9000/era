
all: libera.a clean

libera.a: ./lib/Makefile ./lib/libera.a
	cd ./lib && $(MAKE) 

# sudo apt-get install clang-format
format:
	find . -type f -name "*.hpp" -exec clang-format -style=Chromium -i "{}" ";"
	find . -type f -name "*.cpp" -exec clang-format -style=Chromium -i "{}" ";"

clean:
	cd ./cpp && $(MAKE) clean
	cd ./lib && $(MAKE) clean
	cd ./cpp_ezlog && $(MAKE) clean
	cd ./cpp_logger && $(MAKE) clean

