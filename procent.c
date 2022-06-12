#include <stdio.h>

/* branchless percentual change */

void percent(double new, double old) {

	const int diff = new - old;
	const int sign = diff >> 31;
	printf("Sign: %d\n", sign);

	const int smaller = sign ^ sign - (-sign); /* two's complement form */
	printf("Smaller = %d\n", smaller);

	printf("Smaller reversed... %d\n", smaller ^ 1);
	const double forandringsfaktor = (double) new / (double) old;
	const double percent = ((1 - forandringsfaktor) * smaller) + ( (forandringsfaktor - 1) * (smaller ^ 1) );

	const char symbol = (char) (43 + smaller + smaller); /* ASCII for + */
	printf("Percentage: %c %.2f %%\n", symbol, percent * 100);
}


int main() {
	percent(100, 200);
	percent(300, 250);

    return 0;
}
