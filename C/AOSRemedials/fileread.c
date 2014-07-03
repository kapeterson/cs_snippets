#include <stdio.h>
#include <fcntl.h>

int main (int argc, char *argv[])
{
  printf("Hello\n");
  int fd = open("file1.txt", O_RDWR);
  
  int val;
  
  read(fd, &val, sizeof(int));
  printf("Value is %d\n",val);
  close(fd);
  return 0;
}
