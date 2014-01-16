#include "TestCircle.h"
#include "TestRing.h"
#include "TestRectangle.h"
#include "putils.h"


#include <iostream>
using namespace std;

template<typename Stream>
Stream &operator<<(Stream &stream, const Point point) {
	return stream << "[" << (point.getX()) << ", " << (point.getY()) << "]" << endl;
}

void testPoint() {

}
void testGeneralShapeFuncs(Shape &shape0, Shape &shape1) {
	cout << " - Testing general functions - " << endl;
	cout << " -[ Shape_0.getClosestPoint(Shape_1) = " << shape0.getClosestPoint(shape1) << endl;
	cout << " -[ Shape_0.getFarthestPoint(Shape_1) = " << shape0.getFarthestPoint(shape1) << endl;
	cout << " -[ Shape_0.intersects(Shape_1) = " << (shape0.intersects(shape1) ? "true" : "false") << endl;
	cout << " -[ Shape_0.envelops(Shape_1) = " << (shape0.envelops(shape1) ? "true" : "false") << endl;
	cout << endl;
	cout << " -[ Shape_1.getClosestPoint(Shape_0) = " << shape1.getClosestPoint(shape0) << endl;
	cout << " -[ Shape_1.getFarthestPoint(Shape_0) = " << shape1.getFarthestPoint(shape0) << endl;
	cout << " -[ Shape_1.intersects(Shape_0) = " << (shape1.intersects(shape0) ? "true" : "false") << endl;
	cout << " -[ Shape_1.envelops(Shape_0) = " << (shape1.envelops(shape0) ? "true" : "false") << endl;
	cout << endl << endl;
}

void testCircleShapeFuncs(TestCircle shape0, TestCircle shape1) {
	cout << "------------- Circle Shape function testing -------------" << endl;
	cout << " - With cases: - " << endl;
	cout << " - Circle_0: x=" << shape0.getCenterX() << " y=" << shape0.getCenterY() << " radius=" << shape0.getRadius() << endl;
	cout << " - Circle_1: x=" << shape1.getCenterX() << " y=" << shape1.getCenterY() << " radius=" << shape1.getRadius() << endl;
	cout << endl;
	testGeneralShapeFuncs(shape0, shape1);
	cout << " - Testing optimized functions - " << endl;
	cout << " -[ Circle_0.getClosestPoint(Circle_1) = " << shape0.getClosestPoint(shape1) << endl;
	cout << " -[ Circle_0.getFarthestPoint(Circle_1) = " << shape0.getFarthestPoint(shape1) << endl;
	cout << " -[ Circle_0.intersects(Circle_1) = " << (shape0.intersects(shape1) ? "true" : "false") << endl;
	cout << " -[ Circle_0.envelops(Circle_1) = " << (shape0.envelops(shape1) ? "true" : "false") << endl;
	cout << endl;
	cout << " -[ Circle_1.getClosestPoint(Circle_0) = " << shape1.getClosestPoint(shape0) << endl;
	cout << " -[ Circle_1.getFarthestPoint(Circle_0) = " << shape1.getFarthestPoint(shape0) << endl;
	cout << " -[ Circle_1.intersects(Circle_0) = " << (shape1.intersects(shape0) ? "true" : "false") << endl;
	cout << " -[ Circle_1.envelops(Circle_0) = " << (shape1.envelops(shape0) ? "true" : "false") << endl;
	cout << "-------------------------------------------------------" << endl;
	cout << endl << endl;
}

void testRingShapeFuncs(TestRing shape0, TestRing shape1) {
	cout << "------------- Ring Shape function testing -------------" << endl;
	cout << " - With cases: - " << endl;
	cout << " - Ring_0: x=" << shape0.getCenterX() << " y=" << shape0.getCenterY() << " radius=" << shape0.getRadius() << " holeRadius=" << shape0.getHoleRadius() << endl;
	cout << " - Ring_1: x=" << shape1.getCenterX() << " y=" << shape1.getCenterY() << " radius=" << shape1.getRadius() << " holeRadius=" << shape1.getHoleRadius() << endl;
	cout << endl;
	testGeneralShapeFuncs(shape0, shape1);
	cout << "-------------------------------------------------------" << endl;
	cout << endl << endl;
}

void testRectangleShapeFuncs(TestRectangle shape0, TestRectangle shape1) {
	cout << "------------- Rectangle Shape function testing -------------" << endl;
	cout << " - With cases: - " << endl;
	cout << " - Rectangle_0: x=" << shape0.getCenterX() << " y=" << shape0.getCenterY() << " width=" << shape0.getWidth() << " height=" << shape0.getHeight() << endl;
	cout << " - Rectangle_1: x=" << shape1.getCenterX() << " y=" << shape1.getCenterY() << " width=" << shape1.getWidth() << " height=" << shape1.getHeight() << endl;
	cout << endl;
	testGeneralShapeFuncs(shape0, shape1);
	cout << "-------------------------------------------------------" << endl;
	cout << endl << endl;
}

int main() {
	
	testCircleShapeFuncs(TestCircle(1, TestPoint(0, 0)), TestCircle(1, TestPoint(0, 0)));
	testCircleShapeFuncs(TestCircle(2, TestPoint(0, 0)), TestCircle(1, TestPoint(0, 0)));
	testCircleShapeFuncs(TestCircle(1, TestPoint(2, 0)), TestCircle(1, TestPoint(0, 0)));
	testCircleShapeFuncs(TestCircle(3, TestPoint(1, 0)), TestCircle(1, TestPoint(0, 0)));

	testRingShapeFuncs(TestRing(2, 1, TestPoint(0, 0)), TestRing(2, 1, TestPoint(0, 0)));
	testRingShapeFuncs(TestRing(4, 3, TestPoint(0, 0)), TestRing(2, 1, TestPoint(0, 0)));
	testRingShapeFuncs(TestRing(2, 1, TestPoint(3, 0)), TestRing(2, 1, TestPoint(0, 0)));
	testRingShapeFuncs(TestRing(4, 1, TestPoint(0, 0)), TestRing(3, 2, TestPoint(0, 0)));

	testRectangleShapeFuncs(TestRectangle(1, 1, TestPoint(0, 0)), TestRectangle(1, 1, TestPoint(0, 0)));
	testRectangleShapeFuncs(TestRectangle(2, 2, TestPoint(0, 0)), TestRectangle(1, 1, TestPoint(0, 0)));
	testRectangleShapeFuncs(TestRectangle(1, 1, TestPoint(2, 0)), TestRectangle(1, 1, TestPoint(0, 0)));
	testRectangleShapeFuncs(TestRectangle(7, 2, TestPoint(2, 0)), TestRectangle(1, 1, TestPoint(0, 0)));

	cin.ignore();
	return 0;
}