struct Order {
    char* vendor;
    int PO;
    int open; // 1 is open, 0 is closed
    void (*close_order)(struct Order *this);
    void (*print_order)(struct Order *this);
    int (*get_status)(struct Order *this);
    char* (*get_vendor)(struct Order *this);
    int (*get_PO)(struct Order *this);
    int (*change_vendor)(struct Order *this, char* new_vendor);
    int (*change_PO)(struct Order *this, int new_PO);
    
};
extern const struct OrderClass {
    struct Order (*new)(char* vendor, int PO);
} Order;