#include <iostream>
using namespace std;

class Visitor;
class Shape {
    public:
        virtual void accept(Visitor* visitor) = 0;
        virtual ~Shape() {}
};

class Visitor {
    public:
        virtual void visitCircle(Shape* shape) = 0;
        virtual void visitRectangle(Shape* shape) = 0;
};


class Circle: public Shape {
    public:
        void accept(Visitor* visitor) {
            visitor->visitCircle(this);
        }
};

class Rectangle: public Shape {
    public:
        void accept(Visitor* visitor) {
            visitor->visitRectangle(this);
        }
};

class RenderVisitor: public Visitor {
    public:
        void visitCircle(Shape* shape) {
            cout<<"Rendering Circle"<<endl;
        }
        void visitRectangle(Shape* shape) {
            cout<<"Rendering Rectangle"<<endl;
        }
};

class AreaVisitor: public Visitor {
    public:
        void visitCircle(Shape* shape) {
            cout<<"Calcuate area Circle"<<endl;
        }
        void visitRectangle(Shape* shape) {
            cout<<"Calcuate area Rectangle"<<endl;
        }
};

int main() {
    Visitor* renderVisitor = new RenderVisitor();
    Visitor* areaVisitor = new AreaVisitor();
    Shape* circle = new Circle();
    Shape* rectangle = new Rectangle();
    circle->accept(renderVisitor);
    circle->accept(areaVisitor);
    rectangle->accept(renderVisitor);
    rectangle->accept(areaVisitor);
    return 0;
}