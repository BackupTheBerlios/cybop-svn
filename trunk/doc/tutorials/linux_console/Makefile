#Binary = simple_tui
Binary = tui_held_in_arrays
#Source = simple_tui.c
Source = tui_held_in_arrays.c
#Object = simple_tui.o
Object = tui_held_in_arrays.o
Compiler = gcc
Libary = lncurses

all:
	$(Compiler) -c $(Source)
	$(Compiler) -o $(Binary) $(Object) -$(Libary)

clean:
	rm -f $(Binary) $(Object) *~
