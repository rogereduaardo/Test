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

  if (child_pid)
  {
    printf("\nPARENT: Waiting on child\n");
    wait(NULL);
    printf("PARENT: Child complete!\n");
  }
  else
  {
    printf("CHILD:\n");
    char *argv[] = {"/bin/ls", "-l", NULL};
    char *envp[] = {NULL};
    int result = execve("/bin/ls", argv, envp);
    if (-1 == result)
    {
      perror("execve");
    }
  }
  
  return 0;
}
