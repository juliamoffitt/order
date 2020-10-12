typedef struct Item item;
typedef struct Order order;
typedef struct ItemList list;

struct ItemList {  
    struct Item* head;
    int count;
//    int unique_items;
//    int total_items;
    
    //update item in list --> not sure about this, will implement later
    //sort list --> will also do this later
    
    struct ItemList* (*new_list)();
    void (*delete_list)(struct ItemList* this);
    void (*append_item)(struct ItemList* this, struct Item* new_item);
    void (*add_item)(struct ItemList* this, char* name, int price, int quantity);
    void (*remove_item)(struct ItemList* this, char* name);
    struct Item* (*get_item)(struct ItemList* this, char* name);
    struct Item* (*get_last)(struct ItemList* this);
    void (*print_list)(struct ItemList* this);
    
};
extern const struct ItemListClass {
    struct ItemList (*new)(struct Item* head, int count);
} ItemList;