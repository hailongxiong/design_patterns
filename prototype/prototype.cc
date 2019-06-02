#include <iostream>
using namespace std;

class prototype
{
    public:
        virtual prototype* clone() = 0;
        virtual void show() = 0;
        virtual void setName(string name) = 0;
};

class subPrototype: public prototype
{
    public:
        subPrototype(string _name)
        {
            name = _name;
        }

        prototype* clone()
        {
            subPrototype *p = new subPrototype(name);
            *p = *this;
            return p;
        }

        void setName(string _name)
        {
            name = _name;
        }

        void show()
        {
            cout << "the name: "<<name<<endl;
        }
    private:
        string name;
};

int main()
{
    prototype *sp = new subPrototype("test");
    sp->show();

    prototype *sp1 = sp->clone();
    sp1->setName("test1");
    sp1->show();

    return 0;
}

