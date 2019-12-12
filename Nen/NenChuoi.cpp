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

bool Tim2PhanTuMin(int &i, int &j, int nNode, NODE Huff[])
{
	i = -1;
	j = -1;

	for (int k = 0; k < nNode; k++)
		if (Huff[k].used == false && Huff[k].freq > 0)
		{
			if (i == -1)
			{
				i = k;
			}
			else if (j == -1)
			{
				j = k;
			}
			else
			{
				if (Huff[i].freq > Huff[j].freq)
				{
					if (Huff[k].freq < Huff[i].freq || (Huff[k].freq == Huff[i].freq && Huff[k].c < Huff[i].c))
					{
						i = k;
					}
				}
				else {
					if (Huff[k].freq < Huff[j].freq || (Huff[k].freq == Huff[j].freq && Huff[k].c < Huff[j].c))
					{
						j = k;
					}
				}
			}
		}

	if (i != -1 && j != -1)
	{
		if ((Huff[i].freq > Huff[j].freq) || ((Huff[i].freq == Huff[j].freq) && (Huff[i].c < Huff[j].c)))
		{
			swap(i, j);
		}
		return true;
	}
	else
	{
		return false;
	}
}

