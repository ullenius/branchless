#include <stdio.h>

/* branchless percentual change */

void procent(double ny, double old) {

	int result = ny - old;
	int sign = result >> 31;
	printf("Sign: %d\n", sign);

	int smaller = sign ^ sign - (-sign); /* two's complement form */
	printf("Smaller = %d\n", smaller);

	printf("Smaller reversed... %d\n", smaller ^ 1);
	const double forandringsfaktor = (double) ny / (double) old;
	const double procent = ((1 - forandringsfaktor) * smaller) + ( (forandringsfaktor - 1) * (smaller ^ 1) );

	char symbol = (char) (43 + smaller + smaller); /* ASCII for + */
	printf("Procent: %c %f\n", symbol, procent * 100);
}


int main() {

	procent(100, 200);
	procent(300, 250);

    return 0;
}
