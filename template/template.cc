#include <iostream>
using namespace std;

class abstractClass
{
    public:
        void getMethod()
        {
            operation1();
            cout << "abstrace class method" << endl;
            operation2();
        }

    protected:
        virtual void operation1()
        {
            cout << "default operation1 " << endl;
        }

        virtual void operation2()
        {
            cout << "default operation2 " << endl;
        }
};

class temp1Class: public abstractClass
{
    protected:
        void operation1()
        {
            cout << "temp1Class operation1 " << endl;
        }

        void operation2()
        {
            cout << "temp1Class operation2 " << endl;
        }
};

class temp2Class: public abstractClass
{
    protected:
        void operation1()
        {   
            cout << "temp2Class operation1 " << endl;
        }   

        void operation2()
        {   
            cout << "temp2Class operation2 " << endl;
        }   
};


int main()
{
    abstractClass *temp1 = new temp1Class();
	temp1->getMethod();

    abstractClass *temp2 = new temp2Class();
    temp2->getMethod();
    return 0;
}
