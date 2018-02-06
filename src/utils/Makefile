# utilities makefile

include ../../Makefile.common

DIRECTORY = utils

ODIR = obj

OBJS = $(DIRECTORY).o


all: 
	$(CXX) -c $(CXXFLAGS) *.cpp -o $(OBJS) 
	mv *.o $(ODIR)/

	
clean:
	rm -rf *.d *.o
	

