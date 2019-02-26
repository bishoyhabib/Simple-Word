//Main.cpp
#include "Editor.h"
using namespace std;
int main(int argc, char *argv[])
{
	XiEditor XiEditor(argv[1]);
	XiEditor.PrintLines();
	XiEditor.Navigation();

	system("pause");
	return 0;

}