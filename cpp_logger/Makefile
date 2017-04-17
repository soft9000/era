link = ld
cpp = c++
hpp = ../hpp/
lib = ../lib/
logger = ../cpp_logger/
zstring = ../cpp_zstring/
opts = -std=c++14 -I$(hpp)

all: ezlog.run tlogwriter.run 

# ::::: Target: tlogwriter.run ::::: 
tlogwriter.run: tlogwriter.o libera.a
	$(cpp) $(opts) -o tlogwriter.run tlogwriter.o -L$(lib) -lera
	exec "./tlogwriter.run"

ezlog.run: logcon.o libera.a
	$(cpp) $(opts) -o ezlog.run logcon.o -L$(lib) -lera
	exec "./ezlog.run"

ezlog: logcon.o libera.a
	$(cpp) $(opts) -o ezlog logcon.o -L$(lib) -lera
	ls -al ezlog

tlogwriter.o: $(logger)tlogwriter.cpp
	$(cpp) $(opts) -c $(logger)tlogwriter.cpp

logcon.o: $(logger)logcon.cpp $(hpp)LogWriter.hpp
	$(cpp) $(opts) -c $(logger)logcon.cpp

# ::::: GNU-Style Library :::::
libera.a:
	cd ../lib && $(MAKE) 

# sudo apt-get install clang-format
format:
	find . -type f -name "*.hpp" -exec clang-format -style=Chromium -i "{}" ";"
	find . -type f -name "*.cpp" -exec clang-format -style=Chromium -i "{}" ";"

clean:
	rm -f *.o
	rm -f *.a
	rm -f *.run
	rm -f *.out
	rm -f *.log
	chmod 666 *.?pp

