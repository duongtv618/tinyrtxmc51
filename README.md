# tinyrtxmc51

A tiny rtos feature for at89c51

The at89c51 has a internal RAM of 128 bytes from address 0x00 to 0x7f,
each task takes at least 15 bytes to operate so the minimun stack size should be
0x20. Because the iram is tiny so i can only perform such simple task like 
print some preset string through uart, blink port 3 and increase port2 continuous.
With this set-up there is no more iram.

---

After update spinlock, the program iram space for task is reduce so that i cant bring more feature like semaphor or signal to this project. Timer is on development.

# Specs

MCU     : AT89C51<br>
iRAM    : 128 bytes<br>
Flash   : 4KB<br>

# Compiler

[SDCC](https://sdcc.sourceforge.net/)

# Build

I use **make** on **debian** to build this project<br>
In terminal run:<br> 

    make

This will generate a file main.hex in debug foler