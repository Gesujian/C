#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int tmp[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
int *prime_list(int num){
	int *result, j = 0, i = 0;
	result = (int *)calloc(20,4);
	while (num != 1){
		while(num % tmp[i]) i++;
		num /= tmp[i];
		result[j] = tmp[i];
		j++;
	}

	return result;
}

int *find_match(int *p1, int *p2){
	int *result;
	result = (int *)calloc(20,4);
	int i = 0, j = 0, k = 0;
	//find the same integer in p1 and p2
	while(*(p1 + i) && *(p2 + j)){
		if (*(p1 + i) > *(p2 + j)){
			j++;
		}else if (*(p1 + i) < *(p2 + j)){
			i++;
		}else if (*(p1 + i) = *(p2 + j)){
			result[k] = *(p1 + i);
			i++;
			j++;
		}
	}

	return result;
}

int get_product(int *p){
	int result = 1;
	for (int i = 0; *(p + i); i++){
		result = *(p + i) * result;
	}
	return result;
}

int main(){
	//get two num;
	int n1, n2;
	scanf("%d%d", &n1, &n2);
	//get their primes_list
	int *p1, *p2;
	p1 = prime_list(n1);
	p2 = prime_list(n2);
	//get the matched nums in pl1&pl2
	int *result;
	result = find_match(p1,p2);
	//get these nums' product
	int k = get_product(result);
	printf("result = %d", k);
} 
