#include "../lib/RR.h"

static queue_object* RR_queue;
static int dq;
static int q;
//You can add more global variables


process* RR_tick (process* running_process){
    // TODO        
    if (running_process==NULL || running_process->time_left==0 || q == 0  ){
        if(running_process!=NULL && q == 0 && running_process->time_left != 0){
            queue_add(running_process,RR_queue);
        }
        running_process=queue_poll(RR_queue);
        q = dq;
    }
    if(running_process != NULL){
        running_process->time_left--;
        q--;
    } 
    return running_process;
}

int RR_startup(int quantum){
    // TODO
    dq = quantum;
    RR_queue = new_queue();
    if(RR_queue == NULL){
        return 1;
    }
    return 0;
}


process* RR_new_arrival(process* arriving_process, process* running_process){
    // TODO
    if(arriving_process!=NULL){
        queue_add(arriving_process, RR_queue);
    }
    return running_process;
}


void RR_finish(){
    // TODO
    free(RR_queue);
}
