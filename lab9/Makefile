CXX = g++
CXXFLAGS = -Wall -Wextra -g

.PHONY: build run clean

build: basic ast

basic: basic.o
	$(CXX) $^ -o $@

ast: ast.o
	$(CXX) $^ -o $@

basic.o: basic.cpp BinaryTree.h
ast.o: ast.cpp BinaryTree.h ExpressionNode.h

run-basic: basic
	valgrind --leak-check=full ./basic

run-ast: ast
	./ast

clean:
	rm -rf *~ *.o basic ast
