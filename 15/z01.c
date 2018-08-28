/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

/* line.c (Chapter 15, page 364) */

#include <stdio.h>
#include <string.h>
#include "line.h"

#define MAX_LINE_LEN 60

char line[MAX_LINE_LEN+1];
int line_len = 0;
int num_words = 0;

void clear_line(void)
{
  line[0] = '\0';
  line_len = 0;
  num_words = 0;
}

void add_word(const char *word)
{
  if (num_words > 0) {
    line[line_len] = ' ';
    line[line_len+1] = '\0';
    line_len++;
  }
  strcat(line, word);
  line_len += strlen(word);
  num_words++;
}

int space_remaining(void)
{
  return MAX_LINE_LEN - line_len;
}

//  Added new function
int spaces_to_insert(int *num_words, int *extra_spaces)
{
  int spaces = *extra_spaces / (*num_words - 1);
  *extra_spaces -= spaces;
  --*num_words;
  return spaces;
}

//  Modified function
void write_line(void)
{
  int extra_spaces, i, j, k = 0;
  int num_space[num_words - 1];
  int *ptr1 = num_space, *ptr2 = num_space + num_words - 2;

  extra_spaces = MAX_LINE_LEN - line_len;

  //    Calculates number of additional spaces
  for (;;) {
    *ptr1++ = spaces_to_insert(&num_words, &extra_spaces);
    if (ptr1 > ptr2)
        break;
    *ptr2-- = spaces_to_insert(&num_words, &extra_spaces);
    if (ptr1 > ptr2)
        break;
  }

  for (i = 0; i < line_len; i++) {
    if (line[i] != ' ')
      putchar(line[i]);
    else {
      for (j = 1; j <= num_space[k] + 1; j++)
        putchar(' ');
      k++;
    }
  }
  putchar('\n');
}

void flush_line(void)
{
  if (line_len > 0)
    puts(line);
}
