#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include"write.h"
#include"init.h"



void *writer(){
	FILE *f1;
	int ch;
	printf("\nWriter is Trying To Enter...");
			
	sem_wait(&db);
	
	printf("\nWriter id Inside..");	
	f1=fopen("BUFFER.TXT","w");	
		ch='a'-rand()%32;
		fputc(ch,f1);
		printf("\nCharacter written : %c",ch);
	fclose(f1);	
	sleep(3);
	
	sem_post(&db);
	printf("\nWriter is Leaving...");
}
