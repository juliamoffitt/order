#include <stdio.h>
#include <stdlib.h>
#include "ItemList.h"

ItemList* new_list(){
    struct ItemList* new_list = malloc(sizeof(ItemList));
    if(!new_list) return NULL;
    
    new_list->head=NULL;
    new_list->count=0;
    return new_list;
}
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
void add_item(struct ItemList* this, Item* new_item){
    struct Item* curr = this->head;
    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = new_item;
}
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
Item* get_item(struct ItemList* this, char* name){
    Item* curr = this->head;
    while (curr->next != NULL){
        if (curr->name == name) return curr;
        else curr = curr->next;
    }
    return NULL;
}
Item* get_last(struct ItemList* this) {
    if(this->next == NULL) return NULL;
    Item* curr = this;
    while(curr->next != NULL) {
        curr = curr->next;
    }
    return curr;
}
static struct ItemList new(Item* head, int count) {
    return (struct ItemList){
        .head=head,
        .count=count,
        .new_list=&new_list,
        .delete_list=&delete_list,
        .add_item=&add_item,
        .remove_item=&remove_item,
        .get_item=&get_item,
        .get_last=&get_last
    };
}
const struct ItemListClass ItemList={.new=&new}