/*
 * Author: Sheblova Sonya
 *
 * Version 1:
 * available operations with numbers such as addition, subtraction,
 * multiplication, division, exponentiation and factorial of a number.
 *
 * Version 2:
 * added vector operations such as vector addition,
 * vector subtraction, and scalar product of vectors.
 * At the beginning of the program, you are prompted to select the program mode:
 * s:operations with numbers
 * v:operations with vectors
 *
 * Version 3:
 * work with files is implemented. Input format: sign, s or v, number of coordinates for vectors, data.
 * example of input data for working with numbers: + s 2.3 -2
 * example of input data for working with vectors: - v 3 5 -2 0.1 9 105 0
 *
 * After completion, you are prompted to restart the program.
 *
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	float x, y, res;
	float *a, *b;
	int i, z, size;
	long int f, S;
	char n = 'y', choose, sign, in[100], out[100];
	f = 1;
	S = 1;
	FILE *input, *output;
	while (n == 'y') {
		printf("\nEnter input file name: ");
		scanf("%s", in);
		printf("Enter output file name: ");
		scanf("%s", out);

		input = fopen(in, "r");
		output = fopen(out, "w");
		while (feof(input) == 0) {
			fscanf(input, " %c", &sign);
			fscanf(input, " %c", &choose);

			switch (choose) {
			case 's':
				switch (sign) {
				case '+':
					fscanf(input, " %f %f", &x, &y);
					fprintf(output, "%.2f + %.2f = %.2f", x, y, x + y);
					break;
				case '-':
					fscanf(input, " %f %f", &x, &y);
					fprintf(output, "%.2f - %.2f = %.2f", x, y, x - y);
					break;
				case '*':
					fscanf(input, " %f %f", &x, &y);
					fprintf(output, "%.2f * %.2f = %.2f", x, y, x * y);
					break;
				case '/':
					fscanf(input, " %f %f", &x, &y);
					if (y != 0)
						fprintf(output, "%.2f / %.2f = %.2f", x, y, x / y);
					else
						fprintf(output, "error\n");
					break;
				case '!':
					fscanf(input, "%d", &z);
					if (z < 0) {
						fprintf(output, "error");
					} else {
						if (z == 0) {
							fprintf(output, "0");
						} else {
							for (i = 1; i <= z; i++) {
								f *= i;
							}
							fprintf(output, "%d! = %ld", z, f);
						}
					}
					break;
				case '^':
					fscanf(input, " %f %f", &x, &y);
					for (i = 1; i <= y; i++) {
						S *= x;
					}
					fprintf(output, "%.2f ^ %.2f = %.2ld", x, y, S);
					break;
				default:
					fprintf(output, "Unknown operation");
					break;
				}
				break;

			case 'v':
				fscanf(input, "%i", &size);
				a = malloc(size * sizeof(float));
				b = malloc(size * sizeof(float));
				for (int i = 0; i < size; i++) {
					fscanf(input, "%f", &a[i]);
				}
				for (int i = 0; i < size; i++)
					fscanf(input, "%f", &b[i]);

				switch (sign) {

				case '+':
					fprintf(output, "( ");
					for (int i = 0; i < size; i++)
						fprintf(output, "%.2f ", a[i]);
					fprintf(output, ") + ( ");
					for (int i = 0; i < size; i++)
						fprintf(output, "%.2f ", b[i]);
					fprintf(output, ") = ( ");
					for (int i = 0; i < size; i++)
						fprintf(output, "%.2f ", a[i] + b[i]);
					fprintf(output, ")");
					break;

				case '-':
					fprintf(output, "( ");
					for (int i = 0; i < size; i++)
						fprintf(output, "%.2f ", a[i]);
					fprintf(output, ") - ( ");
					for (int i = 0; i < size; i++)
						fprintf(output, "%.2f ", b[i]);
					fprintf(output, ") = ( ");
					for (int i = 0; i < size; i++)
						fprintf(output, "%.2f ", a[i] - b[i]);
					fprintf(output, ")");
					break;

				case '*':
					fprintf(output, "( ");
					for (int i = 0; i < size; i++)
						fprintf(output, "%.2f ", a[i]);
					fprintf(output, ") * ( ");
					for (int i = 0; i < size; i++)
						fprintf(output, "%.2f ", b[i]);
					fprintf(output, ") = ");
					for (int i = 0; i < size; i++)
						res += a[i] * b[i];
					fprintf(output, "%.2f ", res);
					break;

				default:
					fprintf(output, "Unknown operation");
				}
				free(a);
				free(b);
				break;

			default:
				fprintf(output, "Unknown operation");
				break;
			}
			fprintf(output, "\n");
		}
		fclose(input);
		fclose(output);

		printf("\nDo you want to continue? (y/n)\n");
		scanf("%s", &n);
		if (n == 'n') {
			printf("(^･ω･^)\n");
		}
	}
}

