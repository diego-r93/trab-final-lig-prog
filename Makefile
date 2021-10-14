#!/usr/bin/make -f

TARGET = calculadora_matrizes
# TARGET = test

CXX = g++

RM = rm -f

ifeq ($(compiler), CLANG)
CXX = clang++
endif

LD = $(CXX)

CXXFLAGS = -Wall -std=c++11
LDFLAGS = -Wall 
INCLUDE = -I/usr/include/python3.8/ -lpython3.8

ifeq ($(dialect), C++14)
CXXFLAGS = -Wall -std=c++14
endif

ifeq ($(dialect), C++17)
CXXFLAGS = -Wall -std=c++17
endif

OBJS = main.o pyClass.o

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< $(INCLUDE)

$(TARGET): $(OBJS)
	$(LD) $(LDFLAGS) -o $@ $^ $(INCLUDE)

.PHONY: all clean

all: $(TARGET)

clean:
	$(RM) *.o $(TARGET)