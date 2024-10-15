#include<string>
#include <iostream>
#include<unordered_map>
using namespace std;

class Shape {
    public:
        virtual void draw(int x, int y) = 0;
        virtual ~Shape() {}
};

class Circle : public Shape {
    string color;
    int size;
    public:
        Circle(string color, int size) {
            this->color = color;
            this->size = size;
        }
        void draw(int x, int y) {
            cout<<"Draw circle on "<<x<<" "<<y<<endl;
        }
};

class CircleFactory {
  static unordered_map<string, Shape*> circleMap;
    public:
    static Shape* createCircle(string color, int size){
        string key = color+"_"+to_string(size);
        if(circleMap.find(key) == circleMap.end()){
            circleMap[key] = new Circle(color, size);
        }
        return circleMap[key];
    }
    
    ~CircleFactory() {
        for (auto& pair : circleMap) {
            delete pair.second;
        }
    }
};

unordered_map<string, Shape*> CircleFactory::circleMap;

int main() {
    Shape* circle = CircleFactory::createCircle("Red", 5);
    circle->draw(10, 12);
    delete circle;
    return 0;
}