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
  int max_len;
  int len;
  char chars[];
};

void Vread_line(struct vstring *vstr);
int Vstrcmp(const struct vstring *vstr1, const struct vstring *vstr2);
struct vstring *Vstrcpy(struct vstring *vstr1, const struct vstring *vstr2);
struct vstring *Vstrcat(struct vstring *vstr1, const struct vstring *vstr2);
void Vputs(struct vstring *vstr);

int main(void)
{
  int day, i, j, num_remind = 0;
  struct vstring *reminders[MAX_REMIND]; 
  struct vstring *day_str = malloc(sizeof(struct vstring) + 3);
  if (day_str == NULL) {
    printf("malloc: allocation failed\n");
    return 0;
  }
  day_str->max_len = 3;
  struct vstring *msg_str = malloc(sizeof(struct vstring) + MSG_LEN);
  if (msg_str == NULL) {
    printf("malloc: allocation failed\n");
    return 0;
  }
  msg_str->max_len = MSG_LEN;

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
    day_str->len = strlen(day_str->chars);
    Vread_line(msg_str);

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
    reminders[i]->max_len = day_str->len + msg_str->len;

    Vstrcpy(reminders[i], day_str);
    Vstrcat(reminders[i], msg_str);

    num_remind++;
  }

  printf("\nDay Reminder\n");
  for (i = 0; i < num_remind; i++) {
    putchar(' ');
    Vputs(reminders[i]);
  }

  return 0;
}

void Vread_line(struct vstring *vstr)
{
  int ch, i = 0;

  while ((ch = getchar()) != '\n')
    if (i < vstr->max_len)
      vstr->chars[i++] = ch;
  vstr->len = i;
}

int Vstrcmp(const struct vstring *vstr1, const struct vstring *vstr2)
{
  int i = 0;
  bool equal = true;

  for (;  equal == true && i < vstr1->len && i < vstr2->len; i++) {
    if (vstr1->chars[i] != vstr2->chars[i]) {
      equal = false;
    }
  }
  if (equal == true)
    if (vstr1->len > vstr2->len)
      return 1;
    else if (vstr1->len == vstr2->len)
      return 0;
    else
      return -1;
  else
    if (vstr1->chars[i-1] > vstr2->chars[i-1])
      return 1;
    else
      return -1;
}

struct vstring *Vstrcpy(struct vstring *vstr1, const struct vstring *vstr2)
{
  int i;

  for(i = 0; i < vstr1->max_len && i < vstr2->len; i++)
    vstr1->chars[i] = vstr2->chars[i];
  vstr1->len = i;

  return vstr1;
}

struct vstring *Vstrcat(struct vstring *vstr1, const struct vstring *vstr2)
{
  int i, j;

  for(i = vstr1->len, j = 0; i < vstr1->max_len && j < vstr2->len; i++, j++)
    vstr1->chars[i] = vstr2->chars[j];
  vstr1->len = i;

  return vstr1;
}
void Vputs(struct vstring *vstr)
{
  for (int i = 0; i < vstr->len; i++)
    putchar(vstr->chars[i]);
  putchar('\n');
}
