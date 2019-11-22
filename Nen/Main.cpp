#include <iostream>
#include <fstream>
#include "NenChuoi.h"
using namespace std;


int main()
{
	NODE Huff[MAXNODE];
	Tao(Huff);
	TanSuatXuatHien("input.txt", Huff);
	XuatBangTanSuat(Huff);
	system("PAUSE");
	return 0;
}