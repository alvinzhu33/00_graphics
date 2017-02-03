#include <fcntl.h>

int main(){
  int fd = open("image.ppm", O_CREAT | O_WRONLY | 0644);
  char * buffer = "P3 500 500 255\n";
  write(fd, buffer, sizeof(buffer));
  
  int x, y, r, g, b;
  x = 0;
  y = 0;
  while(y < 10){
    while(x < 10){
      buffer = "0 255 255\n";
      write(fd, buffer, sizeof(buffer));

      x++;
    }
    x=0;
    y++;
  }

  close(fd);

  return 0;
}
