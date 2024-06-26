target=parser
objs=ast.o parser.o printer.o tokens.o main.o 
CC=g++
CXXFLAGS += -std=c++17

$(target):${objs}
	$(CC) -o $(target)  $(objs) 
%.o:%.cpp
	$(CC) -c $< $(CXXFLAGS)
.PHONY: clean
clean:
	rm $(objs) parser.cpp parser.hpp tokens.cpp parser -f
