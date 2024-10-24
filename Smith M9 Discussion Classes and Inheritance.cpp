//This program asks the uer to enter the dimensions for a shape and then calculates the area of the shape.

#include <iostream>
using namespace std;

//create a class called Shape
class Shape {
public:

    virtual double getArea() = 0;
    virtual void displayArea() = 0;
};

//create a class called Rectangle that inherits from Shape
class Rectangle.public Shape {
private:
    double length;
    double width;
public:
    Rectangle(double l, double w) {
        length = l;
        width = w;
    }
    double getArea(){
        return length * width;        
    }
    void displayArea() {
        cout << "The area of the rectangle is: " << getArea() << endl;
    }
};

//create a class called Circle that inherits from Shape
class Circle.public Shape {
private:
    double radius;
public:
    Circle(double r) {
        radius = r;
    }
    double getArea() {
        return 3.14 * radius * radius;
    }
    void displayArea(){
        cout << "The area of the circle is: " << getArea() << endl;
    }
};

//main function
int main(){
    double length; 
    double width; 
    double radius;
    
    cout << "Enter the length of the rectangle: ";
    cin >> length;
    
    cout << "Enter the width of the rectangle: ";
    cin >> width;
    
    Rectangle rectangle(length, width);
    rectangle:displayArea();
    
    cout << "Enter the radius of the circle: ";
    cin >> radius;
    
    Circle circle(radius);
    circle:displayArea();
    
    return 0;
}
