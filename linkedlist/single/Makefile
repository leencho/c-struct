run: test.png
	xdg-open test.png
test.png: hello.dot
	dot -Tpng -o test.png hello.dot

hello.dot:main
	./main


main: main.c list.c 
	gcc -o main main.c list.c 

clean:
	rm -f main hello.dot test.png 
