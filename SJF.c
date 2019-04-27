#include <stdlib.h>
#include "scheduler.h"
#include <stdlib.h>

ProcessInfo **pq;
int curr_num_process;
int active_process;

void set_strategy_SJF() {
     pq = (ProcessInfo**)malloc(sizeof(ProcessInfo*) * num_process);
     curr_num_process = 0;
}

static ProcessInfo** PQ;
static ProcessInfo** tail;

void set_strategy_SJF() {
    PQ = (ProcessInfo **)malloc(num_process * sizeof(ProcessInfo *));
    tail = PQ;
}

void add_process_SJF(ProcessInfo *new_process) {
    pq[cur_num_process] = new_process;
    cur_num_process++;
}

void remove_curr_process_SJF(void) {
     pq[curr_num_process-1] = NULL;
     curr_num_process--;
     sys_log_process_end();
}

int smallest_process(void) {
     if(curr_num_process <= 0) return -1;
     int smallest = 0;
     for(int i = 0; i < curr_num_process; i++) {
          if(pq[i]->remaining_time < pq[smallest]->remaining_time) smallest = i;
     }
     return smallest;
}

void run_process(int ind) {
     while(pq[ind]->remaining_time) {

     }
}

void context_switch_SJF(void) {
    if(scheduler_empty_SJF()) {
         int new_active_process_ind = smallest_process();
         run_process(new_active_process_ind);
    }
}

bool scheduler_empty_SJF(void) {
     return curr_num_process == 0;
}
