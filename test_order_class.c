#include <stdio.h>
#include "Order.h"
void main() {

    
    // test basic functions
    // all functions called standarldy and verified by printing
    struct Order ord = Order.new("Staples", 123);
    ord.print_order(&ord);
    ord.close_order(&ord);
    printf("Status of the order is now: %d\n", ord.get_status(&ord));
    printf("I will change the Vendor to Costco and the PO to 567\n");
    ord.change_vendor(&ord, "Costco");
    ord.change_PO(&ord, 567);
    ord.print_order(&ord);
    printf("Vendor is %s\n", ord.get_vendor(&ord));
    printf("PO is %d\n", ord.get_PO(&ord));

}