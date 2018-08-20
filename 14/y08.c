#include <stdio.h>

#define LINE_FILE_1 Line __LINE__ of file __FILE__
#define STRING(LINE_FILE_1) #LINE_FILE_1
#define STRING_1(LINE_FILE_1) STRING(LINE_FILE_1)
#define LINE_FILE STRING_1(LINE_FILE_1)

int main(void)
{
    const char *str = LINE_FILE;
    puts(str);

    return 0;
}
