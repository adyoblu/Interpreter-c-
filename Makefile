all: interpreter

interpreter:
	bison -d project.y
	flex project.l
	g++ -Wno-register project.tab.c lex.yy.c -o project
	./project < in.txt