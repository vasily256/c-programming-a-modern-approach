/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

/* remind2.c (Chapter 17, page 418) */
/* Prints a one-month reminder list (dynamic string version) */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_REMIND 50   /* maximum number of reminders */
#define MSG_LEN 60      /* max length of reminder message */

struct vstring {
  int len;
  char chars[];
};

void Vread_line(struct vstring *vstr, int n);
int Vstrcmp(const struct vstring *vstr1, const struct vstring *vstr2);
void Vstrcpy(struct vstring *vstr1, const struct vstring *vstr2);

int main(void)
{
  struct vstring *reminders[MAX_REMIND]; 
  struct vstring *day_str = malloc(sizeof(struct vstring) + 3);
  day_str->len = 3;
  struct vstring *msg_str = malloc(sizeof(struct vstring) + MSG_LEN);
  msg_str->len = MSG_LEN;
  int day, i, j, num_remind = 0;

  for (;;) {
    if (num_remind == MAX_REMIND) {
      printf("-- No space left --\n");
      break;
    }

    printf("Enter day and reminder: ");
    scanf("%2d", &day);
    if (day == 0)
      break;
    sprintf(day_str->chars, "%2d", day);
    day_str->len = 2;
    Vread_line(msg_str, MSG_LEN);

    for (i = 0; i < num_remind; i++)
      if (Vstrcmp(reminders[i], day_str) > 0)
        break;
    for (j = num_remind; j > i; j--)
      reminders[j] = reminders[j-1];

    reminders[i] = malloc(sizeof(struct vstring) + day_str->len + msg_str->len);
    if (reminders[i] == NULL) {
      printf("-- No space left --\n");
      break;
    }

    Vstrcpy(reminders[i], day_str);
    Vstrcat(reminders[i], msg_str);

    num_remind++;
  }

  printf("\nDay Reminder\n");
  for (i = 0; i < num_remind; i++)
    printf(" %s\n", reminders[i]);

  return 0;
}

void Vread_line(struct vstring *vstr, int n)
{
  int ch, i = 0;

  while ((ch = getchar()) != '\n')
    if (i < n)
      vstr->chars[i++] = ch;
  vstr->len = i;
}

int Vstrcmp(const struct vstring *vstr1, const struct vstring *vstr2)
{
  int i = 0;
  bool equal = true;

  for (;  equal == true && i < vstr1->len && i < vstr2->len; i++)
    if (vstr1->chars[i] != vstr2->chars[i]) {
      equal = false;
    }
  if (equal == true)
    if (vstr1->len > vstr2->len)
      return 1;
    else if (vstr1->len == vstr2->len)
      return 0;
    else
      return -1;
  else
    if (vstr1->chars[i] > vstr2->chars[i])
      return 1;
    else
      return -1;
}

Vstrcpy(struct vstring *vstr1, const struct vstring *vstr2)
{
  int i;

  for(i = 0; i < vstr1->len; i++)
    vstr1->chars[i] = vstr2->chars[i];
  vstr1->len = i;
}
