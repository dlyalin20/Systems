#include<stdio.h>

int main() {

	// No new lines for printf

	int sample_int = 10000; // wow, an integer
	printf("Sample Integer: %d\n", sample_int); // String formatting!
	sample_int += 1; // incrementation

	int big_int = 2147483647; // biggest int
	printf("Big Int: %d\n", big_int);
	big_int += 1; // rolls over to negative
	printf("Small_Int: %d\n", big_int);

	float sample_float = 0.2; // floats, y'know?
	printf("Sample Float: %f\n", sample_float);
	printf("Testing Wrong Formatting (Float as Int): %d\n", sample_float); // Generates warning, but prints some kind of an int

	char sample_char = 'a';
	printf("Sample char: %c\n", sample_char);

	char sample_string[11] = "Hello world";
	printf("Sample string: %s\n", sample_string); // weird that strings are char arrays but it has a seperate formatter for strings

	unsigned int uitest = -2;
	printf("Negative Unsigned Int Test: %d\n", uitest); // seems to still allow -2?

	char longer[2] = "abc";
	printf("%s\n", longer); // warning, but only prints first two characters

}
