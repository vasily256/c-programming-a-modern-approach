#include <stdio.h>

int main(void)
{
    int gs1_pref, group_id, pub_code, it_num, ch_dig;
    
    printf("Enter ISBN: ");
    scanf("%d-%d-%d-%d-%d", &gs1_pref, &group_id, &pub_code, &it_num, &ch_dig);
    
    printf("GS1 preffix: %d\nGroup identifier: %d\nPublisher code: %d\nItem number: %d\nCheck digit: %d\n", gs1_pref, group_id, pub_code, it_num, ch_dig);
    
    return 0;
}
