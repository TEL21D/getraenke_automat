SOURCES := $(wildcard *.cpp) # searches for all *.cpp files
TARGET := Automat.exe		# name of the output program

all: $(TARGET)

$(TARGET): $(SOURCES)
	g++ -std=c++17 -o $(TARGET) $^

run: $(TARGET)
	./$(TARGET)


.PHONY: clean

clean:
	del /q *.exe
