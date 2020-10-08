struct Item {
    /* values and methods */
    char* name;
    int price;
    int quantity;
    char* (*get_name)(struct Item *this);
    int (*get_price)(struct Item *this);
    int (*get_quantity)(struct Item *this);
    int (*change_name)(struct Item *this, char* new_name);
    int (*change_price)(struct Item *this, int new_price);
    int (*change_quantity)(struct Item *this, int new_quantity);
    int (*add_quantity)(struct Item *this, int add_quantity);
    int (*total_price)(struct Item *this);
    void (*print_item)(struct Item *this);
};
extern const struct ItemClass {
    struct Item (*new)(char* name, int price, int quantity);
} Item;