// The following is called to input the word from the user and it searches in the whole sentence
void executeSearchWordsUtility(int totalNumberOfSentences,
		sentence *sentencePtr) {
	char *searchWord; // This will point to the word to be searched
	do {
		printf("Enter a word to search : ");
		scanf("%m[^\n]s", &searchWord);
		if (searchWord == NULL) // Exit on empty line
			break;
		getchar();
		bool flag = false; // Determines whether the word was found in the sentences or not
		for (int i = 0; i < totalNumberOfSentences; i++) {
			sentence _sentence = *(sentencePtr + i);
			if (find_word(searchWord, _sentence))
				flag = true;
		}
		if (!flag) { // Default message to show if the word was not found in the sentences
			printf("%s was not found in this file\n", searchWord);
		}
		printf("\n");
	} while (searchWord != NULL); // iterate till user enters empty line
}

// prints all the words in a separate line
void printWordsInSeperateLine(int totalNumberOfSentences, sentence *sentencePtr) {
	printf("This is all the words printed out one line at a time :\n");
	for (int i = 0; i < totalNumberOfSentences; i++) {
		sentence Tsentence = *(sentencePtr + i); // Gets the ith sentence starting from 0 and prints words in that sentence
		print_words(Tsentence);
	}
	printf("\n");
}

// This prints all the sentences that user inputs removing the extra spaces
void printInputLinesWithoutExtraSpaces(int totalNumberOfSentences,
		sentence *sentencePtr) {
	printf(
			"This is all the words printed out on the same line as entered : \n");
	for (int i = 0; i < totalNumberOfSentences; i++) {
		sentence _sentence = *(sentencePtr + i); // Gets the ith sentence starting from 0 and prints words in that sentence
		print_sentence(_sentence);
	}
	printf("\n");
}

// find all occurences of the word in the sentence and print the details appropriately
// returns false if the word was not found in the sentence.
// returns true if at least one occurrence is found
bool find_word(char *searchWord, sentence _sentence) {
	bool flag = false;
	int numOfWord = _sentence.numWordsInLine;
	word *Tword = _sentence.wordPtr;
	for (int i = 0; i < numOfWord; i++) { // loop over each word in the sentence
		word *wordInsideSentence = Tword + i;
		if (strcmp(searchWord, wordInsideSentence->charPtr) == 0) { // check if the current word equals the search word
			flag = true; // if yes then set flag to true
			printf("%s found in line %d position %d\n", searchWord,
					_sentence.lineNumber,
					wordInsideSentence->positionInSentence);
		}
	}
	return flag;
}
// Loop over each word of sentence and print it with single space in one line
void print_sentence(sentence _sentence) {
	char *words;
	int numOfWord = _sentence.numWordsInLine;
	word *wordPtr = _sentence.wordPtr;
	for (int i = 0; i < numOfWord; i++) {
		i != 0 ? printf(" ") : 1; // This is done to avoid space in the beginning
		printf("%s", (wordPtr + i)->charPtr);
	}
	printf("\n");
}

// loop over each word of sentence and print each on a new line
void print_words(sentence _sentence) {
	char *words;
	int numOfWord = _sentence.numWordsInLine;
	word *wordPtr = _sentence.wordPtr;
	for (int i = 0; i < numOfWord; i++) {
		printf("%s\n", (wordPtr + i)->charPtr); // gets the ith word in the sentence
	}
}
