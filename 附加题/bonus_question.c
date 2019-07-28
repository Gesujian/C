#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LEN sizeof(struct myword)

struct myword
{
    int     num;
    char   *word;
   	struct  myword  *next;    /*  指向下一个节点 */
};


void  main()
{
    FILE * input;
    struct myword * words_link;
    char  find_word();
    void save_word(struct myword * words_link);
    char  infile_name[]={"test.txt"}, outfile_name[]={"output.txt"};
    if ((input = fopen(infile_name, "r")) == NULL)  //  打开文件
    {
        printf("打开文件失败\n");
        exit(0);
    }
    //  循环读取一行，找出这一行的单词
    words_link = find_word(input);
    save_word(words_link);
    fclose(input)  ;                   //  关闭文件
}


struct myword  *find_word(FILE * input)
{
    /* 输入input文本
    输出单词链表*/
    char ch;
    struct myword * head;
    while (! feof(input))
    {
        ch = fgetc(input);
        printf("%c",ch);
        if (is_alphatet(ch))
        {
            printf("是字母");
        }
    }
    return (head)
}

void save_word(struct myword * words_link)
{
    /*输入单词链表
    将单词输出到文件中，同时记录单词个数*/
}

int is_alphatet(char ch)
{
    if (ch>=65 && ch<=90) return 1;
    else if (ch>=97 & ch<=122) return 1;
    else return 0;
}
