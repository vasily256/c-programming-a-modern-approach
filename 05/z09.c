#include <stdio.h>

int main(void)
{
    int mm0, dd0, yy0;
    int mm1, dd1, yy1;
    int min_dd, min_mm, min_yy;
    int max_dd, max_mm, max_yy;
    
    printf("Enter first date (mm/dd/yy): ");
    scanf("%d/%d/%d", &mm0, &dd0, &yy0);
    printf("Enter second date (mm/dd/yy): ");
    scanf("%d/%d/%d", &mm1, &dd1, &yy1);
    
    if (yy0 < yy1) {
        min_dd = dd0; min_mm = mm0; min_yy = yy0;
        max_dd = dd1; max_mm = mm1; max_yy = yy1;
    } else if (yy1 < yy0) {
        min_dd = dd1; min_mm = mm1; min_yy = yy1;
        max_dd = dd0; max_mm = mm0; max_yy = yy0;
    } else if (mm0 < mm1) {
        min_dd = dd0; min_mm = mm0; min_yy = yy0;
        max_dd = dd1; max_mm = mm1; max_yy = yy1;
    } else if (mm1 < mm0) {
        min_dd = dd1; min_mm = mm1; min_yy = yy1;
        max_dd = dd0; max_mm = mm0; max_yy = yy0;
    } else if (dd0 < dd1) {
        min_dd = dd0; min_mm = mm0; min_yy = yy0;
        max_dd = dd1; max_mm = mm1; max_yy = yy1;
    } else if (dd1 < dd0) {
        min_dd = dd1; min_mm = mm1; min_yy = yy1;
        max_dd = dd0; max_mm = mm0; max_yy = yy0;
    }
    
    if (dd0 == dd1 && mm0 == mm1 && yy0 == yy1)
        printf("%d/%d/%.2d is the same as %d/%d/%.2d.\n", mm0, dd0, yy0, mm1, dd1, yy1);
    else printf("%d/%d/%.2d is earlier than %d/%d/%.2d.\n", min_mm, min_dd, min_yy, max_mm, max_dd, max_yy);
    
    return 0;
}
