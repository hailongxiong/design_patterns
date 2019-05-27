#include <iostream>
using namespace std;

class strategy
{
    public:
        virtual void getResult()
        {
            cout << "strategy" << endl;
        }
};

class strategyA : public strategy
{
   public:
        void getResult()
        {
            cout << "strategyA" << endl;
        }
};

class strategyB : public strategy
{
    public:
        void getResult()
        {
            cout << "strategyB" << endl;
        }
};

class strategyContext
{
    public:
        strategy *st = NULL;

        strategyContext(string strategy_type)
        {
            if (strategy_type == "A") {
                st = new strategyA();
            } else if (strategy_type == "B") {
                st = new strategyB();
            }
        }

        void getResult()
        {
            st->getResult();
        }
};

int main()
{
    cout << "strategy design patterns "<< endl;
    while(1) {
        string strategy_type;
        cout << "input strategy_type: " << endl;
        cin >> strategy_type;
        if (strategy_type != "A" && strategy_type != "B") {
            cout << "no this strategy type!" << endl;
            continue;
        }

        strategyContext sc(strategy_type);
        sc.getResult();
    }

    return 0;
}

