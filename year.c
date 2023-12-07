#include <stdio.h>
#define MONTHS 12
int main()
{
    int month;
    char choice;


    /* do while循环的使用 */
    do{

    printf("请输入想查询的月份：");
    scanf("%d", &month);
    int days[MONTHS] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
   
    printf("%d月有%d天\n", month, *(days + (month - 1)));
    printf("是否继续查询？输入 '1' 继续，其他字符退出： ");
        scanf(" %c", &choice);

    }while(choice == '1');
    
    return 0;
}