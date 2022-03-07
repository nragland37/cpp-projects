#include<iostream>
using namespace std;

int numberWords(const char* words);

int main()
{
	int numWords;
	int numSentences = 3;
	int size = 50;
	char* sentence = new char[size];
	
	for (int i = 0; i < numSentences; i++)
	{
		cout << "Enter a sentence ending in a period: " << endl;
		cin.getline(sentence, size);
		
		numWords = numberWords(sentence);
		cout << endl << "There are " << numWords << " words in this sentence."
		   	 << endl << endl;
	}

	delete[] sentence;

	return 0;
}

//****************************************************************************************************

int numberWords(const char* words)
{
	int numberOfWords = 1;
	int count = 0;
	char character = words[1];
	int num;

	do
	{
		if (words[count] == ',' || words[count] == ' ')
		{
			numberOfWords++;
			num = count + 1;
			if (words[num] == ',' || words[num] == ' ')
			{
				numberOfWords--;
			}
		}
		count++;
		character = words[count];
		
	} while (character != '.');

	return numberOfWords;
}

//****************************************************************************************************

/*

Enter a sentence ending in a period:
Hi there.

There are 2 words in this sentence.

Enter a sentence ending in a period:
This contains a name, address and phone number.

There are 8 words in this sentence.

Enter a sentence ending in a period:
See you later, alligator.

There are 4 words in this sentence.

*/