/*
 10. ������� ��������� ���� � ��������� ���������. ���������
���� ���.  ��������� ������ 3 ����������� �������� � ���������
�����.  ������   �����������   �����   �������������   ������,
�������������� ���� ��������������� ������ (6).
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
	char str[] = "����������� ������������ ������� - ��������������, ���������� �����.";

	cout << "���������� ������ "" << str << "" �� �������:n";
	char * pch = strtok(str, " ,.-"); // �� ������ ��������� ������� ����������� (������, �������, �����, ����)

	while (pch != NULL)                         // ���� ���� �������
	{
		cout << pch << "n";
		pch = strtok(NULL, " ,.-");
	}
	return 0;
	system("pause");
}

