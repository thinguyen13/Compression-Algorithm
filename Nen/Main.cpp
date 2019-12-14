#include <iostream>
#include <fstream>
#include <streambuf>
#include <string>
#include <bitset>
#include <windows.h>
#include <stdio.h>
#include <sstream>
#include <vector>
#include "NenChuoi.h"
using namespace std;


int main()
{
	NODE Huff[MAXNODE];
	MABIT bangMaBit[256];

	NenHuffman("input2.txt", Huff, bangMaBit);

	ifstream input("Output.txt");

	ofstream output("Nen.txt");

	int i = 0;

	char *chuoi = new char[8];

	while (!input.eof())
	{
		if (i == 0)
		{
			char *chuoi = new char[8];
		}
		input >> chuoi[i];
		if (i == 7)
		{
			output << strToChar(chuoi);
			i = 0;
		}
		else i++;
	}

	if (i != 7)
	{
		for (int j = i - 1; j < 8; j++)
		{
			chuoi[i] = '0';
		}
	}

	output << strToChar(chuoi);


	input.close();
	output.close();

	system("PAUSE");
	return 0;
}

