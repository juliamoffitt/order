#include <stdio.h>
#include "ItemList.h"

static struct ItemList new(/*fields*/) {
    return (struct ItemList){/*fields and methods*/};
}
const struct ItemListClass ItemList={.new=&new}