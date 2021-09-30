#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include "Rectangle.h"

TEST_CASE ( "Rectangle constructor", "[Rectangle]") {
  Point origin = {1,0};
  Point starter = {0,1};
  Rectangle square = {origin, starter};
  REQUIRE( ((square.get_p1().x == origin.x) && (square.get_p1().y == origin.y)));
  REQUIRE( ((square.get_p2().x == starter.x) && (square.get_p2().y == starter.y)));
}

TEST_CASE ( "Rectangle overlap", "[Overlaps]") {
  Point origin = {1,0};
  Point starter = {0,1};
  Point starter2 = {0,2};
  Rectangle square = {origin, starter};
  Rectangle square2 = {origin, starter};
  Rectangle square3 = {origin, starter2};
  CHECK( square.Overlaps(square2));
  CHECK( square.Overlaps(square3));
}

TEST_CASE ( "Rectangle area calculated", "[Area]") {
  Point origin = {1,0};
  Point starter = {0,1};
  Point starter2 = {0,4};
  Rectangle square = {origin, starter};
  Rectangle square2 = {origin, starter2};
  CHECK( square.CalculateArea() == 1 );
  CHECK( square2.CalculateArea() == 4 );
}
