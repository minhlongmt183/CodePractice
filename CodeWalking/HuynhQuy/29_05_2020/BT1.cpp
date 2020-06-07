#include <iostream>
#include "Nhanvien.h"
#include "Sanxuat.h" 
#include "Vanphong.h"
#include "Quanlynhanvien.h"
using namespace std;
Nhanvien::Nhanvien() 
{
}
Nhanvien::~Nhanvien()
{
}
void Nhanvien::Nhap()
{
	cout << "Ho ten: ";
	fflush(stdin);
	gets_s(hoten);
	cin >> ngay; cin.ignore(); cin >> thang; cin.ignore(); cin >> nam;
}
void Nhanvien::Xuat()
{
	cout << hoten << endl << "Ngay sinh: " << ngay << "/" << thang << "/" << nam << endl;
}
long Nhanvien::Luong()
{
	return 0;
}
Sanxuat::Sanxuat()
{
}
Sanxuat::~Sanxuat()
{
}
void Sanxuat::Nhap()
{
	Nhanvien::Nhap();
	cout << "Luong can ban: ";
	cin >> Luongcanban;
	cout << "So san pham: ";
	cin >> sosp;
}
void Sanxuat::Xuat()
{
	Nhanvien::Xuat();
	cout << "Luong can ban: " << Luongcanban << endl << "So san pham: " << sosp << endl;
}
long Sanxuat::Luong()
{
	return Luongcanban + sosp * 5000;
}
Vanphong::Vanphong()
{
}
Vanphong::~Vanphong()
{
}
void Vanphong::Nhap()
{
	Nhanvien::Nhap();
	cout << "So ngay lam viec: ";
	cin >> songay;
}
void Vanphong::Xuat()
{
	Nhanvien::Xuat();
	cout << "So ngay lam viec: ";
	cin >> songay;
}
long Vanphong::Luong()
{
	return songay * 100000;
}
Quanlynhanvien::Quanlynhanvien()
{
	n = 0;
	x = new Nhanvien * [1000];
}
Quanlynhanvien::~Quanlynhanvien()
{
	delete[]x;
}
void Quanlynhanvien::Nhap()
{
	int k;
	for (int i = 0;; i++)
	{
		do 
		{
			cout << "\nLoai nhan vien: \n1-Van phong\n2-San xuat\n0-Ket thuc\n";
			cin >> k;
			if (k != 1 && k != 2 && k != 0) cout << "\nKhong hop le!\n";
		} while (k != 1 && k != 2 && k != 0);
		if (k == 0) return;
		else if (k == 1)
			{
				n++;
				x[i] =
			
		x[i]->Nhap();
	}
}
void Quanlynhanvien::Xuat()
{
	cout << "So nhan vien = " << n << "\n";
	for (int i = 0; i < n; i++)
	{
		cout << endl;
		x[i]->Xuat();
		cout << "Luong = " << x[i]->Luong();
		cout << endl;
	}
}
int main()
{
	Quanlynhanvien x;
	x.Nhap();
	x.Xuat();
	//system("pause");
	return 0;
}
	
