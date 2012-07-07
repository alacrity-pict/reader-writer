#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>
#include"read.h"
#include"write.h"
#include"init.h"
pthread_t r[10],w[10];
int main(){
	int nw,nr,i;	
	initialize();
	printf("\nEnter the no readers : ");
	scanf("%d",&nr);
	printf("\nEnter the no Writers : ");
	scanf("%d",&nw);
	pthread_create(&w[0],NULL,writer,0);
	sleep(2);
	for(i=0;i<nr-1;i++){
		if(pthread_create(&r[i],NULL,reader,0)!=0){
			printf("\nError in creating readers");
		}
	}
	
	for(i=0;i<nw;i++){
		if(pthread_create(&w[i],NULL,writer,0)!=0){
			printf("\nError in creating readers");
		}
	}
	for(i=0;i<nr-1;i++){
		pthread_join(r[i],NULL);
	}
	for(i=0;i<nw;i++){
		pthread_join(w[i],NULL);
	}
	if(pthread_create(&r[nr-1],NULL,reader,0)!=0){
			printf("\nError in creating readers");
		}
	pthread_join(r[nr-1],NULL);
}
