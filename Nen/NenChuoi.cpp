#include "NenChuoi.h"
#include <iostream>
#include <fstream>
using namespace std;

void Tao(NODE Huff[])
{
	for (int i = 0; i < MAXNODE; i++)
	{
		Huff[i].c = i;
		Huff[i].freq = 0;
		Huff[i].used = false;
		Huff[i].left = -1;
		Huff[i].right = -1;
	}
}
void TanSuatXuatHien(const char *tenFile, NODE Huff[])
{
	ifstream fileInput(tenFile);
	if (fileInput.fail())
		cout << "Khong the mo file\n";
	
	while (!fileInput.eof())
	{
		unsigned char c;
		if (fileInput >> c)
			Huff[c].freq++;
	}
	fileInput.close();
}
void XuatBangTanSuat(NODE Huff[])
{
	cout << "Bang tan suat thong ke: \n";
	for (int i = 0; i < 256; i++)
	{
		if (Huff[i].freq > 0)
			cout << Huff[i].c << ": " << Huff[i].freq << endl;
	}
}

