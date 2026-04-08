#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queue_simulation.h"

/* global variables definition */
int current_time = 0;
int new_job_id = 0;
int current_job_id = 0;
int remaining_time = 0;
int total_wait_time = 0;
int num_printed_jobs = 0;

QueueNode* front = NULL;
QueueNode* rear = NULL;

/*
    addq
    Insert a job at the rear of the linked queue.
*/
void addq(Job e)
{
    QueueNode* temp;

    temp = (QueueNode*)malloc(sizeof(QueueNode));
    if (temp == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    temp->item = e;
    temp->link = NULL;

    if (front == NULL) {
        front = rear = temp;
    }
    else {
        rear->link = temp;
        rear = temp;
    }
}

/*
    deleteq
    Remove and return the job at the front of the queue.
    This function assumes the queue is not empty.
*/
Job deleteq()
{
    QueueNode* temp;
    Job item;

    temp = front;
    item = temp->item;
    front = front->link;

    if (front == NULL) {
        rear = NULL;
    }

    free(temp);
    return item;
}

/*
    is_queue_empty
    Return true if queue is empty.
*/
boolean is_queue_empty()
{
    if (front == NULL)
        return true;
    else
        return false;
}

/*
    queue_show
    Print the ids of jobs currently waiting in the queue.
*/
void queue_show()
{
    QueueNode* p;

    printf("Current queue: ");

    if (is_queue_empty()) {
        printf("empty\n");
        return;
    }

    p = front;
    while (p != NULL) {
        printf("<%d> ", p->item.id);
        p = p->link;
    }
    printf("\n");
}

/*
    random0
    Return a random double value in [0.0, 1.0].
*/
double random0()
{
    return rand() / (double)RAND_MAX;
}

/*
    get_random_duration
    Return a random integer in [1, MAX_PRINTING_TIME].
*/
int get_random_duration()
{
    return (int)(MAX_PRINTING_TIME * random0()) + 1;
}

/*
    is_job_arrived
    Return true with probability JOB_ARRIVAL_PROB.
*/
boolean is_job_arrived()
{
    if (random0() < JOB_ARRIVAL_PROB)
        return true;
    else
        return false;
}

/*
    is_printer_idle
    Return true if printer is idle.
*/
boolean is_printer_idle()
{
    if (remaining_time <= 0)
        return true;
    else
        return false;
}

/*
    insert_job_into_queue
    Make a new Job and insert it into the queue.
*/
void insert_job_into_queue(int id, int arrival_time, int duration)
{
    Job p;

    p.id = id;
    p.arrival_time = arrival_time;
    p.duration = duration;

    addq(p);

    printf("A new job <%d> has arrived. duration = %d\n", id, duration);
}

/*
    process_next_job
    Delete the next job from the queue and start printing it.

    waiting time = current_time - arrival_time
    remaining_time = duration - 1
    because one unit of printing starts at the current time.
*/
void process_next_job()
{
    Job p;

    p = deleteq();

    current_job_id = p.id;
    remaining_time = p.duration - 1;
    total_wait_time = total_wait_time + (current_time - p.arrival_time);
    num_printed_jobs++;

    printf("Start printing job <%d>\n", current_job_id);
}

/*
    main
    Simulate printer queue.
*/
int main(void)
{
    int duration;

    srand((unsigned int)time(NULL));

    front = rear = NULL;
    remaining_time = 0;

    while (current_time < MAX_SIMUL_TIME) {
        printf("\n----- time %d -----\n", current_time);

        /* if a new job arrives, insert it into queue */
        if (is_job_arrived()) {
            new_job_id++;
            duration = get_random_duration();
            insert_job_into_queue(new_job_id, current_time, duration);
        }

        /* if printer is idle, start next job */
        if (is_printer_idle()) {
            if (!is_queue_empty()) {
                process_next_job();
            }
            else {
                printf("Printer is idle.\n");
            }
        }
        /* if printer is busy, continue printing */
        else {
            printf("Printing job <%d> ... remaining time : %d\n",
                current_job_id, remaining_time);
            remaining_time--;
        }

        queue_show();
        current_time++;
    }

    printf("\n===== Simulation Result =====\n");
    printf("Number of printed jobs = %d\n", num_printed_jobs);

    if (num_printed_jobs > 0)
        printf("Average waiting time = %.2f\n",
            (double)total_wait_time / num_printed_jobs);
    else
        printf("Average waiting time = 0.00\n");

    return 0;
}