#include <stdio.h>
#include <stdlib.h>
#include "ItemList.h"

/*
    ItemList class
    
    Fields: Item* head, int count
    Functions:
        static ItemList* new_list()
        void delete_list(struct ItemList* this)
        void add_item(struct ItemList* this, Item* new_item)
        void remove_item(struct ItemList* this, char* name)
        Item* get_item(struct ItemList* this, char* name)
        Item* get_last(struct ItemList* this)
        void print_list(struct ItemList* this)
        
    * ItemList is a singly linked list to store Items.
*/


/*
 * Creates a new list (linked list of Items)
 * Parameters: none
 * Returns: pointer to new list
*/
static ItemList* new_list(){
    struct ItemList* new_list = malloc(sizeof(ItemList));
    if(!new_list) return NULL;
    
    new_list->head=NULL;
    new_list->count=0;
    return new_list;
}

/*
 * Deletes all items and list itself
 * Parameters: ItemList
 * Returns: void
*/
void delete_list(struct ItemList* this){
    Item* hd, curr;
    if (this->head == NULL){ //if there are no items in list
        free(this);
        this = NULL;
        return;
    }
    
    while (hd->next != NULL) {
        hd = curr->next;
        free(curr);
        curr = hd->next;
    }
    free(curr); curr = NULL;
    free(hd); hd = NULL;
    free(this); this = NULL;
    return;
}

/*
 * Adds existing item to end of list
 * Parameters: ItemList
 * Returns: void
 * Note: assumes duplicate item has already been checked,
*/
void append_item(struct ItemList* this, Item* new_item){
    if (this == NULL || new_item == NULL) return;
    struct Item* last = get_last(this);
    last->next = new_item;
}

/*
 * Checks if item exists in list
 *   if exists update existing item
 *   else creates new item and appends to list
 * Parameters: ItemList, name (of item)
 * Returns: void
 * Note: PUBLIC
 */
void add_item(struct ItemList* this, char* name, int price, int quantity) {
    if (this == NULL || name = '\0' || quantity == 0) return;
    
    Item* temp = get_item(this, name);
    if(temp == NULL) temp = create_item(name, price, quantity);
    else temp->quantity = quantity + temp->quantity;
}

/*
 * Removes item from list and deletes item
 * Parameters: List, name of item
 * Returns: void
*/
void remove_item(struct ItemList* this, char* name){
    Item* prev, curr;
    prev = this->head;
    curr = prev->next;
    
    //case where first item is the item to remove
    if (prev->name == name) {
        this->head = curr;
        free(prev);
        prev = NULL;
        return;
    }
    while(curr->next != NULL) {
        if(curr->name == name){
            prev->next = curr->next;
            free(curr);
            curr = NULL;
            return;
        } else curr = curr->next;
    }
}

/*
 * Searches for item in list by name
 * Parameters: ItemList, name of item
 * Returns: Pointer to item in question
*/
Item* get_item(struct ItemList* this, char* name){
    Item* curr = this->head;
    while (curr->next != NULL){
        if (is_item(name) == name) return curr;
        else curr = curr->next;
    }
    return NULL;
}

/*
 * Gets pointer to last item in list (list traversal)
 * Parameters: ItemList
 * Returns: Pointer to last item in list
*/
Item* get_last(struct ItemList* this) {
    if(this->next == NULL) return NULL;
    Item* curr = this;
    while(curr->next != NULL) {
        curr = curr->next;
    }
    return curr;
}

/*
 * Prints fields of list (including items in list)
 * Parameters: ItemList
 * Returns: void
*/
void print_list(struct ItemList* this) {
    if(this == NULL) {
        printf("Error: list is empty");
        return;
    }
    struct Item* temp = this->head;
    while(this->next != NULL) {
        print_item(this->next);
        this = this->next;
    }
}

static struct ItemList new(Item* head, int count) {
    return (struct ItemList){
        .head=head,
        .count=count,
        .new_list=&new_list,
        .delete_list=&delete_list,
        .append_item=&append_item,
        .add_item=&add_item
        .remove_item=&remove_item,
        .get_item=&get_item,
        .get_last=&get_last,
        .print_list=&print_list
    };
}
const struct ItemListClass ItemList={.new=&new}