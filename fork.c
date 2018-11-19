#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

int main(){
  srand(time(NULL));
  int q = rand()%15*5;
  int qw = rand()%15*5;
  if(fork()){
    if(fork()){
      int status; 
      int cpid = wait(&status); 
      printf("%d ran for %d seconds.\n",cpid,WEXITSTATUS(status));
      return 0;
    }
    else{
      printf("%d\n",getpid());
      sleep(q);
      printf("%d is finished\n", getpid());
      return q;
    }
  }
  else{
      printf("%d\n",getpid());
      sleep(qw);
      printf("%d is finished\n", getpid());
      return qw;
  }
  int status; 
  int cpid = wait(&status); 
  printf("%d ran for %d seconds.\n",cpid,WEXITSTATUS(status));
  printf("parent process done");
  return 0;
}
