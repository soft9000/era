link = ld
cpp = c++
hpp = ../hpp/
lib = ../lib/
logger = ../cpp_logger/
ezlog = ../cpp_ezlog/
zstring = ../cpp_zstring/
opts = -std=c++14 -I$(hpp)

all: logger.run ezlog.run tezlog.run 

# ::::: Target: tezlog.run ::::: 
tezlog.run: tezlog.o libera.a
	$(cpp) $(opts) -o tezlog.run tezlog.o -L$(lib) -lera
	exec "./tezlog.run"

tezlog.o: $(ezlog)tezlog.cpp
	$(cpp) $(opts) -c $(ezlog)tezlog.cpp

# ::::: Target: logger.run ::::: 
# STUDENT / NO-LIB EXAMPLE 
# (Will Become the EzLog Parent)
logger.run: logcon.o LogWriter.o TimeInfo.o TimeStruct.o TimeFormat.o File.o
	$(cpp) $(opts) -o logger.run logcon.o File.o LogWriter.o TimeInfo.o TimeStruct.o TimeFormat.o
	exec "./logger.run"

logcon.o: $(logger)logcon.cpp LogWriter.cpp $(hpp)LogWriter.hpp
	$(cpp) $(opts) -c $(logger)logcon.cpp

LogWriter.o: LogWriter.cpp $(hpp)LogWriter.hpp
	$(cpp) $(opts) -c LogWriter.cpp

# ::::: Target: ezlog.run :::::
# USES libera, as well as LogWriter (above)
ezlog.run: ezcon.o EzLog.o libera.a
	$(cpp) $(opts) -o ezlog.run ezcon.o EzLog.o -L$(lib) -lera
	exec "./ezlog.run"

test_ezlog: $(ezlog)test.cpp EzLog.o LogWriter.o libera.a
	$(cpp) $(opts) $(ezlog)test.cpp -o test_ezlog EzLog.o -L$(lib) -lera
	exec "./test_ezlog"

ezcon.o: $(ezlog)ezcon.cpp $(hpp)EzLog.hpp
	$(cpp) $(opts) -c $(ezlog)ezcon.cpp

EzLog.o: EzLog.cpp $(hpp)EzLog.hpp
	$(cpp) $(opts) -c EzLog.cpp

StatLog.o: StatLog.cpp $(hpp)StatLog.hpp EzLog.o
	$(cpp) $(opts) -c StatLog.cpp

# ::::: Common :::::
Globals.o: $(zstring)Globals.cpp $(zstring)Globals.hpp
	$(cpp) $(opts) -c $(zstring)Globals.cpp

zstring.o: $(zstring)zstring.cpp $(zstring)zstring.hpp
	$(cpp) $(opts) -c $(zstring)zstring.cpp

File.o: File.cpp $(hpp)File.hpp
	$(cpp) $(opts) -c File.cpp

LogSearch.o: LogSearch.cpp $(hpp)LogSearch.hpp
	$(cpp) $(opts) -c LogSearch.cpp

LogEntry.o: LogEntry.cpp $(hpp)LogEntry.hpp
	$(cpp) $(opts) -c LogEntry.cpp

TimeFormat.o: TimeFormat.cpp $(hpp)TimeFormat.hpp
	$(cpp) $(opts) -c TimeFormat.cpp

TimeInfo.o: TimeInfo.cpp $(hpp)TimeInfo.hpp
	$(cpp) $(opts) -c TimeInfo.cpp

TimeStruct.o: TimeStruct.cpp $(hpp)TimeStruct.hpp
	$(cpp) $(opts) -c TimeStruct.cpp

# ::::: GNU-Style Library :::::
libera.a:
	cd ../lib && $(MAKE) 

# sudo apt-get install clang-format
format:
	find .. -type f -name "*.hpp" -exec clang-format -style=Chromium -i "{}" ";"
	find .. -type f -name "*.cpp" -exec clang-format -style=Chromium -i "{}" ";"

clean:
	rm -f *.o
	rm -f *.a
	rm -f *.run
	rm -f *.out
	rm -f *.log
	chmod 666 *.?pp

