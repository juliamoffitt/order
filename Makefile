CC=gcc
CFLAGS=-I.
DEPS = Order.h Item.h
OBJ = Order.o Item.o 

# DEPS is all the .h files
# OBJ is all the .o files

# left side says the .o depends on the .c and the DEPS
# generate the .o by compiling the .c using CC
# -c says to generate the object file
# -o $@ says to put the ouput of the compilation in the file left of :
# the $< is the first item in the DEPS list
# the $^ is all the items in the DEPS list

all : order test_order_class test_item_class
.PHONY : all

order: $(OBJ) order.o
	gcc -o $@ $^ $(CFLAGS)

test_order_class: $(OBJ) test_order_class.o
	gcc -o $@ $^ $(CFLAGS)

test_item_class: $(OBJ) test_item_class.o
	gcc -o $@ $^ $(CFLAGS)

clean: $(OBJ) order test_order_class test_item_class 
	rm $(OBJ) order test_order_class test_item_class
    
# clean needs work :/, needs to remove all .o files
