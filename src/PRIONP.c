#include "../lib/PRIONP.h"
#include <stdio.h>

static queue_object* PRIONP_queue;
static queue_object* withdraw;
//You can add more global variables here

process* PRIONP_tick (process* running_process){
    // TODO
    unsigned int highest_prio = 0;
    if (running_process == NULL || running_process -> time_left == 0)
    {
        queue_object* temp = PRIONP_queue -> next;
        while (temp != NULL)
        {
            if (((process*)temp->object)->priority > highest_prio)
            {
                highest_prio = ((process*)temp->object)->priority;
                running_process = (process*)temp->object;
                withdraw = temp;
            }
            temp = temp -> next;
        }

        queue_object* temp_2 = PRIONP_queue->next;
        queue_object* temp_3 = PRIONP_queue;
        while(temp_2 != NULL){
            if(withdraw == temp_2){
                temp_3->next = temp_2->next;
                break;
            }
            temp_2 = temp_2->next;
            temp_3 = temp_3->next; 
        }

    }

    if (running_process != NULL)
    {
        running_process -> time_left--;
    }

    return running_process;
}

int PRIONP_startup(){
    // TODO
    PRIONP_queue = new_queue();

    if(PRIONP_queue == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

process* PRIONP_new_arrival(process* arriving_process, process* running_process){
    // TODO
    if (arriving_process != NULL)
    {
        queue_add(arriving_process, PRIONP_queue);
    }

    return running_process;
    
}

void PRIONP_finish(){
    // TODO
    free(PRIONP_queue);
}
