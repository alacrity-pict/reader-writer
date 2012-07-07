#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include"nikita1.h"
sem_t db,rc;
int readcount=0;
FILE * fp;
void initialize()
{
	sem_init(&db,0,1);
	sem_init(&rc,0,1);
}

