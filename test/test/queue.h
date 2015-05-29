#ifndef QUEUE_H
#define QUEUE_H

#define QUEUE_TYPE int

void insert_queue(void);
void delete_queue(void);
QUEUE_TYPE first();
int is_queue_empty();
int is_queue_full();
void create_queue(size_t size);
void destroy_queue();

#endif