#include "Rectangle.h"
Rectangle::Rectangle()
{
    this->length = 2;
    this->width = 1;
}

Rectangle::~Rectangle()
{
}
Rectangle::Rectangle(int l,int w){
    this->length = l;
    this->width = w;
}
Rectangle::Rectangle(const Rectangle &rect){
    this->length = rect.length;
    this->width = rect.width;
}
int Rectangle::getWidth() {
	return this->width;
}
void Rectangle::setWidth(int width) {
	this->width = width;
}
int Rectangle::getLength() {
	return this->length;
}
void Rectangle::setLength(int length) {
	this->length = length;
}
void Rectangle::ShowRectangle(){
    cout << "\nlength : " << this->length << " , width : " << this-> width << "\n" << "Area =  " << this->getArea() << "\n";
}
int Rectangle::getArea(){
    return this->length*this->width;
}