#ifndef LINKLIST_H
#define LINKLIST_H
#include <iostream>

using namespace std;

template <class T>
class listNode {
	public:
		T value;
		listNode<T>* next;
		listNode<T>* pointer;
		listNode(T data)
		{
			value = data;
			next = nullptr;
			pointer = nullptr;
		}
		listNode()
		{
			next = nullptr;
			pointer = nullptr;
		}

};

template <class T>
class linkList {
	private:
		listNode<T>* head;
	public:
		linkList();
		~linkList();
		void append(T);			//append the words from the file
		int append1(T);			//append the words entered by user
		void append2(T, T);		//append anagrams
		void insert(T,T);		//add word after the searced word
		void dele(T);			//delete the selected word and its anagram
		void disp();			//display all the words and its anagram
		void anaDisp(T);		//display the selected word and its anagram
		void update(T,T);		//update the searched word
		void letter(T, T);		//search and display the anagrams start with selected words
		int search(T);			//check for the existance of the word in linked list
};

template <class T>
linkList<T>::linkList()
{
	head = nullptr;
}

template <class T>
linkList<T>::~linkList()
{
	listNode<T>* nodeptr;

	nodeptr = head;
	while (nodeptr != nullptr)
	{
		head = head->next;
		delete nodeptr;
		nodeptr = head;
	}
}

template <class T>
void linkList<T>::append(T name)			//This function appends the words from the file
{
	listNode<T>* nodeptr;
	listNode<T>* newNode;
	newNode = new listNode<T>(name);
	newNode->next = nullptr;

	if (!head)
	{
		head = newNode;
	}
	else
	{
		nodeptr = head;
		while (nodeptr->next)
		{
			nodeptr = nodeptr->next;
		}
		
		nodeptr->next = newNode;
	}
}

template <class T>
int linkList<T>::append1(T name)		//This function appends words from user enter in add a new word
{
	listNode<T>* newNode;
	listNode<T>* nodeptr;
	int count = 0;

	newNode = new listNode<T>(name);
	newNode->next = nullptr;

	if (!head)
	{
		head = newNode;
	}
	else
	{
		nodeptr = head;
		while (nodeptr->next)
		{
			if (nodeptr->value == name)			//The statement checks for the word already exist or not
			{
				count += 1;						//if exist the count will increament by one
			}
			nodeptr = nodeptr->next;
		}
		
		if (nodeptr->value == name)			//The same checking process done for the last node
		{
			count += 1;
		}

		if (count == 0)						//the word will be entered only when the count is in zero indicates
		{									// that the word is not exist in the program
			nodeptr->next = newNode;
		}
	}
	return count;
}

template <class T>
void linkList<T>::append2(T name, T word)		//to append the anagrams with the word.The name is word, and the word is the anagram
{
	listNode<T>* newNode;
	listNode<T>* nodeptr;
	int count = 0;

	newNode = new listNode<T>(word);
	newNode->pointer = nullptr;
	
	nodeptr = head;
	while (nodeptr)
	{
		if (nodeptr->value == name)					//the program search for the word
		{
			while (nodeptr->pointer != nullptr)		//if got that word then a pointer named *pointer will created to 
			{										// add the anagram through *pointer.
				
				nodeptr = nodeptr->pointer;
				if (nodeptr->value == word)			//while apppending anagrams with word,if the anagram is same with other anagram
				{									//count will be increament by 1
					count += 1;
				}
			}
			if (nodeptr->value == word)			//same process occurs for last node
			{
				count += 1;
			}

			if (count == 0)						//only if the count is zero means there is no anagrams is same with the current anagram,
			{									//then only the current anagram will be appended.
				nodeptr->pointer = newNode;
			}
		}
		
		nodeptr = nodeptr->next;
	}
}

template <class T>
void linkList<T>::insert(T name, T word)	//add a new word after the searched word
{
	listNode<T>* nodeptr;
	listNode<T>* nextNode;
	listNode<T>* newNode;

	newNode = new listNode<T>(word);

	nodeptr = head;
	nextNode = nodeptr->next;
	
	while (nodeptr)
	{
		if (nodeptr->value == name)		//when the searched word found
		{
			nodeptr->next = newNode;	//the new word will be added
			newNode->next = nextNode;
		}
		if (nextNode == nullptr)
			break;
		nodeptr = nodeptr->next;
		nextNode = nodeptr->next;
	}
}

template <class T>
void linkList<T>::dele(T name)  			//to delete the searched word
{
	listNode<T>* nodeptr;
	listNode<T>* previousNode = nullptr;

	if (!head)
	{
		return;
	}
	if (head->value == name)
	{
		nodeptr = head->next;
		delete head;
		head = nodeptr;
	}
	else
	{
		nodeptr = head;
		while (nodeptr != nullptr && nodeptr->value != name)
		{
			previousNode = nodeptr;
			nodeptr = nodeptr->next;
		}
		if (nodeptr)
		{
			previousNode->next = nodeptr->next;
			delete nodeptr;
		}
	}
}

template <class T>
void linkList<T>::disp()		//to display all the words with anagrams
{
	listNode<T>* nodeptr;
	listNode<T>* node;
	nodeptr = head;
	int count = 0;

	while (nodeptr)				//points the word
	{
		node = nodeptr->pointer;
		cout << "\n" << nodeptr->value << endl;
		cout << "Anagram: " << endl;
		while (node)			//points the anagram
		{
			cout << node->value << endl;	//display the anagram
			node = node->pointer;
			count += 1;
		}
		cout << "Total: " << count << endl;		//count the total of anagrams
		count = 0;
		nodeptr = nodeptr->next;
	}
}

template <class T>
void linkList<T>::anaDisp(T word)		//display the anagrams of specific word
{
	listNode<T>* nodeptr;
	listNode<T>* node;
	int count = 0;

	nodeptr = head;
	cout << "The anagrams of " << word << ": " << endl;

	while (nodeptr)					//points the word
	{
		node = nodeptr->pointer;
		if (nodeptr->value == word)	//if the word found,then it will display that words' anagram
		{
			while (node)			//points the anagram
			{
				cout << node->value << endl;
				node = node->pointer;
				count += 1;
			}
			cout << "Total: " << count << endl;		//display total number of anagrams
		}
		
		nodeptr = nodeptr->next;
	}
}

template <class T>
void linkList<T>::update(T word, T word2) 		//update the searhced word,word is the searched word,word2 is the new word
{
	listNode<T>* nodeptr;
	listNode<T>* nextNode;
	listNode<T>* node;
	listNode<T>* newNode;
	listNode<T>* previousNode;
	newNode = new listNode<T>(word2);

	previousNode = head;
	nodeptr = previousNode->next;
	if (head->value == word)		//if the head is the searched word,then the word will be deleted and will be replace with
	{								//the new word
		node = head->next;
		delete head;
		head = newNode;
		newNode->next = node;
	}
	else
	{
		while (nodeptr)
		{
			if (nodeptr->value == word)			//if the searched word found,that word will be deleted and
			{									//replace with the new word and ends the function
				previousNode->next = newNode;
				newNode->next = nodeptr->next;
				delete nodeptr;
				break;
			}
			previousNode = nodeptr;
			nodeptr = nodeptr->next;
		}
	}
}

template <class T>
void linkList<T>::letter(T name, T word)		//searched anagrams with specfic alphabet,name is the word,word is the alphabet
{
	listNode<T>* nodeptr;
	listNode<T>* node;
	char letter;

	for (int i = 0; i < word.length(); i++)		//converts the alphabet's data type from string to char
	{
		letter = word[i];
	}

	nodeptr = head;
	while (nodeptr)
	{
		if (nodeptr->value == name)			//when the word is found
		{
			node = nodeptr->pointer;		//points to the anagram
			while (node)
			{
				if (node->value[0] == letter) 		//when the anagram's first letter equals to alphabet
				{
					cout << node->value << endl;	//the anagram will be displayed
				}
				node = node->pointer;
			}
		}
		nodeptr = nodeptr->next;
	}
}

template <class T>
int linkList<T>::search(T word)		//check the word is alredy exist in the program or not
{
	listNode<T>* nodeptr;
	int count = 0;

	nodeptr = head;

	while (nodeptr)
	{
		if (nodeptr->value == word)		//if the same word found in the program
		{								//the count will be increament by 1
			count += 1;
		}
		nodeptr = nodeptr->next;
	}
	return count;
}
#endif


