#include "Editor.h"

XiEditor::XiEditor(string filename)
{
	currentLine = 0; // I made the current line, position zero to start at the top left.
	currentPos = 0;
	capacity = 0;
	numOfLines = 0; // Counter for the number of lines
	int i = 0; // I made (I) to help the buffer to collect the text from the file.
	ifstream inFile;
	string line;
	inFile.open("sample.txt");
	if (!inFile)
		cout << "Couldn't find the file" << endl;
	while (!inFile.eof())
	{
		getline(inFile, line);
		numOfLines++;
	}
	inFile.close();
	capacity = 2 * numOfLines; 
	// I made the capacity double the size of the # of lines to give the user the ability to add to the text.
	buffer = new string[capacity];

	inFile.open("sample.txt");
	while (!inFile.eof())
	{
		getline(inFile, line);
		buffer[i] = line;
		i++;
	}
	inFile.close();
	
}

void XiEditor::PrintLines()
{
	for (int i = 0; i < numOfLines; i++)// this loop print till the end of the text.
	{
		if (i == currentLine)// i 
			cout << "*";
		else
			cout << " ";
		cout << buffer[i] << endl;
		if (i == currentLine)
		{
			for (int x = 0; x < currentPos; x++)
				cout << " ";
			cout << "^" << endl;;
		}
	}
}

void XiEditor::Navigation()
{
	char input = _getch();// allow the user to enter the letter without printing them.
	while (input != 'q')
	{
//Every time the user will enter a letter the screen will be cleared,
//the text will be printed again with the (^,*) new position. 
		if (input == 'l')
		{
			currentPos++;
			system("cls");// clear the screen.
			PrintLines();// print again the whole text with new positions.
		}
		if (input == 'h')
		{
			currentPos--;
			system("cls");
			PrintLines();
		}
		if (input == 'k')
		{
			currentLine--;
			system("cls");
			PrintLines();
		}
		if (input == 'j')
		{
			currentLine++;
			system("cls");
			PrintLines();
		}
		input = _getch();
	}
}