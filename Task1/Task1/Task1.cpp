
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;


class WordFreqPair
{
public:
	string word;  //string that holds a word
	int count = 0;
};

int main()
{

	int numberOfWords = 0; // number of words in the document
	int numberOfSentences = 0; // number of sentences in the document
	ifstream filename;//name of the document
	vector <string> allWords;
	string line;
	string word;
    filename.open("text.txt");
	if (filename.is_open()) {
		while (getline(filename, line)) {
			istringstream stringStream(line);
			while (stringStream >> word) {
				allWords.push_back(word);
				numberOfWords++;
			}
		}
		filename.close();
	}

	vector <WordFreqPair> wordList;
	for (int i = 0; i < allWords.size(); i++) {
		
		if (wordList.size() == 0) {
			WordFreqPair wordFreqPair;
			wordList.push_back(wordFreqPair);
			wordList[0].word = allWords[i];
		}
		else
		{
			bool found = false;
			
			for (int e = 0; e < wordList.size(); e++) {
				
				if (wordList[e].word == allWords[i]) {
					found = true;
				}
			}
			if (found == false) {
				WordFreqPair wordFreqPair;
				wordList.push_back(wordFreqPair);
				wordList[wordList.size()-1].word = allWords[i];
			}
		}
	}

	for (auto x : wordList) {
		x.count = 0;
		for (auto y : allWords) {
			if (x.word == y) {
				x.count++;
			}
		}
		cout << x.count << endl;
	}


	for (auto i : wordList) {
		cout << i.word << endl;
		cout << i.count << endl;
	}
	/*
	vector <string> wordList;
	for (int i = 0; i < allWords.size(); i++) {
		if (wordList.size() == 0) {
			wordList.push_back(allWords[i]);
			//wordList.push_back(allWords[i]);
		}
		else
		{
			bool found = false;
			for (int e = 0; e < wordList.size(); e++) {
				if (wordList[e] == allWords[i]) {
					found = true;
				}
			}
			if (found == false) {
				wordList.push_back(allWords[i]);
			}
		}
	}

	for (auto x : wordList) {
		int count = 0;
		for (auto y : allWords){
			if (x == y) {
				count++;
			}
		}
		cout << count << endl;
	}



	for (auto i : wordList) {
		cout << i << endl;
	}
----------------------------------------------------------------------------------------

	for (auto i : allWords) {
		cout << i << endl;
		int count = 0;  //number of occurrences of the word in the document
		if (wordList.size() == 0) {
			wordList.push_back(i);
		}
		else {
			for (auto e : wordList) {
				if (e == i) {
					count++;
				}
				else {
					wordList.push_back(i);
				}
			}
		}
		cout << count << endl;
	}

	int count = 0;
	//cout << lines[0] << endl;
	string words[100];
	for (int i = 0; i < lines.size();i++) {
		vector <char> word;
		for (auto x : lines[i])
		{
			if (x == ' ') {
				count++;
				cout << count << endl;
				words[count] = word;
				break;
			}
			else {
				word.push_back(x);

			}
		}
	}
	*/
}

