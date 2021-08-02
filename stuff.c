#include <stdio.h>
#include <string.h>


char cipher_shift(char shift_letter, int shift_num) {

	// This is the alphabet
	const char alphabet[] = "abcdefghijklmnopqrstuvwxyz";

	// Number of letters in the alphabet
	// -1 because string has null terminate
	int num_letters = strlen(alphabet) - 1;

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


char *cipher_shift_wrapper(char *shift_word, int shift_num) {

	int i;
	for(i = 0; i < (strlen(shift_word)); i++) {
		shift_word[i] = cipher_shift(shift_word[i], shift_num);
	};

	return shift_word;

};


void main() {

	char shift_word[] = "abc";
	printf("%s", cipher_shift_wrapper(shift_word, 1));
};
