#pragma once
#ifndef _NENCHUOI_H_
#define _NENCHUOI_H_

#define MAXNODE 256*9
struct NODE
{
	unsigned char c;
	int freq; // Số lần xuất hiện 
	bool used; //Kiểm tra node đã được xử lí hay chưa
	int left; // Chỉ số của nút con trái
	int right; // Chỉ số nút con phải
};
void Tao(NODE Huff[]);
void TanSuatXuatHien(const char* tenFile, NODE Huff[]);
void XuatBangTanSuat(NODE Huff[]);
bool Tim2PhanTuMin(int &i, int &j, int nNode, NODE Huff[]);
int TaoCayHuffman(NODE Huff[]);
void XuatCayHuffman(int node, int tab, NODE Huff[]);
#endif