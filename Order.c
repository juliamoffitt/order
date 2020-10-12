#include <stdio.h>
#include <stdlib.h>
#include "Order.h"
#include "ItemList.h"


/*
    Order class
    
    Fields: char* vendor, int PO, int open, ItemList* list
    Functions:
        static struct Order* new_order(char* vendor, int PO)
        void delete_order(struct Order *this) 
        void print_order(struct Order *this)   
*/


// will likely need to update/changes these functions. Will focus on main functions for now
// void close_order(struct Order *this) {
//    this->open = 0;
//}
// int get_status(struct Order *this) {
//    if (this->open) return 1;
//    else return 0;
//}
// char* get_vendor(struct Order *this) {
//    if (this->vendor!='\0') return this->vendor;
//    else return "error";
//}
// int get_PO(struct Order *this) {
//    if (this->PO!='\0') return this->PO;
//    else return 0;
//}
// int change_vendor(struct Order *this, char* new_vendor) {
//    if (new_vendor == '\0') return -1;
//    else {
//        this->vendor = new_vendor;
//        return 0;
//    }
//}
// int change_PO(struct Order *this, int new_PO) {
//    if (new_PO < 1) return -1;
//    else {
//        this->PO = new_PO;
//        return 0;
//    }
//}

/*
 * Creates new Order
 * Parameters: vendor, PO
 * Returns: pointer to Order
*/
struct Order* new_order(char* vendor, int PO) { //need to add part where we actually make the list
    struct Order* new_order = malloc(sizeof(Order));
    if(!new_order) return NULL;
    new_order->vendor = vendor;
    new_order->PO = PO;
    new_order->open = 1;
    return new_order;
}

/*
 * Deletes Order
 * Parameters: Order
 * Returns: void
*/
void delete_order(struct Order *this) {
    struct ItemList* test = this->list;
    test->delete_list(test);
    free(this);
    this = NULL;
}


/*
 * Prints order to stdout
 * Parameters: Order
 * Returns: void
*/
void print_order(struct Order *this) {
    printf("Vendor is %s\n", this->vendor);
    printf("PO # is %d\n", this->PO);
    //(get_status(this)) ? (printf("Status is open\n")) : (printf("Status is closed\n"));
}


static struct Order new(char* vendor, int PO, int open, struct ItemList* list) {
    return (struct Order){.vendor=vendor,
                          .PO=PO,
                          .open=open,
                          .list=list,
//                          .close_order=&close_order, 
//                          .get_status=&get_status,
//                          .print_order=&print_order, 
//                          .get_vendor=&get_vendor,
//                          .get_PO=&get_PO, 
//                          .change_vendor=&change_vendor,
//                          .change_PO=&change_PO,
                          .new_order=&new_order,
                          .delete_order=&delete_order
    };
}
const struct OrderClass Order={.new=&new};