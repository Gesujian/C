#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LEN sizeof(struct myword)

struct myword
{
    int     num;
    char   *word;
   	struct  myword  *next;    /*  ָ����һ���ڵ� */
};


void  main()
{
    FILE * input;
    struct myword * words_link;
    char  find_word();
    void save_word(struct myword * words_link);
    char  infile_name[]={"test.txt"}, outfile_name[]={"output.txt"};
    if ((input = fopen(infile_name, "r")) == NULL)  //  ���ļ�
    {
        printf("���ļ�ʧ��\n");
        exit(0);
    }
    //  ѭ����ȡһ�У��ҳ���һ�еĵ���
    words_link = find_word(input);
    save_word(words_link);
    fclose(input)  ;                   //  �ر��ļ�
}


struct myword  *find_word(FILE * input)
{
    /* ����input�ı�
    �����������*/
    char ch;
    struct myword * head;
    while (! feof(input))
    {
        ch = fgetc(input);
        printf("%c",ch);
        if (is_alphatet(ch))
        {
            printf("����ĸ");
        }
    }
    return (head)
}

void save_word(struct myword * words_link)
{
    /*���뵥������
    ������������ļ��У�ͬʱ��¼���ʸ���*/
}

int is_alphatet(char ch)
{
    if (ch>=65 && ch<=90) return 1;
    else if (ch>=97 & ch<=122) return 1;
    else return 0;
}
