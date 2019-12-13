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

int TaoCayHuffman(NODE Huff[])
{
	int nNode = 256;
	int i, j;
	bool timThay = false;
	while (true)
	{

		timThay = Tim2PhanTuMin(i, j, nNode, Huff);
		if (!timThay)
		{
			break;
		}

		Huff[nNode].c = (Huff[i].c < Huff[j].c) ? Huff[i].c : Huff[j].c;
		Huff[nNode].freq = Huff[i].freq + Huff[j].freq;
		Huff[nNode].left = i;
		Huff[nNode].right = j;

		Huff[i].used = true;
		Huff[j].used = true;

		Huff[nNode].used = false;
		nNode++;
	}
	return nNode - 1;
}

void XuatCayHuffman(int node, int tab, NODE Huff[])
{
	if (node == -1)
	{
		return;
	}
	for (int i = 0; i < tab; i++)
	{
		cout << endl;
	}
	if (Huff[node].left == -1 && Huff[node].right == -1)
	{
		cout << Huff[node].c << "\n";
	}
	else
	{
		cout << Huff[node].c << "..\n";
		XuatCayHuffman(Huff[node].left, tab + 1, Huff);
		XuatCayHuffman(Huff[node].right, tab + 1, Huff);
	}
}

void DuyetCayHuffman(int node, char maBit[], int nMaBit, NODE Huff[], MABIT bangMaBit[])
{
	if (node == -1)
	{
		return;
	}
	if (Huff[node].left == -1 && Huff[node].right == -1) {	//Ghi chú: ý nghĩa của điều kiện kiểm tra là gì?	
		bangMaBit[node].soBit = nMaBit;
		bangMaBit[node].bits = new char[nMaBit];
		for (int i = 0; i < nMaBit; i++)
		{
			bangMaBit[node].bits[i] = maBit[i];
		}
		return;
	}
	else
	{
		//Ghi chú: ý nghĩa của 2 dòng lệnh bên dưới là gì?
		maBit[nMaBit] = '0';
		DuyetCayHuffman(Huff[node].left, maBit, nMaBit + 1, Huff, bangMaBit);

		//Ghi chú: ý nghĩa của 2 dòng lệnh bên dưới là gì?
		maBit[nMaBit] = '1';
		DuyetCayHuffman(Huff[node].right, maBit, nMaBit + 1, Huff, bangMaBit);


	}
}

void PhatSinhMaBit(int nRoot, MABIT bangMaBit[], NODE Huff[]) { // Ghi chú: ý nghĩa của tham số nRoot?
	for (int i = 0; i < 256; i++) {
		bangMaBit[i].soBit = 0;
		bangMaBit[i].bits = NULL;
	};
	char maBit[10000 / 8];
	int nMaBit = 0;

	DuyetCayHuffman(nRoot, maBit, nMaBit, Huff, bangMaBit);
}
