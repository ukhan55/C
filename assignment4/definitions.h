#ifndef DEFINITIONS_H_
#define DEFINITIONS_H_

typedef struct word {
	char *charPtr;
	int numOfCharInWord;
	int positionInSentence;
} word;

typedef struct sentence {
	word *wordPtr;
	int lineNumber;
	int numWordsInLine;
} sentence;

void print_sentence(sentence);
void print_words(sentence);
bool find_word(char*, sentence);
void executeSearchWordsUtility(int, sentence*);
void printWordsInSeperateLine(int, sentence*);
void printInputLinesWithoutExtraSpaces(int, sentence*);
int processInput(sentence**);


#endif /* DEFINITIONS_H_ */
