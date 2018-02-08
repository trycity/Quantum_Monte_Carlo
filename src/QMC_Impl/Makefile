# QMC Impl makefile

include ../../Makefile.common


DIRECTORY = QMC_Impl
CXXFLAGS += -I../utils
CXXFLAGS += -I../initialization
CXXFLAGS += -I../Metropolis_Walker


all:
	$(CXX) $(CXXFLAGS) -c *.cpp -o $(DIRECTORY).o


clean:
	rm -rf *.o *.d
