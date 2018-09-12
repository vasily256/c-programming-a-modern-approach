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
#include <stdlib.h>
#include <string.h>
#include "line.h"

#define MAX_LINE_LEN 10

struct word {
  char *word;
  struct word *next;
} *line = NULL, *end_of_line = NULL;

int line_len = 0;
int num_words = 0;

void exit_fail(void)
{
  //printf("%s function called\n", __func__);
    printf("malloc: allocation failed\n");
  //printf("%s function returns\n", __func__);
    exit(EXIT_FAILURE);
}

void clear_line(void)
{
  //printf("%s function called\n", __func__);
  struct word *tmp_ptr;

  while (line != NULL) {
    tmp_ptr = line->next;
    free(line->word);
    free(line);
    line = tmp_ptr;
  }
  end_of_line = NULL;

  line_len = 0;
  num_words = 0;
  //printf("%s function returns\n", __func__);
}

void add_word(const char *word)
{
  //printf("%s function called\n", __func__);
  struct word *p = malloc(sizeof(struct word));
  if (p == NULL)
    exit_fail();
  p->word = malloc(strlen(word) + 1);
  if (p->word == NULL)
    exit_fail();

  strcpy(p->word, word);
  p->next = NULL;

  if (end_of_line != NULL)
    end_of_line->next = p;
  else
    line = p;
  end_of_line = p;

  if (num_words > 0)
    line_len++;
  line_len += strlen(word);
  num_words++;
  //printf("%s function returns\n", __func__);
}

int space_remaining(void)
{
  //printf("%s function called\n", __func__);
  //printf("%s function returns\n", __func__);
  return MAX_LINE_LEN - line_len;
}

void write_line(void)
{
  //printf("%s function called\n", __func__);
  int extra_spaces, spaces_to_insert, j;
  int letters = 0; //

  extra_spaces = MAX_LINE_LEN - line_len;
  printf("%2d %2d ", line_len, extra_spaces);//
  for (struct word *p = line; p != NULL; p = p->next) {
    printf("%s ", p->word);
    letters += strlen(p->word);//
    if (num_words == 1)
      continue;
    spaces_to_insert = extra_spaces / (num_words - 1);
    //printf("_%d", spaces_to_insert);
    for (j = 1; j <= spaces_to_insert; j++)
      putchar(' ');
    extra_spaces -= spaces_to_insert;
    num_words--;
  }
  printf(" %d", letters);
  putchar('\n');
  //printf("%s function returns\n", __func__);
}

void flush_line(void)
{
  //printf("%s function called\n", __func__);
  if (line_len > 0)
    for (struct word *p = line; p != NULL; p = p->next)
      printf("%s ", p->word);
  putchar('\n');
  //printf("%s function returns\n", __func__);
}
