//Editor.h
#pragma once
#include  <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <conio.h>
using namespace std;

class XiEditor
{
public:
	XiEditor(string);
	void PrintLines();
	void Navigation();

private:
	string *buffer;
	int capacity;
	int numOfLines;
	int currentLine;
	int currentPos;

};
