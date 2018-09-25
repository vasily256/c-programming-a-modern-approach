/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

/* readline.c (Chapter 16, page 395) */
/* modified for ex.4 of ch.19 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "readline.h"

#define INITIAL_LENGTH 10

static char *resize(char *str, int n)
{
  char *tmp_ptr = realloc(str, n * sizeof(char));
  assert(tmp_ptr != NULL);

  return tmp_ptr;
}

char *read_line(void)
{
  int ch, n = INITIAL_LENGTH, i = 0;
  char *str = malloc(n * sizeof(char));
  assert(str != NULL);

  while (isspace(ch = getchar()))
    ;
  while (ch != '\n' && ch != EOF) {
    if (i < n)
      str[i++] = ch;
    else
      str = resize(str, n *= 2);
    ch = getchar();
  }
  str[i] = '\0';
  return resize(str, i + 1);
}
