CXX=g++
CXXFLAGS=-Wall -O3

all: slowstd slowbit

clean:
	rm -f slowbuffer.o slowstd.o slowbit.o slowstd slowbit

slowstd: slowbuffer.o slowstd.o
	$(CXX) $(CXXFLAGS) -o $@ $^

slowbit: slowbuffer.o slowbit.o
	$(CXX) $(CXXFLAGS) -o $@ $^

slowbuffer.o: slowbuffer.cpp slowfile.h
	$(CXX) $(CXXFLAGS) -c -o $@ slowbuffer.cpp

slowbit.o: slowfile.cpp slowfile.h
	$(CXX) $(CXXFLAGS) -D BITMAX -c -o $@ slowfile.cpp

slowstd.o: slowfile.cpp slowfile.h
	$(CXX) $(CXXFLAGS) -D STDMAX -c -o $@ slowfile.cpp
