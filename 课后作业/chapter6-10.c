#include <stdio.h>
void main()
{
    /*qwertyuiopasdfghjklzxcvbnm1234567890  -=QWERTYUIOPASDFGHJKLZXCVBNM1234567890  -=
    总共：
    26*3个小写
    26*3个大写
    20*3个数字
    4*3个空格
    4*3个其他字符
    */
    char filename[]={"chapter6-10.txt"}, str[81];
    FILE *fp;
    int i,j;
    int upper_case=0, lower_case=0, number=0, blank_space=0, others=0;
    fp = fopen(filename, "r");
    fgets(str, 81, fp);
    for (j=0; j<3; j++)
    {
        for (i=0; i<80; i++)
        {
            //printf("%c\n", str[i]);
            if (str[i]>=65 && str[i]<=90) upper_case+=1;
            else if (str[i]>=97 && str[i]<=122) lower_case+=1;
            else if (str[i]>=48 && str[i]<=57) number+=1;
            else if (str[i]==32) blank_space+=1;
            else others+=1;
        }
    }
    fclose(fp);
    printf("大写字母有 %d个\n", upper_case);
    printf("小写字母有 %d个\n", lower_case);
    printf("数字有     %d个\n", number);
    printf("空格有     %d个\n", blank_space);
    printf("其他字符有 %d个\n", others);
}
