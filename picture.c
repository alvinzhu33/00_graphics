#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

int main(){
  int fd = open("image.ppm", O_CREAT | O_WRONLY | 0644);
  char buffer[50];
  sprintf(buffer, "P3 500 500 255\n");
  write(fd, buffer, sizeof(buffer));

  int x, y, r, g, b;
  x = 0;
  y = 0;
  while(y < 500){
    while(x < 500){
      sprintf(buffer, "0 255 255\n");
      write(fd, buffer, sizeof(buffer));

      x++;
    }
    x=0;
    y++;
  }

  close(fd);

  return 0;
}
