#include "../lib/queue.h"
#include <stdlib.h>
#include <stdio.h>

int queue_add(void* new_object, queue_object* queue){
    // TODO
    queue_object* new_queue_obejct = (queue_object*)malloc(sizeof(queue_object)); 
    new_queue_obejct->object = new_object;
  
   
    if (new_queue_obejct == NULL)
    {
        return 1;
    }

    queue_object* iter = queue;

    new_queue_obejct->next = iter->next;
    iter->next = new_queue_obejct;


    if (queue == NULL)
    {
        queue = new_queue_obejct;
        queue->next = NULL;
    }
    

    return 0;
}

void* queue_poll(queue_object* queue){
    // TODO
   if (queue == NULL)
    {
        return NULL;
    }

    if (queue->next == NULL)
    {
        void* resultq = queue->object;
        queue = NULL;
        return resultq;
    }
    
    
    queue_object* iter = queue;
    while (iter->next->next != NULL)
    {
        iter = iter->next;
    }
    queue_object* temp = iter->next;
    void* result = temp->object;
    iter->next = NULL;

    if (queue == NULL)
    {
        queue->next = NULL;
    }

    free(temp);

    return result;
}

queue_object* new_queue(){
    // TODO
    queue_object* queue = (queue_object*)malloc(sizeof(queue_object));
    queue->object = NULL;
    queue->next = NULL;
    
    return queue;
}


void free_queue(queue_object* queue){
    // TODO
    if (queue == NULL)
    {
        free(queue);
    }
    
    queue_object* iter = queue;
    queue_object* temp;
    while (iter->next != NULL)
    {
        temp = iter;
        iter = iter->next;
        free(temp);
    }
}

void* queue_peek(queue_object* queue){
    // TODO
    if (queue == NULL)
    {
        return NULL;
    }
    queue_object* iter = queue;

    while (iter->next != NULL)
    {
        iter = iter->next;
    }
    
    return iter->object;
}
