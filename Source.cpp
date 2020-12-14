#include<iostream>
#include<fstream>
#include<string>
#include<cstring>

int main()
{
	setlocale(0, "");

	int task;
	std::cout << "Enter task:";
	std::cin >> task;

	switch (task)
	{
	// 1. Delete all excessive backspaces in sample text. Leave one backspace between words and two backspace between sentences.
	case 1:
	{
		std::ifstream fin("Text.txt");
		std::ofstream fout("Output.txt");
		std::string line;
		char str[250];
		int pos;

		while (!fin.eof())
		{
			getline(fin, line);
			// cycle while <find> finds two bakcspaces in a row and delete one
			for (; line.find("  ") != std::string::npos; line.erase(line.find("  "), 1));

			strcpy_s(str, line.c_str());// c_str transforms string in an char array
			char* s = strpbrk(str, "!.?");// find first inclusion of one of "!.?"
			while (s != nullptr)
			{
				pos = abs(str - s);// find where to put backspace
				line.insert(pos + 1, " ");
				strcpy_s(str, line.c_str());
				s = strpbrk(s + 2, "!.?");// move to backspaces forward and find next inclusion
			}
			fout << line << std::endl;
		}
	}
		break;
	// 2. In C++ code sample in <while> delete parntheses around logical condition and insert <do> keyword after.
	case 2:
	{
		std::ifstream fin("Text.txt");
		std::ofstream fout("Output.txt");
		std::string line;

		while (!fin.eof())
		{
			getline(fin, line);
			if (line.find("while (") != std::string::npos)
			{
				line.erase(line.find_first_of("("), 1);
				line.replace(line.find_last_of(")"), 2, " do");
			}
			fout << line << std::endl;
		}
	}
	break;

	// 3. C++ code sample given. Write in output file all numeric constants with the number of string wher it appears
	case 3:
	{
		std::ifstream fin("Text.txt");
		std::ofstream fout("Output.txt");
		std::string line;
		int lineCount = 1;
		char str[250];
		int pos;

		while (!fin.eof())
		{
			bool flag = true;
			std::string result;

			getline(fin, line);
			strcpy_s(str, line.c_str());
			char* s = strpbrk(str, "0123456789");

			while (s != nullptr)
			{
				if (!isalpha(*(s - 1)))
				{
					std::string tempS;
					int temp = atoi(s);
					tempS = std::to_string(temp);
					pos = tempS.length();
					if (flag)
					{
						result += std::to_string(lineCount);
						flag = false;
					}
					result += " " + tempS;
				}
				s = strpbrk(s + pos, "0123456789");
			}
			if (!flag)
				fout << result << std::endl;

			lineCount++;
		}
	}
		break;

	// 4. Delete given word in every string, sort strings excluding symbol's case and save to a new file
	case 4:
	{
		std::ifstream fin("Text.txt");
		std::ofstream fout("Output.txt");
		std::string line;
		char* str = new char[];

		while (!fin.eof())
		{
			int temp;
			getline(fin, line);
			for (; line.find("The ") != std::string::npos; line.erase(line.find("The "), 4));
			strcpy_s(str, line.c_str());
			temp = atoi(str[0]);
			tolower(temp);
		}
	}
		break;

	// 5. Time in mins and secs given. Get time in string view.
	case 5:
	{
		std::ifstream fin("Text.txt");
		std::ofstream fout("Output.txt");
		std::string units[] = {"zero", "one", "two", "three", "four" , "five" , "six" , "seven" , "eight" , "nine" };
		std::string decimals[] = {"twenty", "thirty", "forty", "fifty"};
		std::string teens[] = {"ten", "eleven", "twelve", "thirteen", "fourteen" , "fifteen" , "sixteen" , "seventeen" , "eighteen" , "ninteen" };
		std::string result;
		int hour, minute, second;
		fin >> hour >> minute >> second;

		//hours
		if (hour / 10 == 0)
			result += units[hour] + " ";
		else if (hour / 10 == 1)
			result += teens[hour % 10] + " ";
		else
		{
			result += decimals[hour / 10 - 2] + " ";
			if (hour % 10 != 0)
				result += units[hour % 10] + " ";
		}

		if ((hour % 100 > 10 && hour % 100 < 20) || hour % 10 > 4 || hour % 10 == 0)
			result += "hours ";
		else if (hour % 10 > 1 && hour % 10 < 5)
			result += "hour ";// different endings in russian 
		else
			result += "hour ";
		//minutes
		if (minute / 10 == 0)
			result += units[minute] + " ";
		else if (minute / 10 == 1)
			result += teens[minute % 10] + " ";
		else
		{
			result += decimals[minute / 10 - 2] + " ";
			if (minute % 10 != 0)
				result += units[minute % 10] + " ";
		}

		if ((minute % 100 > 10 && minute % 100 < 20) || minute % 10 > 4 || minute % 10 == 0)
			result += "min ";
		else if (minute % 10 > 1 && minute % 10 < 5)
			result += "min ";
		else
			result += "min ";
		//seconds
		if (second / 10 == 0)
			result += units[second] + " ";
		else if (second / 10 == 1)
			result += teens[second % 10] + " ";
		else
		{
			result += decimals[second / 10 - 2] + " ";
			if (second % 10 != 0)
				result += units[second % 10] + " ";
		}

		if ((second % 100 > 10 && second % 100 < 20) || second % 10 > 4 || second % 10 == 0)
			result += "sec ";
		else if (second % 10 > 1 && second % 10 < 5)
			result += "sec ";
		else
			result += "sec ";

		fout << result;
	}
		break;
	default:
		break;
	}

	

	return 0;
}