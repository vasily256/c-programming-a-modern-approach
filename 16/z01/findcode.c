#include <stdio.h>
#include "codes.h"

#if 0
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#endif

int find_code(int code, int index);

int main(void)
{
    int code, index = 0;

    printf("Enter country code (0 - exit): ");
    scanf("%d", &code);

    while (code != 0 && index < num_codes) {
        index = find_code(code, index);
        puts(country_codes[index].country);
    }

    return 0;
}
