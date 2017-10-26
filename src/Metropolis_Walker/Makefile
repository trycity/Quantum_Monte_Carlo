# metropolis walker makefile

include ../../Makefile.common

CXXFLAGS += -I../utils
CXXFLAGS += -I../initialization
DIRECTORY = Metropolis_Walker


all:
	$(CXX) $(CXXFLAGS) -c *.h

test: all
#	$(CXX) $(CXXFLAGS) -c -I../$(DIRECTORY) test/*.cpp
#	$(CXX) $(CXXFLAGS) *.o -o test/$(DIRECTORY)

clean:
	rm -rf *.o *.d
	
