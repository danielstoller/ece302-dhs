#include <string>
#include <vector>
#include <iostream>
#include "FindPalindrome.hpp"

using namespace std;

//------------------- HELPER FUNCTIONS -----------------------------------------

// non-class helper functions go here, should be declared as "static" so that
// their scope is limited

//helper function that turns a vector of strings into a string. This string can have upper and lower cases
static string toString(vector<string> vect){
	string stringVector;

	for(int i=0; i<vect.size(); i++)
		stringVector += vect[i]; 

	return stringVector;
}
	

// helper function to convert string to lower case
//This function permenantly changes a word
static void convertToLowerCase(string & value)
{
	for (int i=0; i<value.size(); i++) {
		value[i] = tolower(value[i]);
	}
}

//------------------- PRIVATE CLASS METHODS ------------------------------------

// private recursive function. Must use this signature!
void FindPalindrome::recursiveFindPalindromes(vector<string> candidateStringVector, vector<string> currentStringVector)
{
	int wordsLeft = currentStringVector.size();

	//Set newCandidate equal to the candidateStringVector from the parameter
	vector<string> newCandidate = candidateStringVector;
	string newWord;
	vector<string> newCurrent;

	int j=0;
	//Recursive function ends if the currentStringVector is empty
	if(wordsLeft>0){
	//This loop will recursively call n times with n being the amount of words that are left in currentStringVector
	for(int i=0; i<wordsLeft; i++){
		
		

		//Copy over all the words in currentStringVector except for the one at the i'th index
		for(int j=0; j<wordsLeft; j++){
			newWord = currentStringVector[j];
			if(j!=i)
				newCurrent.push_back(newWord);
		}

		//Push the word at the i'th index onto candidateStringVector. This will return back to normal after i++
		newWord = currentStringVector[i];
		newCandidate.push_back(newWord);

		//Call the recursive function
		recursiveFindPalindromes(newCandidate, newCurrent);
	}
	}

	//We only want to see if the candidate string is a palendrome when candidateStringVector has all the words in it
	else{ 
		//Only add this candidateStringVector to the solutions if it is a palendrome
		if(isPalindrome(toString(candidateStringVector))){
			palindromeCount++;
			solutions[palindromeCount] = candidateStringVector;
		}

	}
	return;
}

// private function to determine if a string is a palindrome (given, you
// may change this if you want)
bool FindPalindrome::isPalindrome(string currentString) const
{
	locale loc;
	// make sure that the string is lower case...
	convertToLowerCase(currentString);
	// see if the characters are symmetric...
	int stringLength = currentString.size();
	for (int i=0; i<stringLength/2; i++) {
		if (currentString[i] != currentString[stringLength - 1 - i]) {
			return false;
		}
	}
	return true;
}

//------------------- PUBLIC CLASS METHODS -------------------------------------

FindPalindrome::FindPalindrome() : wordCount(0), palindromeCount(0)
	{}

FindPalindrome::~FindPalindrome()
	{clear();}

////Done////
int FindPalindrome::number() const
{
	return palindromeCount;
}

void FindPalindrome::clear()
{
	// TODO need to implement this...
	//Reset palindrome count
	palindromeCount = 0;
	solutions.clear();
}




bool FindPalindrome::cutTest1(const vector<string> & stringVector)
{
	//This variable stores the total amount of letters that show up an odd amount
	int oddCount = 0;
	//Putting a while loop in the front for efficiency
	while(oddCount<2){


	//Create a string that holds all the words in the vector

	string word, allWords;
	for(int i=0; i<stringVector.size(); i++){
		word = stringVector[i];
		convertToLowerCase(word);
		allWords += word;
	}
	
	//This variable stores the size of allWords
	int allWordsSize = allWords.size();


	//This is used to count how many times an individual letter is in allWords
	int letterCount;
	//This stores all the previously counted letters
	string usedLetters = "";
	//This is used to end a cycle if the letter has been used
	bool used = false;


	for(int i=0; i<allWordsSize; i++){
		//Next cycle will start if the letter has been used before
		while(!used)

		//See if the letter at index i has been counted before
		for(int j=0; j<usedLetters.size(); j++){
			if(allWords[i] == usedLetters[j])
				//start the next cycle
				used = true;
		}//end cycling through used letters

		//Count how many times this letter is in the string. Reset at 0 when i++
		letterCount = 0;
		
		//Anything before i has already been used, so start at i
		for(int j=i; j<allWordsSize; i++){
			if(allWords[i] == allWords[j])
				letterCount++;
		}
		//If letter count is odd, add to the odd count
		if(letterCount % 2)
			oddCount++;

	}//end cycling through all the strings

	


	//If there are an odd amount of total letters
	if(allWordsSize % 2)
		return oddCount==1;
	//If there are an even amount of total letters
	else
		return oddCount==0;
	
	}	//end while loop
	//Will only be here if oddCount>1
	return false;
}

bool FindPalindrome::cutTest2(const vector<string> & stringVector1,
                              const vector<string> & stringVector2)
{
	// TODO need to implement this...
	return false;
}





bool FindPalindrome::add(const string & value)
{
	//If this word is already in the list, return false
	string word;
	string newWord = value;
	for(int i=0; i<wordCount; i++){
		//Iterate through wordList
		word = wordList[i];

		//If the new word is already on the list, return an error
		convertToLowerCase(newWord);
		convertToLowerCase(word);
		if(word == newWord){
			//Send an error
			return false;
		}
	}
	
	//Add unique word to word list
	wordList.push_back(value);
	wordCount++;

	//Update the solutions palindrome with the new word if they pass the cut tests
	vector<string> emptyVector;
	if(cutTest1(wordList) & cutTest2(emptyVector,emptyVector))		////**TAKE OUT EMPTY VECTOR ONCE CUTTEST 2 IS DONE
		recursiveFindPalindromes(emptyVector, wordList);
	

}

bool FindPalindrome::add(const vector<string> & stringVector)
{
	//If one of the words is already in the list, return false
	string word;
	string newWord;
	for(int i=0; i<stringVector.size; i++){
			//Iterate through new words
			newWord = stringVector[i];
			
			for(int j=0; j<wordCount; j++){
				//Iterate through wordList
				word = wordList[j];

				//If the new word is already on the list, return an error
				convertToLowerCase(newWord);
				convertToLowerCase(word);
				if(word == newWord){
					//Send an error
					return false;
			}
		}
	}
	

	//Add all new words to word list
	wordCount += stringVector.size();
	for(int i=0; i<stringVector.size(); i++)
		wordList.push_back(stringVector[i]);


	//Update the solutions palindrome with the new word if they pass the cut tests
	vector<string> emptyVector;
	if(cutTest1(wordList) & cutTest2(emptyVector,emptyVector))		////**TAKE OUT EMPTY VECTOR ONCE CUTTEST 2 IS DONE
		recursiveFindPalindromes(emptyVector, wordList);
	

	
}




//Done
vector< vector<string> > FindPalindrome::toVector() const
{
	return solutions;
}




//Ask about cut tests
//Ask about how to append, insert, and add with vectors (+=, push_back(), solutions[palindromeCount] = vector<string>)