#include <stdio.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <sys/io.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <types.h>

int main(int argc, char const *argv[]){
  unsigned char *f;
  size_t size;
  struct stat s;
  const char * filename = argv[1];
  int fd = open(argv[1],O_RDONLY);
  int status = fstat(fd,&s);
  size = s.st_size;
  f = mmap(0,size,PROT_READ,MAP_PRIVATE, fd, 0);
  int o = 0;
  printf("Filesize:%d %02x\n",size,f[o]);
  int o_copy = o;
  while(o_copy<size)
    (o_copy%16==0?printf("\n"):o_copy), o_copy==o ? printf(ANSI_COLOR_RED"%02x",f[o_copy++]):printf(ANSI_COLOR_RESET"%02x",f[o_copy++]);
  return 0;
}
