#include "tree.h"
#include <stdio.h>
#include <malloc.h>
#include <assert.h>

typedef struct TREE_NODE
{
	TREE_TYPE value;
	struct TREE_NODE *left;
	struct TREE_NODE *right;
}tree_node;

tree_node *new_node(TREE_TYPE value);
void free_node(tree_node *node);
void insert(tree_node **pp_tr, TREE_TYPE value);
void delete_(tree_node **pp_tr, TREE_TYPE value);
TREE_TYPE delete_left_max(tree_node **pp_tr);
TREE_TYPE delete_right_min(tree_node **pp_tr);
TREE_TYPE is_leaf(tree_node *tr);
int get_max_depth(tree_node *tr);
int get_min_depth(tree_node *tr);
TREE_TYPE get_max_value(tree_node *tr);
TREE_TYPE get_min_value(tree_node *tr);
const TREE_TYPE *_find(tree_node *tr,TREE_TYPE value);
int is_balance(tree_node *tr);
void adjust(tree_node *tr);

tree_node *tree = NULL;

tree_node * new_node(TREE_TYPE value)
{
		tree_node * p_node = (tree_node*)malloc(sizeof(tree_node));
		assert(p_node != NULL);
		p_node->left = NULL;
		p_node->right = NULL;
		p_node->value = value;
		return p_node;
}
void free_node(tree_node *node)
{
	free(node);
}

int is_leaf(tree_node *tr)
{
	return (tr->left == NULL && tr->right == NULL);
}

int get_depth()
{
	return get_max_depth(tree);
}

void insert_tree(TREE_TYPE value)
{
	insert(&tree,value);
}

void delete_tree(TREE_TYPE value)
{
	if(_find(tree,value) == NULL)
	{
		return ;
	}
	delete_(&tree,value);
}

void delete_(tree_node **pp_tr,TREE_TYPE value)
{
	tree_node *tr = *pp_tr;
	if(tr->left == NULL && tr->value == value)
	{
		free_node(tr);
		*pp_tr = NULL;
		return;
	}
	
	if(get_max_depth(tr->left) > get_max_depth(tr->right))
	{
		//´Ó×ó×ÓÊ÷É¾³ý
		if(tr->value == value)
		{
			tr->value = delete_left_max(&tr->left);
			adjust(tr->left);
			return;
		}
		if(value < tr->value)
		{
			delete_(&tr->left,value);
		}
		else
		{
			insert(&tr->right,tr->value);
			tr->value = delete_left_max(&tr->left);
			adjust(tr->left);
			delete_(&tr->right,value);
		}		
	}
	else
	{
		//´ÓÓÒ×ÓÊ÷É¾³ý
		if(tr->value == value)
		{
			tr->value = delete_right_min(&tr->right);
			adjust(tr->right);
			return;
		}
		if(value > tr->value)
		{
			delete_(&tr->right,value);
		}
		else
		{
			insert(&tr->left,tr->value);
			tr->value = delete_right_min(&tr->right);
			adjust(tr->right);
			delete_(&tr->left,value);
		}
	}
}

void adjust(tree_node *tr)
{
	if(!is_balance(tr))
	{
		if(!is_balance(tr->left))
		{
			adjust(tr->left);
		}
		if(!is_balance(tr->right))
		{
			adjust(tr->right);
		}
		if(get_min_depth(tr->left) < get_max_depth(tr->right))
		{
			insert(&tr->left,tr->value);
			adjust(tr->left);
			tr->value = delete_right_min(&tr->right);
			adjust(tr->right);
		}
	}
}

int is_balance()
{
	return is_balance(tree);
}
int is_balance(tree_node *tr)
{
	if(tr == NULL)
	{
		return 1;
	}
	return (get_min_depth(tr->left) >= get_max_depth(tr->right) && is_balance(tr->left) && is_balance(tr->right));
}
int get_max_depth(tree_node *tr)
{
	int l,r;
	if(tr == NULL)
	{
		return 0;
	}
	l = get_max_depth(tr->left) + 1;
	r = get_max_depth(tr->right) + 1;
	return l>r?l:r;
}
int get_min_depth(tree_node *tr)
{
	int l,r;
	if(tr == NULL)
	{
		return 0;
	}
	l = get_min_depth(tr->left) + 1;
	r = get_min_depth(tr->right) + 1;
	return l<r?l:r;
}
TREE_TYPE get_max_value(tree_node *tr)
{
	assert(tr != NULL);
	TREE_TYPE ret = tr->value;
	while(tr->right != NULL)
	{
		tr = tr->right;
		ret = tr->value;
	}
	return ret;
}
TREE_TYPE get_min_value(tree_node *tr)
{
	assert(tr != NULL);
	TREE_TYPE ret = tr->value;
	while(tr->left != NULL)
	{
		tr = tr->left;
		ret = tr->value;
	}
	return ret;
}

TREE_TYPE delete_left_max(tree_node **pp_tr)
{
	assert(*pp_tr != NULL);
	tree_node *p_tr = *pp_tr;
	TREE_TYPE ret = p_tr->value;
	while(p_tr->right != NULL)
	{
		pp_tr = &p_tr->right;
		p_tr = p_tr->right;
		ret = p_tr->value;
	}
	*pp_tr = p_tr->left;
	free_node(p_tr);
	return ret;
}
TREE_TYPE delete_right_min(tree_node **pp_tr)
{
	assert(*pp_tr != NULL);
	tree_node *p_tr = *pp_tr;
	TREE_TYPE ret = p_tr->value;
	while(p_tr->left != NULL)
	{
		pp_tr = &p_tr->left;
		p_tr = p_tr->left;
		ret = p_tr->value;
	}
	*pp_tr = p_tr->right;
	free_node(p_tr);
	return ret;
}

void insert(tree_node **pp_tr,TREE_TYPE value)
{
	if(*pp_tr == NULL)
	{
		*pp_tr = new_node(value);
		return ;
	}
	if(_find(*pp_tr,value) != NULL)
	{
		return ;
	}
	tree_node *tr = *pp_tr;
	if(get_min_depth(tr->left) <= get_min_depth(tr->right))
	{
		if(value < tr->value)
		{
			insert(&tr->left,value);
		}
		else
		{
			insert(&tr->left,tr->value);
			if(tr->right == NULL || value < get_min_value(tr->right))
			{
				tr->value = value;
			}
			else
			{
				tr->value = delete_right_min(&tr->right);
				insert(&tr->right,value);
			}
		}
	}
	else
	{
		if(value > tr->value)
		{
			insert(&tr->right,value);
		}
		else
		{
			insert(&tr->right,tr->value);
			if(value > get_max_value(tr->left))
			{
				tr->value = value;
			}
			else
			{
				tr->value = delete_left_max(&tr->left);
				insert(&tr->left,value);
			}
		}
	}
}

const TREE_TYPE *find(TREE_TYPE value)
{
	return _find(tree,value);
}
const TREE_TYPE *_find(tree_node *tr,TREE_TYPE value)
{
	while(tr != NULL && tr->value != value)
	{
		if(value < tr->value)
		{
			tr = tr->left;
		}
		else
		{
			tr = tr->right;
		}
	}
	if(tr == NULL)
	{
		return NULL;
	}
	return &tr->value;
}

void _pre_order_traverse(tree_node *tr,void (*visit)(TREE_TYPE))
{
	if(tr == NULL)
	{
		return;
	}
	visit(tr->value);
	_pre_order_traverse(tr->left,visit);
	_pre_order_traverse(tr->right,visit);
}
void _in_order_traverse(tree_node *tr,void(*visit)(TREE_TYPE))
{
	if(tr == NULL)
	{
		return;
	}
	_in_order_traverse(tr->left,visit);
	visit(tr->value);
	_in_order_traverse(tr->right,visit);
}
void _post_order_traverse(tree_node *tr, void(*visit)(TREE_TYPE))
{
	if(tr == NULL)
	{
		return;
	}
	_post_order_traverse(tr->left,visit);
	_post_order_traverse(tr->right,visit);
	visit(tr->value);
}
void pre_order_traverse(void (*visit)(TREE_TYPE))
{
	_pre_order_traverse(tree,visit);
}
void in_order_traverse(void (*visit)(TREE_TYPE))
{
	_in_order_traverse(tree,visit);
}
void post_order_traverse(void (*visit)(TREE_TYPE))
{
	_post_order_traverse(tree,visit);
}


//tree_node * new_node(TREE_TYPE value);
//void free_node(tree_node *node);
//void insert_in(tree_node *tr,TREE_TYPE value);
//void insert_left(tree_node *tr,TREE_TYPE value);
//void insert_right(tree_node *tr,TREE_TYPE value);
//TREE_TYPE delete_left_max(tree_node *tr);
//TREE_TYPE delete_right_min(tree_node *tr);
//int is_leaf(tree_node *tr);
//int _get_max_depth(tree_node *tr);
//int _get_min_depth(tree_node *tr);
//int _get_max_value(tree_node *tr);
//int _get_min_value(tree_node *tr);
//
//tree_node *tree = NULL;

//tree_node * new_node(TREE_TYPE value)
//{
//		tree_node * p_node = (tree_node*)malloc(sizeof(tree_node));
//		assert(p_node != NULL);
//		p_node->left = NULL;
//		p_node->right = NULL;
//		p_node->value = value;
//		return p_node;
//}
//void free_node(TREE_NODE * node)
//{
//	free(node);
//}
//
//void insert_in(tree_node *tr,TREE_TYPE value)
//{
//	if(tr->value > value)
//	{
//		insert_left(tr,value);
//	}
//	if(tr->value > value)
//	{
//		insert_right(tr,value);
//	}
//}
//
//void insert_left(tree_node *tr,TREE_TYPE value)
//{
//	if(tr->left == NULL)
//	{
//		tr->left = new_node(value);
//		return;
//	}
//	insert_in(tr->left,value);
//};
//
//void insert_right(tree_node *tr,TREE_TYPE value)
//{
//	if(tr->right == NULL)
//	{
//		tr->right = new_node(value);
//		return;
//	}
//	insert_in(tr->right,value);
//}
//
//void _insert(tree_node * tr,TREE_TYPE value)
//{	
//	//printf("insert %d\n",value);
//	if(_get_min_depth(tr->left) <= _get_min_depth(tr->right))
//	{
//		if(value < tr->value)
//		{
//			if(tr->left == NULL)
//			{
//				tr->left = new_node(value);
//			}
//			else
//			{
//				_insert(tr->left,value);
//			}
//			return;
//		}
//		if(value > tr->value)
//		{
//			if(tr->left == NULL)
//			{
//				tr->left = new_node(tr->value);
//			}
//			else
//			{
//				_insert(tr->left,tr->value);
//			}
//			if(tr->right == NULL)
//			{
//				tr->value = value;
//			}
//			else
//			{
//				if(value < _get_min_value(tr->right))
//				{
//					tr->value = value;
//					return;
//				}
//				if(value > _get_min_value(tr->right))
//				{
//					tr->value = delete_right_min(tr);
//					if(tr->right == NULL)
//					{
//						tr->right = new_node(value);
//					}
//					else
//					{
//						_insert(tr->right,value);
//					}
//				}
//				if(value == _get_min_value(tr->right))
//				{
//					tr->value = delete_right_min(tr);
//				}
//			}
//		}
//	}
//	else
//	{
//		if(value > tr->value)
//		{
//			if(tr->right == NULL)
//			{
//				tr->right = new_node(value);
//			}
//			else
//			{
//				_insert(tr->right,value);
//			}
//			return;
//		}
//		if(value < tr->value)
//		{
//			if(tr->right == NULL)
//			{
//				tr->right = new_node(tr->value);
//			}
//			else
//			{
//				_insert(tr->right,tr->value);
//			}
//			if(tr->left == NULL)
//			{
//				tr->value = value;
//			}
//			else
//			{
//				if(value > _get_max_value(tr->left))
//				{
//					tr->value = value;
//					return;
//				}
//				if(value < _get_max_value(tr->left))
//				{
//					tr->value = delete_left_max(tr);
//					if(tr->left == NULL)
//					{
//						tr->left = new_node(value);
//					}
//					else
//					{
//						_insert(tr->left,value);
//					}
//				}
//				if(value == _get_max_value(tr->left))
//				{
//					tr->value = delete_left_max(tr);
//				}
//			}
//		}
//	}
////	insert_in(tr,value);
//}
//
//void inerst_tree(TREE_TYPE value)
//{
//	if (tree == NULL)
//	{
//		tree = new_node(value);
//		return;
//	}	
//	_insert(tree,value);
//}
//
//TREE_TYPE delete_left_max(tree_node *tr)
//{
//	TREE_TYPE ret=tr->left->value;
//	tree_node **pp = &tr->left;
//	tr = tr->left;
//
//	while(tr->right != NULL)
//	{
//		pp = &tr->right;
//		tr = tr->right;
//		ret = tr->value;
//	}
//	*pp = tr->left;
//	free_node(tr);
//	return ret;
//}
//
//TREE_TYPE delete_right_min(tree_node *tr)
//{
//	TREE_TYPE ret=tr->right->value;
//	tree_node **pp = &tr->right;
//	tr = tr->right;
//
//	while(tr->left != NULL)
//	{
//		pp = &tr->left;
//		tr = tr->left;
//		ret = tr->value;
//	}
//	*pp = tr->right;
//	free_node(tr);
//	return ret;
//}
//
//void delete_tree(TREE_TYPE value)
//{
//	tree_node *tr = tree;
//	tree_node **pp = &tree;
//	
//	while((tr != NULL) && (tr->value != value))
//	{
//		if(tr->value > value)
//		{
//			pp = &tr->right;
//			tr = tr->right;
//		}
//		else
//		{
//			pp = &tr->left;
//			tr = tr->left;
//		}
//	}
//	if(tr != NULL)
//	{
//		if(tr->left == NULL)
//		{
//			*pp = tr->right;
//			free(tr);
//			return;
//		}
//		if(tr->right == NULL)
//		{
//			*pp = tr->left;
//			free(tr);
//			return;
//		}
//		tr->value = delete_left_max(tr);
//	}
//}
//
//int is_leaf(tree_node *tr)
//{
//	return (tr->left == NULL && tr->right == NULL);
//}
//
//int _get_max_depth(tree_node *tr)
//{
//	int l,r;
//	if (tr == NULL) 
//	{
//		return 0;
//	}
//	l = _get_max_depth(tr->left)+1;
//	r = _get_max_depth(tr->right)+1;
//	return l>r?l:r;
//}
//
//int _get_min_depth(tree_node *tr)
//{
//	int l,r;
//	if (tr == NULL) 
//	{
//		return 0;
//	}
//	l = _get_min_depth(tr->left)+1;
//	r = _get_min_depth(tr->right)+1;
//	return l<r?l:r;
//}
//
//int _get_min_value(tree_node *tr)
//{
//	while(tr->left != NULL)
//	{
//		tr = tr->left;
//	}
//	return tr->value;
//}
//
//int _get_max_value(tree_node *tr)
//{
//	while(tr->right != NULL)
//	{
//		tr = tr->right;
//	}
//	return tr->value;
//}
//
//int get_depth()
//{
//	return _get_max_depth(tree);
//}
//
//void _pre_order_traverse(tree_node *tr,void (*visit)(TREE_TYPE))
//{
//	if(tr == NULL)
//	{
//		return;
//	}
//	visit(tr->value);
//	_pre_order_traverse(tr->left,visit);
//	_pre_order_traverse(tr->right,visit);
//}
//
//void _in_order_traverse(tree_node *tr,void(*visit)(TREE_TYPE))
//{
//	if(tr == NULL)
//	{
//		return;
//	}
//	_in_order_traverse(tr->left,visit);
//	visit(tr->value);
//	_in_order_traverse(tr->right,visit);
//}
//
//void _post_order_traverse(tree_node *tr, void(*visit)(TREE_TYPE))
//{
//	if(tr == NULL)
//	{
//		return;
//	}
//	_post_order_traverse(tr->left,visit);
//	_post_order_traverse(tr->right,visit);
//	visit(tr->value);
//}
//void pre_order_traverse(void (*visit)(TREE_TYPE))
//{
//	_pre_order_traverse(tree,visit);
//}
//
//void in_order_traverse(void (*visit)(TREE_TYPE))
//{
//	_in_order_traverse(tree,visit);
//}
//void post_order_traverse(void (*visit)(TREE_TYPE))
//{
//	_post_order_traverse(tree,visit);
//}
