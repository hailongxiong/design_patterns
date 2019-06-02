#include <iostream>
using namespace std;

class operation
{
    public:
        double numberA;
        double numberB;

        virtual double getResult()
        {
            return 0;
        }
};

class add: public operation
{
    double getResult()
    {
        return numberA+numberB;
    }
};

class sub: public operation
{
    double getResult()
    {
        return numberA-numberB;
    }
};

class factory
{
    public:
        virtual operation* getOperation()
        {
            return NULL;
        }
};

class addFactory: public factory
{
    operation * getOperation()
    {
        operation *op = new add();
        return op;
    }
};

class subFactory: public factory
{
    operation * getOperation()
    {
        operation *op = new sub();
        return op;
    }
};

int main()
{
    factory *addF = new addFactory();
    operation *op = addF->getOperation();
    op->numberA=1;
    op->numberB=2;
    double result = op->getResult();
    cout << "the add result: " << result << endl;

    factory *subF = new subFactory();
    operation *op1 = subF->getOperation();
    op1->numberA=3;
    op1->numberB=1;
    double sub_result = op->getResult();
    cout << "the sub result: " << sub_result << endl;
    
    return 0;
}
