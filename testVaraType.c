#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main()
{

    /*变量的命名：数字，字母，下划线。只能以字母和下划线开头*/
    /*数据类型对应的是内存的存储空间*/
    int age = 6;
    int len =sizeof(age);      /*整形——整数*/

      /*%d,整数占位符*/
    printf("age = %d, len: %d\n", age, len);
    printf("hello world!\n");

#if 0    /*浮点数*/
    float weight = 50.5;
    float len1 =sizeof(weight);
    printf("len1: %f,weight = %f\n", len1, weight);
#else
    double weight =50.5;
    len = sizeof(weight);
    printf("len: %d, weight = %f\n", len, weight);
#endif
#if 1
    char sex = '-1';
    len = sizeof(sex);
    printf("len: %d, sex = %c, sex = %d\n", len, sex, sex);
   
   scanf();
    char default_value = 137;
    len = sizeof(default_value);
    printf("len: %d, default_value = %c, default_value = %d\n", len, default_value, default_value);
    
    
    /*无符号 和 有符号的区别*/
    unsigned char m_value = -2;
    len = sizeof(m_value);
    printf("len: %d, m_value: %c, m_value: %d\n", len, m_value, m_value);
#endif
#if 0
    int num = 5.5;
    printf("%d\n",num);

    int val = 10;
    printf("val:%d\n", val);

    val++;
    printf("val:%d\n", val);
    val--;
    printf("val:%d\n", val);
    --val;
    printf("val:%d\n", val);
    ++val;
    printf("val:%d\n", val);
    val += 100;
    printf("val:%d\n", val);
    

    int m_value1 = 10;
    int remainder = m_value1 % 3;

    printf("remainder:%d\n", remainder);



    int randomVal = rand();
    printf("%d\n",randomVal);
    

    int a = 5 << 1;   /*位运算，等效于*2，原理基于二进制*/



#endif

#if 0
    int val1 = 51;
    int orVal = val1 | 7;
    int andVal = val1 & 2;   /* 与 */

    printf("orVal1:%d\n", orVal);
    printf("andVal:%d\n", andVal);


    /* 非 */
    int notVal = !val1;
    printf("notVal:%d\n", notVal);
    
#endif
int condition1 = 1;
int condition2 = 6;

if((condition1 == 1) || (condition2 == 6)){
    printf("r");
} else{
    printf("w");
}  /* || 或*/
return 0;
}