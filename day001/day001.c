#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils/readFile.h"

char **day001ParseInput(char *input, int *size)
{
  int lines = 0;
  for (int i = 0; input[i] != '\0'; i++)
  {
    if (input[i] == '\n')
      lines++;
  }

  char **data = (char **)malloc(lines * sizeof(char *));
  int index = 0;
  char *line = strtok(input, "\n");

  while (line != NULL)
  {
    data[index++] = line;
    line = strtok(NULL, "\n");
  }

  *size = lines;
  return data;
}

int day001Part001(char **data, int length)
{
  int pos = 50;
  int count = 0;

  for (int i = 0; i < length; i++)
  {
    char turn = data[i][0];
    int dist = atoi(&data[i][1]);

    pos += turn == 'L' ? -dist : dist;
    pos = ((pos % 100) + 100) % 100;

    if (pos == 0)
    {
      count += 1;
    }
  }

  return count;
}

int day001Part002(char **data, int length)
{
  int pos = 50;
  int count = 0;

  for (int i = 0; i < length; i++)
  {
    char turn = data[i][0];
    int dir = (turn == 'L') ? -1 : 1;
    int dist = atoi(&data[i][1]);

    for (int step = 0; step < dist; step++)
    {
      pos += dir;
      if (pos == 0 || pos % 100 == 0)
      {
        count += 1;
      }
    }
    pos = ((pos % 100) + 100) % 100;
  }

  return count;
}

int main()
{
  printf("=== Advent of Code 2025 ===\n");

  char *testInput = readFile("./day001/testInput.txt");
  int testSize;
  char **testData = day001ParseInput(testInput, &testSize);

  char *input = readFile("./day001/input.txt");
  int size;
  char **data = day001ParseInput(input, &size);

  printf("Day 001 - Test 001: %d\n", day001Part001(testData, testSize));
  printf("Day 001 - Part 001: %d\n", day001Part001(data, size));
  printf("Day 001 - Test 002: %d\n", day001Part002(testData, testSize));
  printf("Day 001 - Part 002: %d\n", day001Part002(data, size));

  free(testInput);
  free(testData);
  free(input);
  free(data);

  return 0;
}