#include <stdio.h>
#include <stdlib.h>
#include "Order.h"
#include "Item.h"
#include "ItemList.h"

void get_line(char* line, int size){
    if(fgets(line, size, stdin)) {
        return;
    }
}

//
//void new_order(char* line, int size) {
//    char* vendor;
//    char* PO;
//    PO = line;
//    printf("Vendor? ");
//    get_line(line, size);
//    vendor = line;
//    
//}

void main(){
    
//    struct Order first = Order.new("staples", 123);
//    if (first.get_status(&first) == 1) printf("Order is open. I will now close the order\n");
//    first.close_order(&first);
//    printf("first.open value is %d\n", first.open);
//    first.print_order(&first);
}


