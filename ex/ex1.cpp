#include<stdio.h>
int main(){
	extern void e_s(char str[]);
	extern void d_s(char *str, char c);
	extern void p_s(char *str);
	char c, str[80];
	c = '2';
	e_s(str);
	p_s(str);
	d_s(str, c);
	p_s(str);
	return 0;
}
