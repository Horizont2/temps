#include <iostream>
#include <vector>
#include <cmath>
#include <memory>

using namespace std;

class Shape {
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void display() const = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override { return M_PI * radius * radius; }
    double perimeter() const override { return 2 * M_PI * radius; }
    void display() const override {
        cout << "Circle: radius = " << radius
             << ", area = " << area()
             << ", perimeter = " << perimeter() << endl;
    }
};

class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() const override { return width * height; }
    double perimeter() const override { return 2 * (width + height); }
    void display() const override {
        cout << "Rectangle: width = " << width
             << ", height = " << height
             << ", area = " << area()
             << ", perimeter = " << perimeter() << endl;
    }
};

class Triangle : public Shape {
    double a, b, c;
public:
    Triangle(double side1, double side2, double side3) : a(side1), b(side2), c(side3) {}
    double area() const override {
        double s = (a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }
    double perimeter() const override { return a + b + c; }
    void display() const override {
        cout << "Triangle: sides = " << a << ", " << b << ", " << c
             << ", area = " << area()
             << ", perimeter = " << perimeter() << endl;
    }
};

int main() {
    vector<shared_ptr<Shape>> shapes;

    shapes.push_back(make_shared<Circle>(5.0));
    shapes.push_back(make_shared<Rectangle>(4.0, 6.0));
    shapes.push_back(make_shared<Triangle>(3.0, 4.0, 5.0));

    for (const auto& shape : shapes) {
        shape->display();
    }

    return 0;
}
