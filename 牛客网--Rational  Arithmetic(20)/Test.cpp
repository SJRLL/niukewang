输入：
5 / 3    0 / 6

输出：
1 2 / 3 + 0 = 1 2 / 3
1 2 / 3 - 0 = 1 2 / 3
1 2 / 3 * 0 = 0
1 2 / 3 / 0 = Inf

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void print(int num, int den);
int gcd(int a, int b);

int main()
{
	int num1, den1, num2, den2, num, den;
	scanf("%d/%d %d/%d", &num1, &den1, &num2, &den2);
	// 分别打印四则运算
	// 加法
	num = num1*den2 + num2*den1;
	den = den1*den2;
	print(num1, den1); printf(" + "); print(num2, den2);
	printf(" = "); print(num, den); printf("\n");
	// 减法
	num = num1*den2 - num2*den1;
	print(num1, den1); printf(" - "); print(num2, den2);
	printf(" = "); print(num, den); printf("\n");
	// 乘法
	num = num1*num2;
	print(num1, den1); printf(" * "); print(num2, den2);
	printf(" = "); print(num, den); printf("\n");
	// 除法
	num = num1*den2; den = num2*den1;
	print(num1, den1); printf(" / "); print(num2, den2);
	printf(" = "); print(num, den); printf("\n");
	return 0;
}

void print(int num, int den)
{
	int ggccdd = gcd(num, den);
	num = num / ggccdd;  den = den / ggccdd;
	long long p = num*den;
	num = abs(num); den = abs(den);
	if (p<0) {
		printf("(-");
	}
	if (num == 0) {
		printf("0");
	}
	else if (den == 0) {
		printf("Inf");
	}
	else {
		int intPart = num / den;
		if (intPart) {
			printf("%d", intPart);
		}
		int fracPart = num%den;
		if (fracPart) {
			if (intPart) printf(" ");
			printf("%d/%d", fracPart, den);
		}
	}
	if (p<0) {
		printf(")");
	}
}

int gcd(int a, int b)
{
	int c;
	while (b) {
		c = a%b;
		a = b; b = c;
	}
	return a;
}