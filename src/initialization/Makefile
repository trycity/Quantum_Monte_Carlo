# initialization makefile

include ../../Makefile.common


DIRECTORY = initialization
DEPS = utils


all:
	$(CXX) $(CXXFLAGS) -c -I../$(DEPS)/ *.cpp -o $(DIRECTORY).o

test: all
#	$(CXX) $(CXXFLAGS) -c -I../$(DEPS)/QMC_Utilities.cpp -I../$(DIRECTORY)/ test/*.cpp
#	$(CXX) $(CXXFLAGS) *.o -o test/$(DIRECTORY)

clean:
	rm -rf *.o *.d
#	rm -rf test/$(DIRECTORY)
	
