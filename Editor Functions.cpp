// Editor Fuctions.cpp
#include "Editor.h"
XiEditor::XiEditor(string filename)
{ 
// I made the current line, position zero to start at the top left.
	currentLine = 0;
	currentPos = 0;
	capacity = 0;
// Counter for the number of lines
	numOfLines = 0; 
// I made (I) to help the buffer to collect the text from the file.
	int i = 0; 
	ifstream inFile;
	string line;
	inFile.open("sample.txt");
// check if the file opened or nah.
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
// this loop print till the end of the text.
	for (int i = 0; i < numOfLines; i++)
	{
//this if to print the (*) for the current line and ( ) for the rest of the lines.
		if (i == currentLine)
			cout << "*";
		else
			cout << " ";
		cout << buffer[i] << endl;
//this if to print the (^) for the current position and ( ) for the rest of the lines.
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
	char command;
//The (_getch()) allow the user to enter the letter without printing them.
	command = _getch();
//Every time the user will enter a letter the screen will be cleared,
//the text will be printed again with the (^,*) new position. 
	while (command != 'q') {
		
		switch (command) {
		case 'k': currentLine++; break;
		case 'j': currentLine--; break;
		case 'l': currentPos++; break;
		case 'h': currentPos--; break;
		}
// clear the screen.
		system("cls");
// print again the whole text with the new positions.
		PrintLines();
		command = _getch();
	}
}