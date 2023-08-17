#include "../lib/SJN.h"

static queue_object* SJN_queue;
static queue_object* withdraw;
//You can add more global variables here

process* SJN_tick (process* running_process){
    // TODO
    if (running_process == NULL || running_process -> time_left == 0)
    {
        queue_object* temp = SJN_queue -> next;
        unsigned int shortest_time = ((process*)temp->object)->time_left;
        running_process = (process*)temp->object;
        withdraw = temp;
        queue_object* temp_2 = temp -> next;
        while (temp_2 != NULL)
        {
            if (((process*)temp_2->object)->time_left <= shortest_time)
            {
                shortest_time = ((process*)temp_2->object)->time_left;
                running_process = (process*)temp_2->object;
                withdraw = temp_2;
            }
            temp_2 = temp_2 -> next;
        }

        queue_object* temp_3 = SJN_queue->next;
        queue_object* temp_4 = SJN_queue;
        while(temp_3 != NULL){
            if(withdraw == temp_3){
                temp_4->next = temp_3->next;
                break;
            }
            temp_3 = temp_3->next;
            temp_4 = temp_4->next; 
        }

    }

    if (running_process != NULL)
    {
        running_process -> time_left--;
    }

    return running_process;
}

int SJN_startup(){
    // TODO
    SJN_queue = new_queue();

    if(SJN_queue == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

process* SJN_new_arrival(process* arriving_process, process* running_process){
    // TODO
    if (arriving_process != NULL)
    {
        queue_add(arriving_process, SJN_queue);
    }

    return running_process;
}

void SJN_finish(){
    // TODO
    free(SJN_queue);
}
