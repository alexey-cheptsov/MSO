appname := Exercise1

CXX := g++
CXXFLAGS := -Wall -g -std=c++11

srcfiles := $(shell find ./src/ -maxdepth 3 -name "*.cpp")
objects  := $(patsubst %.cpp, %.o, $(srcfiles))

all: $(appname)

$(appname): $(objects)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $(appname) $(objects) $(LDLIBS)
	rm ./src/*.o .depend
	find . -type f -name '*.o' -delete

depend: .depend

.depend: $(srcfiles)
	rm -f ./.depend
	$(CXX) $(CXXFLAGS) -MM $^>>./.depend;

clean:
	rm -f $(objects) $(appname) .depend

dist-clean: clean
	rm -f *~ .depend

include .depend