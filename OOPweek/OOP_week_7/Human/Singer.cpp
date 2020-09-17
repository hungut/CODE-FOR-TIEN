#include "Singer.h"

void Singer::setInfo(){
    cout << "set info for this singer : \n";
    Human::setInfo();
    cout << "music genre : ";
    cin.ignore();
    getline(cin,this->genre);
    cout << "shows : ";
    cin >> this->shows;
    cout << "albums : ";
    cin >>this->albums;
}
void Singer::getInfo(){
    cout << "Info of Doctor : \n";
    Human::getInfo();
    cout << "music genre : " << this->genre<< "\nshows : " << this->shows << "\nalbums : " << this->albums << "\n";
}
Singer::Singer()
{
    this->setWorkplace("Stage");
}

Singer::~Singer()
{
}

string Singer::getGenre() {
	return this->genre;
}
void Singer::setGenre(string genre) {
	this->genre = genre;
}


int Singer::getShows() {
	return this->shows;
}
void Singer::setShows(int shows) {
	this->shows = shows;
}


int Singer::getAlbums() {
	return this->albums;
}
void Singer::setAlbums(int albums) {
	this->albums = albums;
}