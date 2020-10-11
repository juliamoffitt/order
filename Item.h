typedef struct ItemList list;
typedef struct Order order;
typedef struct Item item;

struct Item {
    /* values and methods */
    char* name;
    int price;
    int quantity;
    struct Item* next;

// will likely need to alter these but will focus on main functions for now
//    char* (*get_name)(struct Item *this);
//    int (*get_price)(struct Item *this);
//    int (*get_quantity)(struct Item *this);
//    int (*change_name)(struct Item *this, char* new_name);
//    int (*change_price)(struct Item *this, int new_price);
//    int (*change_quantity)(struct Item *this, int new_quantity);
//    int (*add_quantity)(struct Item *this, int add_quantity);
//    int (*total_price)(struct Item *this);
    
    static struct Item* (*create_item)(char* name, int price, int quantity);
    void (*free_item)(struct Item *this);
    struct Item* (*get_next)(struct Item* this);
    int (*is_item)(struct Item* this, char* name); //returns 0 for no and 1 for yes
    void (*print_item)(struct Item *this);
    

};
extern const struct ItemClass {
    struct Item (*new)(char* name, int price, int quantity, struct Item* next);
} Item;