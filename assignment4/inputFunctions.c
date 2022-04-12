/* Initial function which reads the sentences entered by the user until an empty line is entered
 * This builds up the word and sentence structs dynamically.
 * There is no array element used here
 * Returns the number of lines user entered and intializes the sentencePtr to
 * the sentences that have been input
 */
int processInput(sentence **sentencePtrPtr) {
	int lineNumber = 1;
	char *line;
	do {
		printf("Enter sentence : ");
		scanf("%m[^\n]s", &line); // m - specifies that the space should be allocated dynamically and [^\n] specifies to stop scanning on new line
		getchar(); // The above scanf doesnt read the new line character so we discard that with this call so as to process next line afresh
		if (line == NULL)
			break;

		char *token = strtok(line, " "); // break the sentence into words skipping spaces
		word *wordPtr = malloc(sizeof(word*));
		int position = 1;
		// Fill up the words in the sentences one by one
		while (token != NULL) {
			word *wordPtr2 = malloc(sizeof(word*));
			wordPtr2->charPtr = token;
			wordPtr2->numOfCharInWord = strlen(token);
			wordPtr2->positionInSentence = position;
			*(wordPtr + position - 1) = *wordPtr2;
			token = strtok(NULL, " ");
			wordPtr = realloc(wordPtr, (position + 1) * sizeof(word));
			position++;
		}
		sentence *Tsentence = malloc(sizeof(sentence*));
		Tsentence->wordPtr = wordPtr;
		Tsentence->lineNumber = lineNumber;
		Tsentence->numWordsInLine = position - 1;
		*(*sentencePtrPtr + lineNumber - 1) = *Tsentence;
		*sentencePtrPtr = realloc(*sentencePtrPtr,
				(lineNumber + 1) * sizeof(sentence));
		lineNumber++;
	} while (line != NULL); // line is NULL when user inputs an empty line
	return lineNumber - 1;
}
