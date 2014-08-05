.PHONY: all clean

all: test

test:
	clang rgb2gray.c test.c -o test -lopencv_core -lopencv_highgui -lopencv_imgproc

clean:
	rm -f test
