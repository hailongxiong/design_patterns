#include <iostream>
using namespace std;

class Food{
    public:
        string name = "food";

        string getName() {
            return name;
        }

        virtual double price() {
            return 0;
        }
};

class TornCake : public Food{
    public:
        TornCake() {
            name = "手抓饼";
        }

        double price () {
            return 4;
        }
};

class Condiment : public Food{
    virtual string getName() {
        return "";
    }
};

class FireEgg : public Condiment {
    private:
        Food *food;

    public:
        FireEgg(Food *food) {
            this->food = food;
        }

        string getName() {
            return (food->getName() + "煎蛋");
        }

        double price() {
            return food->price() + 2;
        }
};

int main()
{
    Food *tornCake = new TornCake();
    cout<< "the tornCoke price: "<<tornCake->price()<<endl;
    cout<< "the tornCoke name: "<<tornCake->getName()<<endl;

    tornCake = new FireEgg(tornCake);
    tornCake = new FireEgg(tornCake);
    cout<< "the tornCoke price: "<<tornCake->price()<<endl;
    cout<< "the tornCoke name: "<<tornCake->getName()<<endl;

    return 0;
}
