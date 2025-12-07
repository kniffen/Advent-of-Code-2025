#include <stdio.h>

char *readFile(char filePath[])
{
  FILE *file;
  char *data;
  int size;

  file = fopen(filePath, "r");

  fseek(file, 0, SEEK_END);
  size = ftell(file) * sizeof(char) + 1;
  rewind(file);

  data = (char *)malloc(size);
  fread(data, sizeof(char), size, file);
  data[size] = '\0';
  fclose(file);

  return data;
}