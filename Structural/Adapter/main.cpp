
#include<iostream>
using namespace std;

class StockDataXML {
    public:
        void getStockDataXML() {
            cout<<"Stock data in XML format"<<endl;
        }
};

class StockDataJSON {
    public:
        virtual void getStockDataJSON() = 0;
        virtual ~StockDataJSON() {}
};

class StockDataAdapter : public StockDataJSON {
    StockDataXML stockDataXML;
    public:
        StockDataAdapter(StockDataXML stockDataXML) {
            this->stockDataXML = stockDataXML;
        }
        void getStockDataJSON() {
            stockDataXML.getStockDataXML();
            cout<<"Convert XML stock data to JSON"<<endl;
        }
    
};
int main() {
    StockDataXML data;
    StockDataJSON* adapter = new StockDataAdapter(data);
    adapter->getStockDataJSON();
    return 0;
}