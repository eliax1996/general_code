#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main(int argc,char*argv[]){
    char str[20];
    
    int n = atoi (argv[1]);
    
    if (n>=0 && fork()) { if (fork()>0) {
        sprintf (str, "%d", n);
        execlp ("echo", "echo", "n=", str, (char *) 0);
        if (fork()>0) {
            execlp (argv[0], argv[0], n-1, (char *) 0); }
    } else {
        sprintf (str, "%s %d", argv[0], n-1); printf ("%s\n", str);
        if (fork()>0) {
            system (str); }
    }
        
    }
    return (1);
}
