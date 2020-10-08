#include <Order.h>
#include <stdbool.h>

struct Order first = Order.new("staples", 123);
if (first.open == true) printf("Order is open. I will now close the order\n");
first.close_order;
if (first.open == false) printf("Order is closed\n");