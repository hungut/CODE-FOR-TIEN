#include "Candidate.h"

    int Candidate::iTongDiem()
    {
        return this->getIAnh() + this->getIToan() + this->getIVan();
    }
    void Candidate::NhapThongTin()
    {
        cin.ignore();
        cout << "nhap ten : ";
        getline(cin,this->sHoten);
        cout << "nhap ma so : ";
        cin >> this->iMaso;
        cout << "nhap diem mon Van : ";
        cin >> this->iVan;
        cout << "nhap diem mon Toan : ";
        cin >> this->iToan;
        cout << "nhap diem mon Anh : ";
        cin >> this->iAnh;
    }
    void Candidate::XuatThongTin()
    {
        cout << "ten : " << this->sHoten << "\n";
        cout << "ma so : " << this->iMaso << "\n";
        cout << "tong diem : " << this->iTongDiem() << "\n";
    }
    int Candidate::getIMaso() {
	    return this->iMaso;
    }
    void Candidate::setIMaso(int iMaso) {
	    this->iMaso = iMaso;
    }   
    string Candidate::getSHoten() {
    	return this->sHoten;
    }
    void Candidate::setSHoten(string sHoten) {
    	this->sHoten = sHoten;
    }
    int Candidate::getIToan() {
    	return this->iToan;
    }
    void Candidate::setIToan(int iToan) {
    	this->iToan = iToan;
    }

    int Candidate::getIVan() {
    	return this->iVan;
    }
    void Candidate::setIVan(int iVan) {
    	this->iVan = iVan;
    }
    int Candidate::getIAnh() {
    	return this->iAnh;
    }
    void Candidate::setIAnh(int iAnh) {
    	this->iAnh = iAnh;
    }
    Candidate::Candidate(){}
    Candidate::~Candidate(){}