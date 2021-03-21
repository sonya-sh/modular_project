/*
 * Выполнила Шеблова Софья
 *
 * Калькулятор выполняет простейшие операции с двумя числами:
 * Сложение, вычитание, умножение, деление,
 * факториал числа, возведение числа в степень.
 * После завершения выводится запрос на повторную работу программы.
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	printf(
			" + - addition\n - - subtraction\n * - multiplication\n / - division\n");
	printf(" ! - factorial\n ^ - exponentiation\n");
	float x, y;
	int i, st;
	long int f, S;
	char c, n;
	f = 1;
	S = 1;
	do {
		printf("x = ");
		scanf("%f%*c", &x);
		printf("sign: ");
		scanf("%c%*c", &c);

		// операции с двумя числами
		if (c == '+' || c == '-' || c == '*' || c == '/') {
			printf("y = ");
			scanf("%f%*c", &y);
			printf("result:");
			switch (c) {
			case '+':
				printf("%.2f\n", x + y);
				break;
			case '-':
				printf("%.2f\n", x - y);
				break;
			case '*':
				printf("%.2f\n", x * y);
				break;
			case '/':
				if (y != 0)
					printf("%.2f\n", x / y);
				else
					printf("error\n");
				break;
			}
		} else {

			// операции с одним числом
			if (c == '!' || c == '^') {
				// вычисление факториала числа
				if (c == '!') {
					if (x < 0) {
						printf("error");
					} else {
						if (x == 0) {
							printf("0");
						} else {
							for (i = 1; i <= x; i++) {
								f *= i;
							}
							printf("result: %ld", f);
						}
					}
				} else {
					// возведение числа в степнь
					if (c == '^') {
						printf("st = ");
						scanf("%d", &st);
						for (i = 1; i <= st; i++) {
							S *= x;
						}
						printf("result: %ld", S);
					}
				}
			}
		}
		printf("\nDo you want to continue? (y/n)\n");
		scanf("%s", &n);

		while ((n != 'y') && (n != 'n')) {
			printf("Do you want to continue? (y/n)\n");
			scanf("%s", &n);
		}
	} while (n == 'y');
	return 0;
 }
