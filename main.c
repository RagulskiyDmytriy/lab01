#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

void print_header();
void print_row_border();
void print_row(unsigned int N, double X, double function_result);
void clear_screen();
double calculate_function(double X);
void print_table(unsigned int N, double delta);

int main()
{
    int variant;
    do
    {
        printf("VVedit 1 abo 2\n");
        scanf("%d", &variant);

    } while (!(variant == 1 || variant == 2));

    double X1;
    double X2;
    unsigned int N;
    double delta;

    printf("X1 = ");
    scanf("%lf", &X1);

    printf("X2 = ");
    scanf("%lf", &X2);

    if (variant == 1)
    {
        printf("N = ");
        scanf("%d", &N);
      	clear_screen();
        printf("X1 = %.2f, X2 = %.2f, N = %d\n", X1, X2, N);

      	delta = (X2 - X1) / N;

    }
    else if(variant == 2)
    {
        printf("delta = ");
        scanf("%lf", &delta);
  		clear_screen();
        printf("X1 = %.2f, X2 = %.2f, delta = %.2f\n", X1, X2, delta);

      	N = (X2 - X1) / delta;
    }

	print_table(N, delta);

    return 0;
}

void print_header()
{
	printf("*****************************************************************\n");
  	printf("* N       *               X       *                      F(X)   *\n");
  	printf("*****************************************************************\n");
  	print_row_border();
}

void print_row_border()
{
  	printf("+---------+-----------------------+-----------------------------+\n");
}

void print_row(unsigned int N, double X, double function_result)
{
  	printf("|%7d  |%21.2f  |%27.2f  |\n", N, X, function_result);
  	print_row_border();
}

void clear_screen()
{
  	system("CLS");
}

double calculate_function(double X)
{
  	return sin(X) - cos(X) * 2;
}

void print_table(unsigned int N, double delta)
{
	const int MAX_N = 10;
	print_header();
	for (int i = 1; i <= N; i++)
	{
		print_row(i, i * delta, calculate_function(i * delta));
	  	if ((i % MAX_N == 0) && (i != N))
	    {
	      printf("Press any key to continue...");
	      getch();
	      clear_screen();
  		  print_row_border();
	    }
	}
}
