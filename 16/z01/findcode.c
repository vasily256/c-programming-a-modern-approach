#include <stdio.h>
#include <stdlib.h>
#include "codes.h"

int find_code(int code, int index);

int main(void)
{
    int code, index = 0;
 
    printf("Enter country code (0 - exit): ");
    scanf("%d", &code); 
    if (code == 0)
        return 0; 
    while ((index = find_code(code, index)) < num_codes)
        puts(country_codes[index++].country); 
    return 0;
}

int find_code(int code, int index)
{
    int initial_index = index;

    for (; index < num_codes; index++)
        if (country_codes[index].code == code)
            return index;

    if (initial_index == 0) {
        printf("Code not found\n");
        exit(EXIT_SUCCESS);
    }
}
