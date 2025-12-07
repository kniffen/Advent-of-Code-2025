#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils/readFile.h"

void day003CountRowsAndColumns(char *input, int *rows, int *columns)
{
  char *token = strtok(input, "\n");
  *rows = 0;
  *columns = strlen(token);
  while (token != NULL)
  {
    (*rows)++;
    token = strtok(NULL, "\n");
  }
}
void day003ParseInputStr(char *input, int rows, int columns, int batteries[rows][columns])
{
  char *inputCpy = strdup(input);
  char *token = strtok(inputCpy, "\n");
  int y = 0;
  while (token != NULL)
  {
    for (int x = 0; x < columns; x++)
    {
      int n = token[x] - '0';
      batteries[y][x] = n;
    }
    y++;
    token = strtok(NULL, "\n");
  }
}

int day003Part001(char *input)
{
  int rows;
  int columns;
  day003CountRowsAndColumns(strdup(input), &rows, &columns);

  int batteries[rows][columns];
  day003ParseInputStr(input, rows, columns, batteries);

  int sum = 0;
  for (int y = 0; y < rows; y++)
  {
    int num = -1;
    for (int x = 0; x < columns - 1; x++)
    {
      for (int z = x + 1; z < columns; z++)
      {
        int newNum = batteries[y][x] * 10 + batteries[y][z];
        if (newNum > num)
        {
          num = newNum;
        }
      }
    }
    sum += num;
  }

  return sum;
}

int main()
{
  printf("=== Advent of Code 2025 ===\n");

  char *testInput = readFile("./day003/testInput.txt");
  char *input = readFile("./day003/input.txt");

  printf("Day 003 - Test 001: %d\n", day003Part001(testInput));
  printf("Day 003 - Part 001: %d\n", day003Part001(input));

  free(testInput);
  free(input);

  return 0;
}