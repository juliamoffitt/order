#include <stdio.h>
#include <stdlib.h>
#include "Item.h"

/*
    Item class
    
    Fields: char* name, int price, int quantity, Item* next
    Functions:
        Item* create_item(char* name, int price, int quantity)
        void free_item(struct Item *this)
        Item* get_next(struct Item* this)
        int is_item(struct Item* this, char* name)
        void print_item(struct Item *this)
        
    * This serves as the "nodes" in the linked list (ItemList).
    
    * Note the nodes only have a "next" pointer and not a "previous" pointer as I decided to implement a singularly linked list as opposed to a doubly linked list.
    
    * More info on linked list implementation in ItemList class.
        
*/

// will likely need to update/change these functions. Will focus on main functions for now
//static char* get_name(struct Item *this) {
//    if (this->name!='\0') return this->name;
//    else return "error";
//}
//static int get_price(struct Item *this){
//    if (this->price!='\0') return this->price;
//    else return -1;
//}
//static int get_quantity(struct Item *this){
//    if (this->quantity!='\0') return this->quantity;
//    else return -1;
//}
//int change_name(struct Item *this, char* new_name) {
//    if (new_name == '\0') return -1;
//    else {
//        this->name = new_name;
//        return 0;
//    }
//}
//int change_price(struct Item *this, int new_price) {
//    if (new_price < 0) return -1;
//    else {
//        this->price = new_price;
//        return this->price;
//    }
//}
//int change_quantity(struct Item *this, int new_quantity) {
//    if (new_quantity < 0) return -1;
//    else {
//        this->quantity = new_quantity;
//        return this->quantity;
//    }
//}
//int add_quantity(struct Item *this, int add_quantity) {
//    this->quantity = this->quantity + add_quantity;
//    return this->quantity;
//}
//int total_price(struct Item *this) {
//    return this->quantity * this->price;
//}

/*
 * Creates new Item object (node in ItemList linked list)
 * Parameters: name, price, quantity
 * Returns: pointer to Item
*/
struct Item* create_item(char* name, int price, int quantity) {
    struct Item* new_item = malloc(sizeof(Item));
    if (!new_item) return NULL;
    
    new_item->name = name;
    new_item->price = price;
    new_item->quantity = quantity;
    new_item->next = NULL;
    return new_item;
}

/*
 * Frees the item passed
 * Parameters: Item
 * Returns: void
 * Comments: Not sure this is strictly necessary, will keep for now just incase
*/
void free_item(struct Item *this){
    free(this);
    this = NULL;
}

/*
 * Gets the Item that this item points to
 * Parameters: Item
 * Returns: Pointer to next item
 * Comments: Not sure if this is necessary
*/
struct Item* get_next(struct Item* this){
    if (this->next == NULL) return NULL;
    else return this->next;
}

/*
 * Determines if the name of the item parameter is the same as the name parameter 
 *    (Used by ItemList class, which assumes list cannot have mult items of the same name)
 * Parameters: Item, name (string)
 * Returns: 0 for false and 1 for true
*/
int is_item(struct Item* this, char* name){
    if (name == this->name) return 1;
    else return 0;
}

/*
 * Prints values of Item to stdout
 * Parameters: Item
 * Returns: void
*/
void print_item(struct Item *this) {
    printf("Name: %s\n", this->name);
    printf("Price: %d\n", this->price);
    printf("Quantity: %d\n", this->quantity);
    if(this->next == NULL) printf("There is no next item\n");
    else printf("Next item is: %s\n", this->next->name);
}


static struct Item new(char* name, int price, int quantity, struct Item* next) {
    return (struct Item){.name=name,
                         .price=price,
                         .quantity=quantity,
                         .next=next,
//                         .get_name=&get_name,
//                         .get_price=&get_price,
//                         .get_quantity=&get_quantity,
//                         .change_name=&change_name,
//                         .change_price=&change_price,
//                         .change_quantity=&change_quantity,
//                         .add_quantity=add_quantity,
//                         .total_price=&total_price,
                         .print_item=&print_item,
                         .create_item=&create_item,
                         .free_item=&free_item,
                         .get_next=&get_next,
                         .is_item=&is_item
    };
}
const struct ItemClass Item={.new=&new};