TARGET = target
SRCS = main.cpp util.cpp
OBJS = $(SRCS:.cpp=.o)

CXXFLAGS = -std=c++2a -Wall -Wextra --pedantic-errors

INSTALL = /usr/bin/install -c
FORMATTER = clang-format -i
BINDIR = /bin

all: $(TARGET)
check: all
	@if test -f not_existence; then \
		echo "Error: It is assumed that file 'not_existence' DOES NOT exist." ;\
		false ;\
	fi
	./$(TARGET) -t
clean:
	- rm -f $(TARGET) $(OBJS)

$(TARGET): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LIBS)
main.o:  util.h
util.o:  util.h

.PHONY: all check clean format
