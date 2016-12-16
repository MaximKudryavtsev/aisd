/*
 10. Имеется текстовый файл с некоторым описанием. Переносов
слов нет.  Требуется каждые 3 предложения выделить в отдельный
абзац.  Каждое   предложение   может   заканчиваться   точкой,
вопросительным либо восклицательным знаком (6).
*/

#include "stdafx.h"
using namespace std;

/*bool IsFilesOpened(ifstream &inputFile)
{
	if (!inputFile.is_open())
	{
		return false;
		cout << "Input file isn't open" << endl;
	}
	return true;
}

bool IsFileEmpty(ifstream &inputFile)
{
	return inputFile.peek() == ifstream::traits_type::eof();
}

void FragmentationOnParagraph(ifstream &inputFile)
{
	string line;
	getline(inputFile, line);
	//char* str = (char*)line.c_str();
	char str[] = "first. two? three! four.";
	char* pointer = strtok(str, ".");
	while (pointer != NULL)
	{
		cout << pointer << "\n";
		pointer = strtok(NULL, ".");
	}
	
}*/

int main(int argc, char* argv[])
{
	/*if (argc != 2)
	{
		cout << "Invalid amount of arguments\n"
			<< "Usage: paragraph-3.exe <input>" << endl;
		return 1;
	}
	ifstream inputFile(argv[1]);
	FragmentationOnParagraph(inputFile);*/
	char str[] = "Особенности национальной рыбалки - художественный, комедийный фильм.";

	cout << "Разделение строки "" << str << "" на лексемы:n";
	char * pch = strtok(str, " ,.-"); // во втором параметре указаны разделитель (пробел, запятая, точка, тире)

	while (pch != NULL)                         // пока есть лексемы
	{
		cout << pch << "n";
		pch = strtok(NULL, " ,.-");
	}
	return 0;
	system("pause");
}

