#include "../lib/MLF.h"
#include <stdio.h>

static queue_object** MLF_queues;
static int MLF_quantum_counter;
static int queue_order;
static int size_mlf = 8;
//You can add more global variables here

process* MLF_tick (process* running_process){
    // TODO
    if (MLF_quantum_counter == 0 && running_process != NULL && running_process->time_left != 0) {
        queue_add(running_process, MLF_queues[queue_order + 1]);
        running_process = NULL;
    }

    if (running_process == NULL || running_process->time_left == 0) {
        for (int level = 0; level < size_mlf; level++) {
            running_process = queue_poll(MLF_queues[level]);
            MLF_quantum_counter = 1 << level;

            if (running_process != NULL) {
                queue_order = level;
                break;
            }
        }
    }
    
    if (running_process != NULL && MLF_quantum_counter != 0) {
        running_process->time_left--;
        MLF_quantum_counter--;
    }

    return running_process;

}

/**
 * Do everything you have to at startup in this function. It is called once.
 * @result 0 if everything was fine. Any other number if there was an error.
 */
int MLF_startup(){
    // TODO
    MLF_queues = calloc(7, sizeof(queue_object));

    for (int i = 0; i < size_mlf; i++)
    {
        MLF_queues[i] = new_queue();
    }
    

    if(MLF_queues == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

process* MLF_new_arrival(process* arriving_process, process* running_process){
    // TODO
    if(arriving_process!=NULL){
        queue_add(arriving_process, MLF_queues[0]);
    }
    return running_process;
}

/**
 * is called once after the all processes were handled. In case you want to cleanup something
 */
void MLF_finish(){
    // TODO
    free(MLF_queues);
}
