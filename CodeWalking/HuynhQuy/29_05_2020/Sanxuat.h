#pragma once
#include "Nhanvien.h"
class Sanxuat: public Nhanvien
{
private:
	long Luongcanban, sosp;
public:
	Sanxuat();
	~Sanxuat();
	virtual void Nhap();
	virtual void Xuat();
	virtual long Luong();
};