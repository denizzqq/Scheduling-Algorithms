#include "../lib/HRRN.h"

static queue_object* HRRN_queue;
//You can add more global variables and structs here

process* HRRN_tick (process* running_process){
    // TODO
    float highest_rr = 0.0;

    if (running_process == NULL || running_process -> time_left == 0)
    {
        queue_object* temp = HRRN_queue -> next;
        while (temp != NULL)
        {
            ((HRRN_process*)temp -> object) -> rr = (((HRRN_process*)temp -> object) -> waiting_time + ((HRRN_process*)temp -> object) -> this_process -> time_left)
            / ((HRRN_process*)temp -> object) -> this_process -> time_left;

            if (((HRRN_process*)temp -> object)-> rr > highest_rr)
            {
                highest_rr = ((HRRN_process*)temp -> object)-> rr;
                running_process = ((HRRN_process*)temp -> object)-> this_process;
            }
            temp = temp -> next;
            

        }
        
    }

    if (running_process != NULL)
    {
        running_process -> time_left--;
        queue_object* temp_2 = HRRN_queue -> next;
        while (temp_2 != NULL)
        {
            ((HRRN_process*)temp_2 -> object) -> waiting_time++;
            temp_2 = temp_2 -> next;
        }
        
    }

    return running_process;
    
    
}

int HRRN_startup(){
    // TODO
    HRRN_queue = new_queue();

    if(HRRN_queue == NULL){
        return 1;
    }
    else{
        return 0;
    }
    
}

process* HRRN_new_arrival(process* arriving_process, process* running_process){
    // TODO
    if(arriving_process!=NULL){
        HRRN_process* arriving = (HRRN_process*)malloc(sizeof(HRRN_process));
        arriving->this_process = arriving_process;
        arriving->waiting_time = 0.0;
        arriving->rr = 0.0; 
        queue_add(arriving, HRRN_queue);
    }
    return running_process;
}

void HRRN_finish(){
    // TODO
    free_queue(HRRN_queue);
}
