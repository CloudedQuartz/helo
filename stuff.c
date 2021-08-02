#include <stdio.h>
#include <string.h>


char cipher_shift(char shift_letter, int shift_num) {

	// This is the alphabet
	const char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
//	printf("%c\n", alphabet[sizeof(alphabet) - 2]);

	// Number of letters in the alphabet
	// -2 because string has null terminate
	int num_letters = sizeof(alphabet) - 2;

	char *tmp;
	int index;
	int i;

	// Don't waste time
	shift_num = shift_num % num_letters;

	for(i=0; i < shift_num; i++) {

		tmp = strchr(alphabet, shift_letter);
		index = (int)(tmp - alphabet);

		if (index == num_letters)
			index = 0;
		else
			index++;


		shift_letter = alphabet[index];
	};

	return shift_letter;
};

void main() {

	printf("%c", cipher_shift('z', 1));

};
