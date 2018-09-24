#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>


void sigUsr(int signal){
	if (signal == SIGUSR1){
		printf("sig usr1");
	}
	
	if (signal == SIGUSR2){
		printf("sigusr2");
	}
	
}

void P1(int pid){
	printf("s11");
	sleep(1);
	kill(pid,SIGUSR1);
	printf("s12");
	pause();
	printf("s13");
}

void P2(){
	int p = fork();
	
	if (p > 0){
		printf("s21");
		pause();
		printf("s22");
		kill(getppid(),SIGUSR2);
		wait((int*)0);
		printf("s24");
	} else {
		printf("s22");
		exit(0);
	}
	
}

int main(int argc,char* argv[]){
	
	signal(SIGUSR1,sigUsr);
	signal(SIGUSR2,sigUsr);
	
	int pid;
	
	printf("s20");
	
	if ((pid = fork()) == 0){
		P2();
		wait((int*)0);
	} else {
		P1(pid);
		exit(0);
	}
	
	printf("s25");
	return(0);
}



















