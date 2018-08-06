#include <stdio.h>

int main(void)
{
    int age;
    
    printf("How old are you? (years): ");
    scanf("%d", &age);
    
    if (13 <= age && age <= 19) {
        printf("You are teenager\n");
    } else {
        printf("You aren't teenager\n");
    }
    
    return 0;
}
