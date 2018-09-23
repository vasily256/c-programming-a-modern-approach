/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

/* stack2.c (Chapter 19, page 489) */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define PRIVATE static
#define PUBLIC /* empty */

PUBLIC struct node {
  int data;
  struct node *next;
};

PRIVATE struct node *top = NULL;

PRIVATE void terminate(const char *message)
{
  printf("%s\n", message);
  exit(EXIT_FAILURE);
}

PRIVATE void make_empty(void)
{
  while (!is_empty())
    pop();
}

PRIVATE bool is_empty(void)
{
  return top == NULL;
}

PRIVATE bool is_full(void)
{
  return false;
}

PRIVATE void push(int i)
{
  struct node *new_node = malloc(sizeof(struct node));
  if (new_node == NULL)
    terminate("Error in push: stack is full.");

  new_node->data = i;
  new_node->next = top;
  top = new_node;
}

PRIVATE int pop(void)
{
  struct node *old_top;
  int i;

  if (is_empty())
    terminate("Error in pop: stack is empty.");

  old_top = top;
  i = top->data;
  top = top->next;
  free(old_top);
  return i;
}
