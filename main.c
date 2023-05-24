#include <stdio.h>

#include <sys/types.h>
#include <unistd.h>

#include <stdlib.h>

#include <sys/wait.h>

int main(void) {
  printf("Process Demos\n");
  printf("Code by Roger Martinez\n\n");

  pid_t pid = getpid();
  printf("pid: %d\n", pid);

  pid_t ppid = getppid();
  printf("ppid: %d\n\n", ppid);

  int result = system("ps");
  printf("result: %d\n", result);

  result = system("pstree");
  printf("result: %d\n", result);
  
  pid_t child_pid = fork();
  if (-1 == child_pid)
  {
    perror("fork");
    return 1;
  }

  if (0 == child_pid)
  {
    printf("CHILD! pid: %d, ppid: %d\n", getpid(),getppid());
    sleep(5);
    return 42;
  }
  else
  {
    printf("\nPARENT! pid: %d, ppid: %d, chil_pid: %d\n", getpid(),               getppid(),child_pid);
    int wait_status = 0;
    pid_t pid = wait(&wait_status);
    printf("\nPARENT: Returned from wait: pid: %d\n", pid);
    printf("PARENT: child exit status: %d", WEXITSTATUS(wait_status));
  }
  
  return 0;
}
