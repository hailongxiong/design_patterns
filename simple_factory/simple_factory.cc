#include <iostream>
using namespace std;

class operation
{
   public:
        double numberA;
        double numberB;

    public:
        virtual double getResult()
        {
            return 0;
        }
};

class add : public operation
{
    double getResult()
    {
        return numberA+numberB;
    }
};

class sub : public operation
{
    double getResult()
    {
        return numberA-numberB;
    }
};

class mul : public operation
{
    double getResult()
    {
        return numberA*numberB;
    }
};

class div : public operation
{
    double getResult()
    {
        if (numberB==0)
        {
            cout <<"could not 0 " << endl;
            return 0;
        } else {
            return numberA/numberB;
        }
    }
};

class factory
{
    public:
        static operation* getOperation(string opera)
        {
            operation *op = NULL;
            if (opera == "+")
            {
                op = new add();
            } else if(opera == "-") {
                op = new sub();
            } else if(opera == "*") {
                op = new mul();
            } else if (opera == "/") {
                op = new div();
            }

            return op;
        }
};

int main()
{
    cout << "factory design pattern" << endl;
    while(1)
    {
        double numberA, numberB;
        string opera;
        cout << "input numberA: "<<endl;
        cin >> numberA;
        cout << "input numberB: "<<endl;
        cin>>numberB;
        cout << "input opera:" << endl;
        cin>>opera;

        factory *fac = new factory();
        operation *op = fac->getOperation(opera);
        if (op == NULL)
        {
            cout << "the opera is wrong." << endl;
            continue;
        }

        op->numberA = numberA;
        op->numberB = numberB;
        double result = op->getResult();
        cout << "the result is: " << result << endl;
    }

    return 0;
}

