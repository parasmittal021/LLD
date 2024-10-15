#include <iostream>
using namespace std;

class Shape {
    public:
    virtual Shape* clone() = 0;
    virtual void draw() = 0;
    virtual ~Shape() {}
};

class Circle: public Shape {
    public:
    Shape* clone() {
        return new Circle(*this);
    }
    void draw() {
        cout<<"Circle draw"<<endl;
    }
};

int main() {
    Shape* circle = new Circle();
    Shape* anotherCircle = circle->clone();
    circle->draw();
    anotherCircle->draw();
    return 0;
}