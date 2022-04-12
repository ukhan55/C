#include "headers.h"

int main(void) {
	sentence *sentencePtr = malloc(sizeof(sentence*));
	/* sentencePtr is the main variable which points to the beginning of sentences
	 * Any processing on the user input can be done using this pointer by
	 * looping over it as per the defined structs/typedef
	 */
	int totalNumberOfSentences = processInput(&sentencePtr);
	// total number of sentences is helpful to determine so that we know the size of the pointer

	//print each word in a separate line
	printWordsInSeperateLine(totalNumberOfSentences, sentencePtr);
	// print each line discarding extra spaces
	printInputLinesWithoutExtraSpaces(totalNumberOfSentences, sentencePtr);
	//Asks the user for search word and searches that word in the whole list of sentences entered by the user
	//reports all occurences.  Till the user enters empty line resulting in the exit of main program
	executeSearchWordsUtility(totalNumberOfSentences, sentencePtr);
	return 0;
}
