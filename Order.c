#include <stdio.h>
#include "Order.h"
static void close_order(struct Order *this) {
    this->open = 0;
}
static int get_status(struct Order *this) {
    if (this->open) return 1;
    else return 0;
}
static char* get_vendor(struct Order *this) {
    if (this->vendor!='\0') return this->vendor;
    else return "error";
}
static int get_PO(struct Order *this) {
    if (this->PO!='\0') return this->PO;
    else return 0;
}
static int change_vendor(struct Order *this, char* new_vendor) {
    if (new_vendor == '\0') return -1;
    else {
        this->vendor = new_vendor;
        return 0;
    }
}
static int change_PO(struct Order *this, int new_PO) {
    if (new_PO < 1) return -1;
    else {
        this->PO = new_PO;
        return 0;
    }
}

// needs error handling
static void print_order(struct Order *this) {
    printf("Vendor is %s\n", this->vendor);
    printf("PO # is %d\n", this->PO);
    (get_status(this)) ? (printf("Status is open\n")) : (printf("Status is closed\n"));
}
static struct Order new(char* vendor, int PO) {
    return (struct Order){.vendor=vendor, .PO=PO, .open=1, .close_order=&close_order, 
                          .get_status=&get_status, .print_order=&print_order, 
                          .get_vendor=&get_vendor, .get_PO=&get_PO, 
                          .change_vendor=&change_vendor, .change_PO=&change_PO};
}
const struct OrderClass Order={.new=&new};