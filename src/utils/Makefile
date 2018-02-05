# utilities makefile

include ../../Makefile.common

DIRECTORY = utils

CXXFLAGS += -c

all:
	$(CXX) $(CXXFLAGS) *.cpp -o $(DIRECTORY).o
	
test: all
#	$(CXX) $(CXXFLAGS) -c -I../$(DIRECTORY) tests/*.cpp
#	$(CXX) $(CXXFLAGS) *.o -o tests/$(DIRECTORY)
	
clean:
	rm -rf *.o *.d
   

