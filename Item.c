#include <stdio.h>
#include "Item.h"
static char* get_name(struct Item *this) {
    if (this->name!='\0') return this->name;
    else return "error";
}
static int get_price(struct Item *this){
    if (this->price!='\0') return this->price;
    else return -1;
}
static int get_quantity(struct Item *this){
    if (this->quantity!='\0') return this->quantity;
    else return -1;
}
int change_name(struct Item *this, char* new_name) {
    if (new_name == '\0') return -1;
    else {
        this->name = new_name;
        return 0;
    }
}
int change_price(struct Item *this, int new_price) {
    if (new_price < 0) return -1;
    else {
        this->price = new_price;
        return this->price;
    }
}
int change_quantity(struct Item *this, int new_quantity) {
    if (new_quantity < 0) return -1;
    else {
        this->quantity = new_quantity;
        return this->quantity;
    }
}
int add_quantity(struct Item *this, int add_quantity) {
    this->quantity = this->quantity + add_quantity;
    return this->quantity;
}
int total_price(struct Item *this) {
    return this->quantity * this->price;
}
void print_item(struct Item *this) {
    printf("Name of item is: %s\n", this->name);
    printf("Price of item is %d\n", this->price);
    printf("Quantity of item is %d\n", this->quantity);
    printf("Total price for item is %d\n", total_price(this));
}

static struct Item new(char* name, int price, int quantity) {
    return (struct Item){.name=name, .price=price, .quantity=quantity, .get_name=&get_name,
                        .get_price=&get_price, .get_quantity=&get_quantity, .change_name=&change_name,
                        .change_price=&change_price, .change_quantity=&change_quantity,
                        .add_quantity=add_quantity, .total_price=&total_price, .print_item=&print_item};
}
const struct ItemClass Item={.new=&new};