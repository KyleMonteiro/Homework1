CPP=g++
CPPFLAGS=-Iincludes
SOURCEDIR=src
SOURCES=$(shell ls $(SOURCEDIR))
OBJECTDIR=obj
BINDIR=bin
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=bin/patients

all: $(EXECUTABLE)
	g++ -o $(EXECUTABLE) $(SOURCEDIR)/PatientHW.cpp

.PHONY : clean
clean:
	if [ -d $(BINDIR) ]; then rm -rfv $(BINDIR); fi; if [ -d $(OBJECTDIR) ]; then rm -rfv $(OBJECTDIR); fi;

.PHONY : run
run: $(EXECUTABLE)
	$(EXECUTABLE) arg1 arg2
