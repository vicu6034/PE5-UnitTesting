#include "Rectangle.h"
//constructor
Rectangle::Rectangle(Point p1, Point p2) {
    p1_ = p1;
    p2_ = p2;
}
// get the width of the rectangle  
// between p1.x and p2.x
int Rectangle::GetWidth() { return (p2_.x-p1_.x); }
// get the height of the rectangle
// between p2.y and p2.y
int Rectangle::GetHeight() { return (p2_.y-p1_.y); }
//returns true iff this rectangle shares any points with the other one
bool Rectangle::Overlaps(Rectangle& other) {
    if ((p1_.x == other.get_p1().x) && (p1_.y == other.get_p1().y)) {return true;}
    if ((p2_.x == other.get_p1().x) && (p2_.y == other.get_p1().y)) {return true;}
    if ((p1_.x == other.get_p2().x) && (p1_.y == other.get_p2().y)) {return true;}
    if ((p2_.x == other.get_p2().x) && (p2_.y == other.get_p2().y)) {return true;}
    return false;
}
//returns area of the rectangle
int Rectangle::CalculateArea() { return (GetHeight() * GetWidth() * -1); }
// moves the bottom left coordinate down one and to the left one
// moves the upper right coordinate up one and to the right one
void Rectangle::Expand() {
    Point newP1 = {p1_.x+1,p1_.y-1};
    Point newP2 = {p2_.x-1,p2_.y+1};
    p1_ = newP1;
    p2_ = newP2;
}
// moves the bottom left coordinate up one and to the right one
// moves the upper right coordinate down one and to the left one
void Rectangle::Shrink() {
    Point newP1 = {p1_.x-1,p1_.y+1};
    Point newP2 = {p2_.x+1,p2_.y-1};
    p1_ = newP1;
    p2_ = newP2;
}