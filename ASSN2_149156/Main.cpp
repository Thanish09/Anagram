#include <iostream>
#include <fstream>
#include <string>
#include "DynQueue.h"
#include "linkList.h"
#include "DynStack.h"

using namespace std;

void anagram(string, linkList<string>&, DynQueue<string>, DynStack<string>);
void swap(string&, string&);
int menu();
int search();

int main()
{
	fstream fileName;
	string file, name, word, word1,word2, word3,word4;
	int number, count=0,start, sear, check, num=0, valid;
	char yesno;
	linkList<string> link, list;
	DynQueue<string> queue, out;
	DynStack<string> stack;
	
	cout << "\t\t\t*****************" << endl;
	cout << "\t\t\tAnagram Processor" << endl;
	cout << "\t\t\t*****************" << endl << endl;
	cout << "Welcome to Anangram Program.\n";
	cout << "NOTE: words with more letter takes longer time.\n" << endl;
	cout << "Please enter a file name to be process: " << endl;
	cin >> file;

	while (file != "")		//validating file
	{
		file += ".txt";
		fileName.open(file.c_str(), ios::in);

		if (fileName)
		{
			cout << "The file has been retrieved.\nPlease wait while the program generates the anagram." << endl;
			break;
		}
		else if (!fileName)
		{
			cout << "The file you have entered not found.Please enter file name: " << endl;
			cin >> file;
		}
	}

	while (!fileName.eof())		//Get information from file
	{
		fileName >> name;
		link.append(name);	//append all words from file to link object
		anagram(name, link, queue, stack);	//generates all the anagrams of words from file
	}
	fileName.close();
	cout << "The program is ready to use.Let's continue." << endl;
	system("PAUSE");
	system("CLS");
	
	while (start = menu())		//using main menu
	{
		switch (start)
		{
			case 1:
				cout << "Enter the word you want to add.Make sure there is no repeated letters." << endl;
				cin >> word;
				count = link.append1(word); 	//append the word to link object
				cout << "Please wait while its generating the anagram.More letter takes time."<< endl;
				if (count == 0)			//checking the word already exist in linked list or not
				{
					anagram(word, link, queue, stack);	//generates anagram for the enterd word
					cout << "Your word and it's anagram has been saved." << endl;
				}
				else
					cout << "The word you have is already in the system.Thank you." << endl;
				system("PAUSE");
				system("CLS");
				break;
			case 2:
				cout << "Enter the word you want to search: " << endl;	//the the words in linked list
				cin >> word1;

				check = link.search(word1);		//check the word is exist in linked list or not
				
				if (check == 0)
				{
					cout << "The word you have entered is not in database.Plese go to main menu to add." << endl;
					system("PAUSE");
					system("CLS");
					break;
				}
				while (sear = search())		//using search menu
				{
					if (sear == 1)
					{
						link.anaDisp(word1);	//display anagram of selected word
						system("PAUSE");
						system("CLS");
					}
					else if (sear == 2)
					{
						do	//checking the letters entered is in the searched word
						{
							cout << "Choose any letter from '" << word1 << "' to display it: " << endl;
							cin >> word2;

							num = 0;
							for (int i = 0; i < word1.length(); i++)
							{
								if (word1[i] != word2[0])
								{
									num += 1;
								}
								else if (word1[i] == word2[0])
								{
									num = 0;
									break;
								}
							}
						} while (num != 0);
						
						link.letter(word1, word2);	//display the anagram of searched word with selected alphabet
						system("PAUSE");
						system("CLS");
					}
					else if (sear == 3)
					{
						cout << "Enter the correct word to replace it: " << endl;
						cin >> word3;
						
						valid = link.search(word3);
						
						if (valid > 0)
						{
							cout << "The word you have entered already exist in the program.\nYou will be directed to search menu." << endl;
							system("PAUSE");
							system("CLS");
						}
						else
						{
							link.update(word1,word3);			//update the searched word and delete anagrams of searched word
							anagram(word3, link, queue, stack);	//generated anagrams of updated word
							link.anaDisp(word3);		//display the anagrams of updated word
							word1 = word3;
							system("PAUSE");
							system("CLS");
						}
					}
					else if (sear == 4)
					{
						cout << "Enter the word you want to add after searched word: " << endl;
						cin >> word4;

						check = link.search(word4);		//check whether user entered word is already exist in linked list or not

						if (check > 0)
						{
							cout << "The word you have entered is alrdy in database.\nYou will directed to searching menu." << endl;
							system("PAUSE");
							system("CLS");
						}
						else
						{
							link.insert(word1, word4);		//add the word after the searched word in linked list
							anagram(word4, link, queue, stack);	//generates the anagram of added word
							link.anaDisp(word4);				//display the anarams of added word
							system("PAUSE");
							system("CLS");
						}
					}
					else if (sear == 5)
					{
						link.dele(word1);		//delete the searched word and its anagram
						cout << "The word and its anagram has been deleted.\nYou will directed to main menu since the word has been deleted." << endl;
						system("PAUSE");
						system("CLS");
						break;
					}
					else if (sear == 6)
					{
						cout << "You will be directed to main menu." << endl;
						break;
					}
				}
				break;
			case 3:
				link.disp();		//display all the words in linked list and its anagram
				system("PAUSE");
				system("CLS");
				break;
			case 4:
				cout << "Thank you for using this app." << endl;
				cout << "The program will exit now." << endl;
				break;
		}
		if (start == 4)	//end the program
			break;
	}

	return 0;
}

int menu()
{
	int number;
	cout << "Choose the options.\n1.Add word\n2.Search and Update\n3.Display all\n4.Exit" << endl;
	cin >> number;
	while (number < 1 || number > 4)
	{
		cout << "Incorrect choosing.Enter again: " << endl;
		cout << "Choose the options.\n1.Add word\n2.Search and Update\n3.Display all\n4.Exit" << endl;
		cin >> number;
	}
	system("CLS");
	return number;
}

int search()
{
	int number;
	cout << "Choose the options.\n1.Display the anagram of that word\n2.Find anagrams start with choosen letter";
	cout << "\n3.Update that word\n4.Add a new word after this word\n5.delete the word and it's anagram\n6.Exit to main menu." << endl;
	cin >> number;
	while (number < 1 || number > 6)
	{
		cout << "Error.Please choose again: " << endl;
		cout << "Choose the options.\n1.Display the anagram of that word\n2.Find anagrams start with choosen letter";
		cout << "\n3.Update that word\n4.Add a new word after this word\n5.delete the word and it's anagram\n6.Exit to main menu." << endl;
		cin >> number;
	}
	system("CLS");
	return number;
}

void anagram(string name, linkList<string> &link, DynQueue<string> queue, DynStack<string> stack)
{
	string wrd;
	char temp;
	int k = name.length();
	string word = name;
	int count = 0, p = 0;

	for (int i = 0; i < k - 1; i++)		//enqueue the first swapping of the word means swap the first position with other positions in queue object
	{
		for (int j = 0; j < k; j++)
		{
			temp = word[j];
			wrd = name;
			for (int m = 0; m < k; m++)
			{
				if (word[j] == wrd[m])
				{
					wrd[m] = wrd[i];
					wrd[i] = temp;
					if (p < 2)
					{
						queue.enqueue(wrd);
					}
					p++;
				}
			}
		}
	}

	for (int i = 0; i < k - 1; i++) 			//swap the letters of with all positions
	{
		while (!queue.isEmpty())				//dequeue the words of first time swapping
		{
			queue.dequeue(word);
			string letter = word;
			for (int j = 0; j < k; j++)			
			{
				temp = letter[j];
				wrd = word;
				for (int m = 0; m < k; m++)
				{
					if (letter[j] == wrd[m])
					{
						wrd[m] = wrd[i];
						wrd[i] = temp;
						stack.push(wrd);		//stack all the swapped letters
					}
				}

			}
		}
		while (!stack.isEmpty())
		{
			stack.pop(wrd);				//take out the swapped letters and enqueue it
			queue.enqueue(wrd);
		}
	}
	while (!queue.isEmpty())		//append all the swapped words
	{
		queue.dequeue(wrd);
		link.append2(name, wrd);
	}
}

