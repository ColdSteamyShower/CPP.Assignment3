EXECUTABLE := SyntaxChecker

SOURCES := ./SyntaxChecker/syntaxChecker.cpp checkerDriver.cpp

INCLUDES := -I ..\include
EXT := exe
CC := g++

syntax:
	$(CC) $(INCLUDES) $(SOURCES) -o $(EXECUTABLE).$(EXT)
