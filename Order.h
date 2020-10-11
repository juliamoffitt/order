typedef struct ItemList list;
typedef struct Order order;
typedef struct Item item;

struct Order {
    char* vendor;
    int PO;
    struct ItemList* list;
    int open; // 1 is open, 0 is closed
    
//    void (*close_order)(struct Order *this);
//    void (*print_order)(struct Order *this);
//    int (*get_status)(struct Order *this);
//    char* (*get_vendor)(struct Order *this);
//    int (*get_PO)(struct Order *this);
//    int (*change_vendor)(struct Order *this, char* new_vendor);
//    int (*change_PO)(struct Order *this, int new_PO);
    
    static struct Order* (*new_order)(char* vendor, int PO);
    void (*delete_order)(struct Order *this);
    void (*print_order)(struct Order *this);
    
};
extern const struct OrderClass {
    struct Order (*new)(char* vendor, int PO);
} Order;