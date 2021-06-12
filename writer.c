#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main (int argc, char *argv[])
{
  FILE * file;
  file = fopen(argv[1], "w+");
  int file_descriptor = fileno(file);
  
  int size = 0;
  int fact_size = 0;
  int zero_counter = 0;
  while (!feof(stdin))
  {
    char value = fgetc(stdin);
    if (value == 0)
      zero_counter++;
    else
    {
      if (zero_counter > 0)
      {
        lseek(file_descriptor, zero_counter, SEEK_CUR);
        zero_counter = 0;
      }

      char buffer[1];
      buffer[0] = value;
      
      write(file_descriptor, buffer, 1);
      fact_size++;
    }
    size++;    
  }

  return 0;
}