#ifndef TREE_H
#define TREE_H

#define TREE_TYPE int

void insert_tree(TREE_TYPE value);
void delete_tree(TREE_TYPE value);
const TREE_TYPE * find(TREE_TYPE value);
void pre_order_traverse(void (*visit)(TREE_TYPE));
void in_order_traverse(void (*visit)(TREE_TYPE));
void post_order_traverse(void (*visit)(TREE_TYPE));
int get_depth();
int is_balance();

#endif
