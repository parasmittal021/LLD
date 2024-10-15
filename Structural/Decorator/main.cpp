#include <iostream>
#include <string>
using namespace std;

class Coffee {
    public:
        virtual string getDescription() = 0;
        virtual int cost() = 0;
        virtual ~Coffee() {}
};

class SimpleCoffee : public Coffee {
    public:
        string getDescription() {
            return "Coffee with water, coffee power";
        }
        int cost() {
            return 50;
        }
};

class CoffeeDecorator: public Coffee {
    protected:
        Coffee* coffee;
    public:
        CoffeeDecorator(Coffee* coffee){
            this->coffee = coffee;
        }
        string getDescription() {
            return coffee->getDescription();
        }
        int cost() {
            return coffee->cost();
        } 
};

class MilkDecorator: public CoffeeDecorator  {
    public:
        MilkDecorator(Coffee* coffee): CoffeeDecorator(coffee) {
            
        }
        string getDescription() {
            cout<<"here"<<endl;
            return coffee->getDescription() + ", Milk";
        }
        int cost() {
            return coffee->cost()+20;
        } 
};

int main() {
    Coffee* simpleCoffee = new SimpleCoffee();
    Coffee* milkDecorator = new MilkDecorator(simpleCoffee);
    cout<<milkDecorator->getDescription()<<endl;
    cout<<milkDecorator->cost()<<endl;
}

