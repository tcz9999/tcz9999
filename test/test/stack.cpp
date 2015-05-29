#include "stack.h"
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>


//#define STACK_SIZE 100
//
//static STACK_TYPE *stack = NULL;
//static int top_element = -1;
//static size_t stack_size = 0;
//
//void push(STACK_TYPE value)
//{
//	if (is_stack_full())
//	{
//		return;
//	}
//	stack[++top_element]= value;
//}
//
//void pop()
//{
//	if(is_stack_empty())
//	{
//		return;
//	}
//	top_element--;
//}
//
//STACK_TYPE top()
//{
//	if(is_stack_empty())
//	{
//		return NULL;
//	}
//	return stack[top_element];
//}
//
//int is_stack_empty()
//{
//	assert(stack_size > 0);
//	return top_element == -1;
//}
//
//int is_stack_full()
//{
//	assert(stack_size > 0);
//	return top_element == stack_size-1;
//}
//
//void create_stack(size_t size)
//{
//	if (stack_size != 0)
//	{
//		stack = (STACK_TYPE *)malloc(size * sizeof(STACK_TYPE));
//		assert(stack != NULL);
//		stack_size = size;
//	}
//}
//
//void destroy_stack()
//{
//	if(stack_size != 0)
//	{
//		free(stack);
//		stack = NULL;
//		stack_size = 0;
//	}
//}

typedef struct STACK_NODE
{
	STACK_TYPE value;
	struct STACK_NODE *next;
} stack_node;

static stack_node *stack = NULL;

void create_stack()
{
}

void _pop()
{
	stack_node *first_node;
	first_node = stack;
	stack = stack->next;
	free(first_node);
}

void destroy_stack()
{
	while(!is_stack_empty())
	{
		_pop();
	}
}

void push(STACK_TYPE value)
{
	stack_node *new_node = NULL;
	
	new_node = (stack_node*)malloc(sizeof(stack_node));
	assert(new_node != NULL);
	new_node->value = value;
	new_node->next = stack;
	stack = new_node;
}

void pop()
{
	if (is_stack_empty())
	{
		return;
	}
	_pop();
}

STACK_TYPE top()
{
	assert(stack != NULL);
	return stack->value;
}

int is_stack_empty()
{
	return stack==NULL;
}

int is_stack_full()
{
	return 0;
}
