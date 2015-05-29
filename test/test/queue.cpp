#include "queue.h"
#include <stdio.h>
#include <malloc.h>
#include <assert.h>

//#define QUEUE_SIZE 100
//static int front = 1;
//static int rear = 0;
//static QUEUE_TYPE queue[QUEUE_SIZE];
//
//void inerst_queue(QUEUE_TYPE value)
//{
//	if(!is_queue_full())
//	{
//		rear = (rear+1)%QUEUE_SIZE;
//		queue[rear] = value;
//	}
//}
//
//void delete_queue()
//{
//	if(!is_queue_empty())
//	{
//		front = (front + 1) % QUEUE_SIZE;
//	}
//}
//
//QUEUE_TYPE first()
//{
//	if(!is_queue_empty())
//	{
//		return queue[front];
//	}
//	return NULL;
//}
//
//int is_queue_empty()
//{
//	return (rear + 1) % QUEUE_SIZE == front;
//}
//
//int is_queue_full()
//{
//	return (rear + 2) % QUEUE_SIZE == front;
//}
//
//void create_queue(size_t size)
//{
//}
//
//void destroy_queue()
//{
//}

typedef struct QUEUE_NODE
{
	QUEUE_TYPE value;
	struct QUEUE_NODE *next;
}queue_node;

static queue_node *p_front = NULL;
static queue_node *p_rear = NULL;

void inerst_queue(QUEUE_TYPE value)
{
	queue_node *new_node = NULL;
	if(!is_queue_full())
	{
		new_node = (queue_node *)malloc(sizeof(queue_node));
		assert(new_node != NULL);
		new_node->value = value;
		new_node->next = NULL;
		if(p_front == NULL)
		{
			p_front = p_rear = new_node;
		}
		else
		{
			p_rear->next = new_node;
			p_rear = new_node;
		}
	}
}

void delete_queue()
{
	queue_node *old_node;
	if(!is_queue_empty())
	{
		old_node = p_front;
		p_front = p_front->next;
		free(old_node);
	}
}

QUEUE_TYPE first()
{
	if(!is_queue_empty())
	{
		return p_front->value;
	}
	return NULL;
}

int is_queue_empty()
{
	return p_front == NULL;
}

int is_queue_full()
{
	return 0;
}

void create_queue()
{
}

void destroy_queue()
{
	while(!is_queue_empty())
	{
		delete_queue();
	}
}

