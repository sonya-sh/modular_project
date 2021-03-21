/*
 * Author: Sheblova Sonya
 *
 * c:
 * The calculator performs the following operations:
 * Addition, subtraction, multiplication, division,
 * factorial of a number, exponentiation of a number.
 *
 * v:
 * The calculator performs the following operations with vectors:
 * Addition, subtraction, scalar product
 *
 * After completion, you are prompted to restart the program.
 *
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

	float x, y, rez;
	float *a, *b;
	int i, st, size;
	long int f, S;
	char n, c, choose, sgn;
	f = 1;
	S = 1;
	do {
		printf(" c - operations with numbers\n v - operations with vectors\n");
		printf("choose: ");
		scanf("%s", &choose);
		switch (choose) {
		case 'c':
			printf(
					" + - addition\n - - subtraction\n * - multiplication\n / - division\n");
			printf(" ! - factorial\n ^ - exponentiation\n");
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
			break;
		case 'v':
			printf(" + - addition\n - - subtraction\n * - scalar product\n");
			printf("size: ");
			scanf("%i", &size);
			a = malloc(size * sizeof(float));
			b = malloc(size * sizeof(float));
			printf("a:\n");
			for (int i = 0; i < size; i++) {
				scanf("%f", &a[i]);
			}
			printf("b:\n");
			for (int i = 0; i < size; i++)
				scanf("%f", &b[i]);

			printf("sign: ");
			scanf("%s", &sgn);

			switch (sgn) {

			case '+':
				printf("( ");
				for (int i = 0; i < size; i++)
					printf("%.2f ", a[i]);
				printf(") + ( ");
				for (int i = 0; i < size; i++)
					printf("%.2f ", b[i]);
				printf(") = ( ");
				for (int i = 0; i < size; i++)
					printf("%.2f ", a[i] + b[i]);
				printf(")");
				break;

			case '-':
				printf("( ");
				for (int i = 0; i < size; i++)
					printf("%.2f ", a[i]);
				printf(") - ( ");
				for (int i = 0; i < size; i++)
					printf("%.2f ", b[i]);
				printf(") = ( ");
				for (int i = 0; i < size; i++)
					printf("%.2f ", a[i] - b[i]);
				printf(")");
				break;

			case '*':
				printf("( ");
				for (int i = 0; i < size; i++)
					printf("%.2f ", a[i]);
				printf(") * ( ");
				for (int i = 0; i < size; i++)
					printf("%.2f ", b[i]);
				printf(") = ");
				for (int i = 0; i < size; i++)
					rez += a[i] * b[i];
				printf("%.2f ", rez);
				break;

			default:
				printf("Unknown operation");
			}
			free(a);
			free(b);
			break;
		default:
			printf("try again");
			printf("\n");
			break;
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
