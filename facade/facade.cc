#include <iostream>
using namespace std;

class methodA
{
    public:
        void operation()
        {
            cout << "methodA" << endl;
        }
};

class methodB
{
    public:
        void operation()
        {   
            cout << "methodB" << endl;
        }   
};

class methodC
{
    public:
        void operation()
        {   
            cout << "methodC" << endl;
        }   
};

class facade
{
	public:
		methodA mA;
		methodB mB;
		methodC mC;

		void getMethod1()
		{
			mA.operation();
			mB.operation();
		}

		void getMethod2()
		{
			mA.operation();
			mC.operation();
		}
};

int main()
{
    facade *f = new facade();
	f->getMethod1();
	f->getMethod2();

    if (f) delete f;

    return 0;
}
