/* Initial function which reads the sentences entered by the user until an empty line is entered
 * This builds up the word and sentence structs dynamically.
 * There is no array element used here
 * Returns the number of lines user entered and intializes the sentencePtr to
 * the sentences that have been input
 */
sentence* processInput() {
	int lineNumber = 1;
	char *line;
	sentence *prevSentence;
	sentence *currSentence;
	sentence *firstSentence;
	do {
		printf("Enter sentence : ");
		scanf("%m[^\n]s", &line); // m - specifies that the space should be allocated dynamically and [^\n] specifies to stop scanning on new line
		getchar(); // The above scanf doesnt read the new line character so we discard that with this call so as to process next line afresh
		if (line == NULL)
			break;

		char *token = strtok(line, " "); // break the sentence into words skipping spaces
		word* prevWord;
		word* firstWord;
		int position = 1;
		// Fill up the words in the sentences one by one
		while (token != NULL) {
			word *wordPtr = malloc(sizeof(word*));
			wordPtr->charPtr = token;
			wordPtr->numOfCharInWord = strlen(token);
			wordPtr->positionInSentence = position;
			if(position!=1) {
		      prevWord->nextWord = wordPtr;
		      prevWord = wordPtr;
			}
			if(position==1) {
		       prevWord  = wordPtr;
		       firstWord = wordPtr;
			}
			token = strtok(NULL, " ");
			position++;
		}

		currSentence = malloc(sizeof(sentence*));
		currSentence->wordPtr = firstWord;
		currSentence->lineNumber = lineNumber;
		currSentence->numWordsInLine = position - 1;
		if(lineNumber!=1){
		    prevSentence->nextSentence=currSentence;
		    prevSentence = currSentence;
		}
		if(lineNumber==1){
		    prevSentence = currSentence;
		    firstSentence = currSentence;
		}
		lineNumber++;
	} while (line != NULL); // line is NULL when user inputs an empty line
	currSentence->nextSentence=NULL;
	return firstSentence;
}
