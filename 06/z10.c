#include <stdio.h>

int main(void)
{
    int mm, dd, yy;
    int min_dd, min_mm, min_yy;
    
    printf("Enter a date (mm/dd/yy): ");
    scanf("%d/%d/%d", &mm, &dd, &yy);
    min_mm = mm;
    min_dd = dd;
    min_yy = yy;
    while (mm != 0 && dd != 0 && yy != 0) {
        if (yy < min_yy) {
            min_dd = dd;
            min_mm = mm;
            min_yy = yy;
        } else if (yy == min_yy) {
            if (mm < min_mm) {
                min_dd = dd;
                min_mm = mm;
                min_yy = yy;
            } else if (mm == min_mm) {
                if (dd < min_dd) {
                    min_dd = dd;
                    min_mm = mm;
                    min_yy = yy;
                }
            }
        }
        printf("Enter a date (mm/dd/yy): ");
        scanf("%d/%d/%d", &mm, &dd, &yy);
    }
    
    printf("%d/%d/%.2d is earliest date\n", min_mm, min_dd, min_yy);
    
    return 0;
}
