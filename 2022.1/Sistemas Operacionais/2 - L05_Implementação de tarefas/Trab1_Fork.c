/*
          D
        /  \
       A    N
           / 
          I 
         / 
        E
         \
          L
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
  pid_t pid;
  int status = 0;

  printf("proc-D, pid %d, ppid %d, acaba de ser criado\n", getpid(), getppid());

  pid = fork();
  if(pid==0){
    printf("proc-A, pid %d, ppid %d, acaba de ser criado\n", getpid(), getppid());
    printf("proc-A, pid %d, e morreu\n", getpid());
    exit(0);
  }

  pid = fork();
  if (pid == 0){
    printf("proc-N, pid %d, ppid %d, acaba de ser criado\n", getpid(), getppid());

    pid = fork();
    if (pid == 0)
    {
      printf("proc-I, pid %d, ppid %d, acaba de ser criado\n", getpid(), getppid());

      pid = fork();
      if(pid == 0){
        printf("proc-E, pid %d, ppid %d, acaba de ser criado\n", getpid(), getppid());

        pid = fork();
        if(pid == 0){
            printf("proc-L, pid %d, ppid %d, acaba de ser criado\n", getpid(), getppid());
            printf("proc-L, pid %d, e morreu\n", getpid());
            exit(0);
        }
        else{
          waitpid(pid, &status, 0);
          printf("proc-E, pid %d, e morreu\n", getpid());
          exit(0);
        }
      }
      else{
        waitpid(pid, &status, 0);
        printf("proc-I, pid %d, e morreu\n", getpid());
        exit(0);
      }
    }
    else{
      waitpid(pid, &status, 0);
      printf("proc-N, pid %d, e morreu\n", getpid());
      exit(0);
    }
  }
  else{
    waitpid(pid, &status, 0);
    printf("proc-D, pid %d, e morreu\n", getpid());
    exit(0);
  }

  return 0;
}