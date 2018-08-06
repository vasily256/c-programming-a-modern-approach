#include <stdio.h>
#define S 5
#define Q 5

int main(void)
{
    int grade[S] [Q] = {0};
    int stud_score[S] = {0};
    int quiz_score[Q] = {0};
    int student, quiz, temp;
    
    for (student = 0; student < S; student++) {
        printf("Enter grades of student %d: ", student + 1);
        for (quiz = 0; quiz < Q; quiz++) {
            scanf("%d", &grade[student] [quiz]);
        }
    }
    
    printf("\nStudents:     ");
    for (student = 1; student <= S; student++) {
        printf(" %8d", student);
    }
    
    printf("\nTotal score:  ");
    for (student = 0; student < S; student++) {
        for (quiz = 0; quiz < Q; quiz++) {
            stud_score[student] += grade[student] [quiz];
        }
        printf(" %8d", stud_score[student]);
    }
    
    printf("\nAverage score:");
    for (student = 0; student < S; student++) {
        printf(" %8.1f", (double) stud_score[student] / Q);
    }
    
    printf("\n\nQuiz:         ");
    for (quiz = 1; quiz <= S; quiz++) {
        printf(" %8d", quiz);
    }
    
    for (quiz = 0; quiz < Q; quiz++) {
        for (student = 0; student < S; student++) {
            quiz_score[quiz] += grade[student] [quiz];
        }
    }
    
    printf("\nAverage score:");
    for (quiz = 0; quiz < Q; quiz++) {
        printf(" %8.1f", (double) quiz_score[quiz] / S);
    }
    
    printf("\nHigh score:   ");
    for (quiz = 0; quiz < Q; quiz++) {
        for (student = 0, temp = grade [student] [quiz]; student < S; student++) {
            if (grade [student] [quiz] > temp) {
                temp = grade [student] [quiz];
            }
        }
        printf(" %8d", temp);
    }
    
    printf("\nLow score:    ");
    for (quiz = 0; quiz < Q; quiz++) {
        for (student = 0, temp = grade [student] [quiz]; student < S; student++) {
            if (grade [student] [quiz] < temp) {
                temp = grade [student] [quiz];
            }
        }
        printf(" %8d", temp);
    }
    
    printf("\n");
    
    return 0;
}
