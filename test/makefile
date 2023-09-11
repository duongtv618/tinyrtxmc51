CC = sdcc
CFLAGS = -I . -I ../rtx/ -I ../uart/
SRC = \
../rtx/os.c\
../uart/uart.c

OBJ = $(SRC:.c=.rel)

main : main.c makefile $(OBJ)
	$(CC) $(CFLAGS) -o ../debug/ main.c $(OBJ)
	packihx ../debug/main.ihx > ../debug/main.hex

%.rel : %.c makefile 
	$(CC) -c $(CFLAGS) -o $@  $<

clean:
	rm -rf ../debug/*.*
	rm -rf ../*.asm ../*.ihx ../*.lk ../*.lst ../*.map ../*.rel ../*.mem ../*.rst ../*.sym ../*.hex
	rm -rf ../rtx/*.asm ../rtx/*.lst ../rtx/*.rel ../rtx/*.rst ../rtx/*.sym
	rm -rf ../uart/*.asm ../uart/*.lst ../uart/*.rel ../uart/*.rst ../uart/*.sym

