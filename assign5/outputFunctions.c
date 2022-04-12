void deleteLines(sentence *sentencePtr){
	int lineNumberToDelete;
	char *lineNumberToDeleteString;
	sentence *firstSentence = sentencePtr;
	printf("Enter line number to delete : ");
	getchar();
    scanf("%m[^\n]s", &lineNumberToDeleteString);
	getchar(); 
     while(lineNumberToDeleteString!=NULL) {
	    int lineNumberToDelete = atoi(lineNumberToDeleteString);
	    int totalNumberOfLines = getNumberOfLines(firstSentence);
	    if(lineNumberToDelete > totalNumberOfLines || totalNumberOfLines <1){
		    printf("Line number doesnt exists\n");
		    printf("Enter line number to delete : ");
		   	scanf("%m[^\n]s", &lineNumberToDeleteString);
		    getchar();
			continue;
		}

	    sentence *prevSentencePtr=NULL;
	    sentence *sentenceToDeletePtr = firstSentence;
	    for(int i=1;i<lineNumberToDelete;i++){
	    	prevSentencePtr= sentenceToDeletePtr;
	    	sentenceToDeletePtr = sentenceToDeletePtr->nextSentence;
	    }
	    if(prevSentencePtr==NULL)
	    	firstSentence = firstSentence->nextSentence;
	    else
	    	prevSentencePtr->nextSentence = sentenceToDeletePtr->nextSentence;

	    updateSentenceNumbers(firstSentence);
		printInputLinesWithoutExtraSpaces(firstSentence);
		printf("\n");
	    printf("Enter line number to delete : ");
	    scanf("%m[^\n]s", &lineNumberToDeleteString);
         getchar();
	}
}
void updateSentenceNumbers(sentence *firstSentence){
	sentence *currSentence = firstSentence;
	int lineNumber = 1;
	while(currSentence!=NULL){
		currSentence->lineNumber= lineNumber;
		currSentence = currSentence->nextSentence;
		lineNumber++;
	}

}

int getNumberOfLines(sentence *sentencePtr){
	int lineCount = 0;
	while(sentencePtr!=NULL){
		lineCount++;
		sentencePtr = sentencePtr->nextSentence;
	}
	return lineCount;
}


// The following is called to input the word from the user and it searches in the whole sentence
void executeSearchWordsUtility(sentence *sentencePtr) {
	sentence *firstSentencePtr = sentencePtr;
	char *searchWord; // This will point to the word to be searched
	do {
		printf("Enter a word to search : ");
		scanf("%m[^\n]s", &searchWord);
		if (searchWord == NULL) // Exit on empty line
			break;
		getchar();
		sentence *currSentencePtr = firstSentencePtr;
		bool flag = false; // Determines whether the word was found in the sentences or not
		    while(currSentencePtr!=NULL){
			if (find_word(searchWord, currSentencePtr))
				flag = true;
			currSentencePtr=currSentencePtr->nextSentence;
		}
		if (!flag) { // Default message to show if the word was not found in the sentences
			printf("%s was not found in this file\n", searchWord);
		}
		printf("\n");
	} while (searchWord != NULL); // iterate till user enters empty line
}

// This prints all the sentences that user inputs removing the extra spaces
void printInputLinesWithoutExtraSpaces(sentence *sentencePtr) {
	while(sentencePtr!=NULL){
		print_sentence(sentencePtr);
		sentencePtr = sentencePtr->nextSentence;
	}
	printf("\n");
}

// find all occurences of the word in the sentence and print the details appropriately
// returns false if the word was not found in the sentence.
// returns true if at least one occurrence is found
bool find_word(char *searchWord, sentence *sentencePtr) {
    	bool flag = false;
     	word *wordPtr = sentencePtr->wordPtr;
	    while(wordPtr!=NULL){
		if (strcmp(searchWord, wordPtr->charPtr) == 0) { // check if the current word equals the search word
			flag = true; // if yes then set flag to true
			printf("%s found in line %d position %d\n", searchWord,
					sentencePtr->lineNumber,
					wordPtr->positionInSentence);
		}
		wordPtr=wordPtr->nextWord;
	}
	return flag;
}
// Loop over each word of sentence and print it with single space in one line
void print_sentence(sentence *sentencePtr) {
	bool flag = true;
	word* wordPtr = sentencePtr->wordPtr;
    while(wordPtr!=NULL) {
    	!flag ? printf(" ") : 1;
		printf("%s", wordPtr->charPtr);
        wordPtr = wordPtr->nextWord;
        flag=false;
    }
	printf("\n");
}

void freeSpace(sentence *sentencePtr){
	sentence* currSentence=sentencePtr;
	while(currSentence!=NULL){
       word *currWord = currSentence->wordPtr;
       while(currWord!=NULL){
    	   word *nextWord = currWord->nextWord;
    	   free(currWord);
    	   currWord = nextWord;
       }
       sentence* nextSentence = currSentence->nextSentence;
       free(currSentence);
       currSentence = nextSentence;
}
}

