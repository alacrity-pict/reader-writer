#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include"read.h"
#include"init.h"

void *reader(){
	FILE *f1;
	int ch;
	printf("\nReader is Trying To Enter...");
	sem_wait(&rc);
	readcount=readcount+1;
		if(readcount==1){
			sem_wait(&db);
			printf("\nI GOT THE LOCK...");
		}
	sem_post(&rc);

	printf("\nReader Inside..");
	f1=fopen("BUFFER.TXT","r");	
		ch=fgetc(f1);
		printf("%c",ch);
	sleep(2);	
	fclose(f1);
	
	
	sem_wait(&rc);
	readcount=readcount-1;
		if(readcount==0){
			sem_post(&db);
		}
	sem_post(&rc);
	printf("\nReader is Leaving...");
}

