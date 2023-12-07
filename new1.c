#include <stdio.h>
#include <string.h>

#define MAX_STRING_LENGTH 100
#define ARRAY_SIZE 5

int main() {
    char myStrings[ARRAY_SIZE][MAX_STRING_LENGTH];  // 二维数组，存储5个字符串
    int i, searchIndex = -1;
    char searchName[MAX_STRING_LENGTH];
    char newName[MAX_STRING_LENGTH];
    char choice;

    // 循环接收用户输入并存储在数组中
    for (i = 0; i < ARRAY_SIZE; ++i) {
        printf("请输入第%d个字符串: ", i + 1);
        fgets(myStrings[i], MAX_STRING_LENGTH, stdin);
        myStrings[i][strcspn(myStrings[i], "\n")] = '\0';  // 去除末尾的换行符
    }
    
    do {
        // 提示用户输入要查询的字符串
        printf("请输入要查询的字符串: ");
        fgets(searchName, MAX_STRING_LENGTH, stdin);
        searchName[strcspn(searchName, "\n")] = '\0';  // 去除末尾的换行符

        // 查询数组中是否存在输入的字符串
        for (i = 0; i < ARRAY_SIZE; ++i) {
            if (strcmp(myStrings[i], searchName) == 0) {
                searchIndex = i;
                break;
            }
        }

        // 显示查询结果
        if (searchIndex != -1) {
            printf("找到字符串 \"%s\"，位于数组的第%d个位置。\n", searchName, searchIndex + 1);

            // 提示用户输入新的字符串
            printf("请输入新的字符串: ");
            fgets(newName, MAX_STRING_LENGTH, stdin);
            newName[strcspn(newName, "\n")] = '\0';  // 去除末尾的换行符

            // 修改数组中的字符串
            strncpy(myStrings[searchIndex], newName, MAX_STRING_LENGTH - 1);
            myStrings[searchIndex][MAX_STRING_LENGTH - 1] = '\0';

            printf("数组已更新，新的字符串为: %s\n", myStrings[searchIndex]);
        } else {
            printf("未找到字符串 \"%s\"。\n", searchName);
        }

        printf("是否继续查询？输入 '1' 继续，其他字符退出： ");
        scanf(" %c", &choice);

        // 清空输入缓冲区，以防止影响下一次输入
        while (getchar() != '\n');

        // 重置searchIndex
        searchIndex = -1;

    } while (choice == '1');

    return 0;
}