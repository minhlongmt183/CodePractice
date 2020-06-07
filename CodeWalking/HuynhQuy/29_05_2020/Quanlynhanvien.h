#pragma once
#include "Nhanvien.h"
#include <vector>
class Quanlynhanvien: public Nhanvien
{
private:
	Nhanvien** x;
	int n;
public:
	Quanlynhanvien();
	~Quanlynhanvien();
	void Nhap();
	void Xuat();
};
