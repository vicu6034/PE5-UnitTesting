#include "Rectangle.h"
#include <cmath>
//Author: Vincent Curran
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
//original function would never return true
bool Rectangle::Overlaps(Rectangle& other) {
    if ((p1_.x == other.get_p1().x) && (p1_.y == other.get_p1().y)) {return true;}
    if ((p2_.x == other.get_p1().x) && (p2_.y == other.get_p1().y)) {return true;}
    if ((p1_.x == other.get_p2().x) && (p1_.y == other.get_p2().y)) {return true;}
    if ((p2_.x == other.get_p2().x) && (p2_.y == other.get_p2().y)) {return true;}
    return false;
}
//returns area of the rectangle
//Original function would return the area but negative 
int Rectangle::CalculateArea() { return (abs(GetHeight() * GetWidth())); }
// moves the bottom left coordinate down one and to the left one
// moves the upper right coordinate up one and to the right one
// original function moved the row in instead of out, correctly changed the col
void Rectangle::Expand() {
    int p1_col = p1_.y;
    if (p1_col != 0) {p1_col -= 1;}
    int p2_row = p2_.x;
    if (p2_row != 0) {p2_row -= 1;}
    Point newP1 = {p1_.x+1,p1_col};
    Point newP2 = {p2_row,p2_.y+1};
    p1_ = newP1;
    p2_ = newP2;
}
// moves the bottom left coordinate up one and to the right one
// moves the upper right coordinate down one and to the left one
// original function moved the row out instead of in, correctly changed the col
void Rectangle::Shrink() {
    int p1_row = p1_.x;
    if (p1_row != 0) {p1_row -= 1;}
    int p2_col = p2_.y;
    if (p2_col != 0) {p2_col -= 1;}
    Point newP1 = {p1_row,p1_.y+1};
    Point newP2 = {p2_.x+1,p2_col};
    p1_ = newP1;
    p2_ = newP2;
}