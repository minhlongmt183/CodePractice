#pragma once
class Nhanvien
{
protected:
	char hoten[100];
	int ngay, thang, nam;
public:
	Nhanvien();
	~Nhanvien();
	virtual void Nhap();
	virtual void Xuat();
	virtual long Luong();
};
