#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int chil

int main(){
  if(!fork()){
    printf("%d",getpid());
  }
}
