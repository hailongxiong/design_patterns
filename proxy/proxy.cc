#include <iostream>
using namespace std;

class girl
{
    public:
        string name;

        girl(string _name):name(_name)
        {}

        string getName()
        {
            return name;
        }
};

class action
{
    public:
        virtual void giveFlowers()
        {
            cout << "give flowers" << endl;
        }

        virtual void giveDoll()
        {
            cout << "give doll" << endl;
        }
};

class pursuit : public action
{
    public:
        void giveFlowers()
        {
            cout << "pursuit give flowers" << endl;
        }

        void giveDoll()
        {
            cout << "pursuit give doll" << endl;
        }
};

class proxy : public action
{
    public:
        girl gl;
        pursuit test;

        proxy(girl _girl):gl(_girl){
        }

        void giveFlowers()
        {
            cout << "tht girl: " << gl.getName() <<endl;
            test.giveFlowers();
        }

        void giveDoll()
        {
            cout << "the girl: " << gl.getName() << endl;
            test.giveDoll();
        }
};


int main()
{
    string name = "jiaojiao";
    girl gl(name);

    proxy p = proxy(gl);
    p.giveFlowers();
    p.giveDoll();

    return 0;
}
