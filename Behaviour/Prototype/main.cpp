
#include <iostream>
using namespace std;

class Shape {
    public:
    int x;
    virtual Shape* clone() = 0;
    virtual void draw() = 0;
    virtual void setX(int val) {}
};

class Rectangle : public Shape {
    public:
    int x = 12;
    Shape* clone() {
        return new Rectangle(*this);
    }

    void setX(int val) {
       this->x = val;
    }

    void draw() {
        cout << "Drawing a rectangle " << this->x << endl;
    }
};


int main() {
    Shape* rectangle = new Rectangle();
    Shape* rectangleClone = rectangle->clone();
    rectangle->setX(15);
    rectangle->draw();
    rectangleClone->draw();
    //Drawing a rectangle 15
    // Drawing a rectangle 12
    return 0;
}