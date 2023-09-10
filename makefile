TARGET = main
CC = sdcc

$(TARGET): 
	$(CC) main.c
	packihx main.ihx > main.hex

clean:
	rm -rf main main.lk main.map main.rel main.sym main.asm main.hex main.lst main.mem main.rst main.ihx
