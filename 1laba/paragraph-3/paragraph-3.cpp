/*
    10. Имеется текстовый файл с некоторым описанием. Переносов
    слов нет.  Требуется каждые 3 предложения выделить в отдельный
    абзац.  Каждое   предложение   может   заканчиваться   точкой,
    вопросительным либо восклицательным знаком (6).
*/

#include "stdafx.h"

using namespace std;

bool IsEndOfFile(ifstream &inputFile)
{
	return inputFile.peek() == ifstream::traits_type::eof();
}

void FragmentationOnParagraph(ifstream &inputFile)
{
	string line;
	getline(inputFile, line);
	char* str = (char*)line.c_str();
	//char str[] = "first. two? three! four.";
	int i = 0;
	char* pointer = strtok(str, ".!?");
	while ((pointer != NULL) && (pointer != " "))
	{
		
		if (i % 3 == 0) 
		{
			cout << endl;
		}
		i++;
		cout << pointer;
		pointer = strtok(NULL, ".!?");
	}
}

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Russian");

    if (argc != 2)
    {
        std::cerr << "Invalid amount of arguments\n"
             << "Usage: paragraph-3.exe <input>" << endl;
        return 1;
    }

    ifstream file(argv[1]);

    if (!file.is_open())
    {
        std::cerr << "Failed to open " << argv[1] << " for reading!" << std::endl;
        return 1;
    }

    std::string str;
    std::string result;

    while (std::getline(file, str))
    {
        int counter = 0;
        bool flag = false;

        for (size_t i = 0; i < str.length(); ++i)
        {
            // пропускаем пробелы в новой строке после того как нашли 3 знака
            if ((flag) && (isspace(static_cast<unsigned char>(str[i]))))
            {
                continue;
            }
            else if (str[i] != ' ')
            {
                flag = false;
            }

            result += str[i];

            if ((str[i] == '.') || (str[i] == '?') || (str[i] == '!'))
            {
                ++counter;
            }

            if (counter == 3)
            {
                std::cout << result << std::endl;

                result.clear();
                counter = 0;

                // ставим флажок, что нужно пропускать пробелы в начале новой строки
                flag = true;
            }
        }

        result.clear();
    }

    file.close();
}
