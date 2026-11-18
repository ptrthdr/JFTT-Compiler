CXX ?= c++
CPPFLAGS ?=
CXXFLAGS ?= -O2 -Wall -Wextra -Wpedantic
LDFLAGS ?=
LDLIBS ?=

.PHONY: all clean
.DELETE_ON_ERROR:

all: kompilator

kompilator: build/main.o
	$(CXX) $(LDFLAGS) $^ $(LDLIBS) -o $@

build/main.o: src/main.cpp | build
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -std=c++17 -MMD -MP -c $< -o $@

build:
	mkdir -p $@

clean:
	$(RM) build/main.o build/main.d kompilator

-include build/main.d
