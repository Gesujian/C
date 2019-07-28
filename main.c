#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LEN sizeof(struct myword)

struct myword
{
    int     num;
    char    *word;
   	struct  myword  *next;    /*  ָ����һ���ڵ� */
};


void  main()
{
	/*��ȡinfile_name�ļ�����find_words�ҵ����ʣ��洢��head�������������������ļ�*/ 
	void print_link_to_file(struct myword *head);     //����������ļ� 
	struct myword *find_words(FILE *input);           //�ҵ��ʣ������������ 
	void destory_word(struct myword *head);
    char  infile_name[]={"test.txt"};
    struct myword *head;
    FILE *input;
    input = fopen(infile_name, "r");                  //���ļ� 
    if (input == NULL)
    {
        printf("���ļ�%sʧ��\n",infile_name);
        exit(0);
    }
    head = find_words(input);                         //�ҵ��� 
    fclose(input);                                    //�ر��ļ� 
    print_link_to_file(head);                         //������������ļ� 
    destory_word(head);
}

void print_link_to_file(struct myword *head)
{
	/*�������������������������input.txt*/ 
	printf("NOW,print LINK  to File......\n");
	struct myword *p;
	FILE  *output;
	char outfile_name[]={"output.txt"};
	output = fopen(outfile_name, "w");
    if (output == NULL)
    {
        printf("���ļ�%sʧ��\n",outfile_name);
        exit(0);
    }
    p = head->next;
    do
    {
        fprintf(output,"%s,%d\n",p->word,p->num);
        p = p->next;
    }while(p!=NULL);
    fclose(output);
    printf("print to file Done!\n");
 }
 
struct myword * new_word(char word[]) 
 {
 	/*����һ���������飬����һ��myword�ṹ��*/
 	struct myword *tmp;
 	char *t_word;
 	tmp=(struct myword *) malloc(LEN);                //��һ���µĽڵ�����ռ� 
 	//��̬����һ���ռ�������myword->word����Ϊ�Ȿ���Ǹ�ָ�룬��Ҫָ��һ������������
    t_word = (char *) malloc(strlen(word));
    strcpy(t_word,strlwr(word));
    tmp->word = t_word;
    tmp->num = 1;
    tmp->next=NULL;
    return tmp;
 }
 
struct myword *instert_word(struct myword *tmp,struct myword *head)
 {
 	/*���µ�tmp�ڵ���뵽head��Ӧ��λ��
 	->�������нڵ� 
	 # head��             �ŵ���һ���ڵ�
	 # �뵱ǰ�ڵ���ͬ     ��ǰ�ڵ��num+1
	 # �ȵ�ǰ�ڵ��       �������һ���ڵ�С������ڵ�ǰ�ڵ��
	                      �������һ���ڵ�� ���������һ���ڵ� 
	 # �ȵ�һ���ڵ�С     ���ڵ�һ���ڵ�ǰ��ͷ����
	 					����Ϊ����������ģ�������һ����д�����
						 �ں��治���ڱȵ�ǰ�ڵ�С������� 
	 */ 
 	struct myword *cur;
	if (head==NULL)
	{
		head = (struct myword *) malloc(LEN);
		head->next = tmp;
	}
	else
	{
		cur = head->next;
		while (cur!=NULL)
		{
			if (strcmp(tmp->word,cur->word)<0)
			{
				//С�ڵ�һ��ֵ ,��Ϊ������������ȵ�һ��С���Ǿ�����С�� 
				tmp->next = cur;
				head->next = tmp;
				break;
			}
			if (strcmp(tmp->word,cur->word)==0)
			{
				//���ڵ�ǰֵ 
				cur->num++;
				free(tmp);                        //����ڵ��Ѿ����ڣ��ͷ�tmp�ռ� 
				break;
			}
			else if (strcmp(tmp->word,cur->word)>0)
			{	
				//���ڵ�ǰֵ 
				if (cur->next!=NULL)// && (tmp->word,cur->next->word)<0
				{
					//���治Ϊ�� 
					if (strcmp(tmp->word,cur->next->word)<0)
					{
						//С����һ��ֵ ,���뵱ǰ�ڵ�֮�� 
						tmp->next = cur->next;
						cur->next = tmp;
						break; 
					}
					//���ڵ�����һ��ֵ 
					cur = cur->next;
				}
				else
				{
					//����Ϊ�� 
					cur->next= tmp; 
					break; 
				}
			} 
		}
	}
	return head;
 }
 
struct myword *find_words(FILE *input)
{
	/*�����ļ�ָ�룬�ҵ����ʣ������������������ͷhead��
	���ļ���һ���ַ�һ���ַ��Ķ�ȡ�����������ĸ�������
	�ַ������У�ֱ����������ĸ�� 
	��������ĺ������'\0',�Դ����ָ������е�
	���ʣ���Ϊǰһ�����ʿ��ܱȵ�ǰ���ʳ��� 
	�������еľ���һ�����ʣ�
	���ɽڵ㣬��������Ӧλ�á� 
	���ַ����鱣�浱ǰ����*/ 
	printf("start find Words....\n");
	struct myword *head, *tmp;
	struct myword *instert_word(struct myword *tmp,struct myword *head);  //����ڵ�
	struct myword *new_word(char word[]);  //����һ���µĽڵ㣬����ָ�� 
	char ch;
	char word[25];
	int i=0;
	head = NULL;
	
	while (! feof(input))
    {
    	ch = fgetc(input);
	    if ((ch>=65 && ch <=90) || (ch>=97 && ch <=122))
	    {
	        word[i]=ch;
	        i++;
	    }
	    else
	    {
	        word[i]='\0';
	        if (strlen(word) !=0)
	        {
	            tmp = new_word(word);
	            head = instert_word(tmp,head);
			}	
			i=0;
		}
	}
	printf("find Words Done!\n");
	return head;
	
}

void destory_word(struct myword *head)
{
	printf("start free!\n");
	struct myword *tmp;
	while(head!=NULL)
    {
    	tmp = head;
    	head  = head->next;
    	free(tmp);
    }
    printf("Free Done!\n");
} 