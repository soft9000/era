link = ld
cpp = c++
hpp = ../hpp/
core = ../cpp/
opts = -std=c++14 -I$(hpp)

OBJS = TimeInfo.o TimeStruct.o TimeFormat.o LogEntry.o \
       File.o LogWriter.o EzLog.o StatLog.o LogSearch.o

all: libera.a clean

LogWriter.o: $(core)LogWriter.cpp $(hpp)LogWriter.hpp
	$(cpp) $(opts) -c $(core)LogWriter.cpp

EzLog.o: $(core)EzLog.cpp $(hpp)EzLog.hpp
	$(cpp) $(opts) -c $(core)EzLog.cpp

StatLog.o: $(core)StatLog.cpp $(hpp)StatLog.hpp EzLog.o
	$(cpp) $(opts) -c $(core)StatLog.cpp

File.o: $(core)File.cpp $(hpp)File.hpp
	$(cpp) $(opts) -c $(core)File.cpp

LogSearch.o: $(core)LogSearch.cpp $(hpp)LogSearch.hpp
	$(cpp) $(opts) -c $(core)LogSearch.cpp

LogEntry.o: $(core)LogEntry.cpp $(hpp)LogEntry.hpp
	$(cpp) $(opts) -c $(core)LogEntry.cpp

TimeFormat.o: $(core)TimeFormat.cpp $(hpp)TimeFormat.hpp
	$(cpp) $(opts) -c $(core)TimeFormat.cpp

TimeInfo.o: $(core)TimeInfo.cpp $(hpp)TimeInfo.hpp
	$(cpp) $(opts) -c $(core)TimeInfo.cpp

TimeStruct.o: $(core)TimeStruct.cpp $(hpp)TimeStruct.hpp
	$(cpp) $(opts) -c $(core)TimeStruct.cpp

# ::::: GNU-Style Library :::::
libera.a: $(OBJS)
	ar rcs libera.a $(OBJS)

clean:
	rm -f $(OBJS)

