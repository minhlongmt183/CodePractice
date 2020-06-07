#pragma once
#include "Nhanvien.h"
class Vanphong :public Nhanvien
{
private:
	int songay;
public:
	Vanphong();
	~Vanphong();
	virtual void Nhap();
	virtual void Xuat();
	virtual long Luong();
};
