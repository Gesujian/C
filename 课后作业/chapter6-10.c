#include <stdio.h>
void main()
{
    /*qwertyuiopasdfghjklzxcvbnm1234567890  -=QWERTYUIOPASDFGHJKLZXCVBNM1234567890  -=
    �ܹ���
    26*3��Сд
    26*3����д
    20*3������
    4*3���ո�
    4*3�������ַ�
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
    printf("��д��ĸ�� %d��\n", upper_case);
    printf("Сд��ĸ�� %d��\n", lower_case);
    printf("������     %d��\n", number);
    printf("�ո���     %d��\n", blank_space);
    printf("�����ַ��� %d��\n", others);
}
