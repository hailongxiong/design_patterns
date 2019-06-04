#include <iostream>
using namespace std;

class Product
{
    public:
        void setPartA(int param)
        {
            partA = param;
        }

        void setPartB(int param)
        {
            partB = param;
        }

        void setPartC(int param)
        {
            partC = param;
        }

        void show()
        {
            cout<<"A: "<<partA<<"B: "<<partB<<"C: "<<partC<<endl;
        }
    private:
        int partA;
        int partB;
        int partC;
};

class AbstractBuilder
{
    public:
        virtual void createProduct() = 0;
        virtual void buildPartA(int param) = 0;
        virtual void buildPartB(int param) = 0;
        virtual void buildPartC(int param) = 0;
    
        virtual Product* getProduct()=0;
};

class Builder: public AbstractBuilder
{
    public:
        void createProduct()
        {
            curProduct = new Product();
        }

        void buildPartA(int param)
        {
            curProduct->setPartA(param);
        }

        void buildPartB(int param)
        {
            curProduct->setPartB(param);
        }

        void buildPartC(int param)
        {
            curProduct->setPartC(param);
        }

        Product* getProduct()
        {
            return curProduct;
        }

    private:
        Product * curProduct;
};

class Director
{
    public:
        Director(AbstractBuilder *builder)
        {
            curBuilder = builder;
        }

        void construct()
        {
            if (!curBuilder)
                return;

            curBuilder->createProduct();
            curBuilder->buildPartA(1);
            curBuilder->buildPartB(2);
            curBuilder->buildPartC(3);
        }
    
    private:
        AbstractBuilder *curBuilder;
};


int main()
{
    AbstractBuilder *builder = new Builder();
    Director* director = new Director(builder);

    director->construct();

    Product* product = builder->getProduct();
    product->show();
    return 0;
}
