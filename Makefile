main:
	cd src/; flex ruby.lex; bison ruby.y
	g++ main.cpp