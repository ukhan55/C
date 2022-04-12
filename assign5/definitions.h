#ifndef DEFINITIONS_H_
#define DEFINITIONS_H_

typedef struct word {
	char *charPtr;
	int numOfCharInWord;
	int positionInSentence;
	struct word *nextWord;
} word;

typedef struct sentence {
	word *wordPtr;
	int lineNumber;
	int numWordsInLine;
	struct sentence *nextSentence;
} sentence;

void print_sentence(sentence*);
bool find_word(char*, sentence*);
void executeSearchWordsUtility(sentence*);
void printWordsInSeperateLine(sentence*);
void printInputLinesWithoutExtraSpaces(sentence*);
void deleteLines(sentence*);
void updateSentenceNumbers(sentence*);
int getNumberOfLines(sentence*);
void freeSpace(sentence*);
sentence* processInput();


#endif /* DEFINITIONS_H_ */
