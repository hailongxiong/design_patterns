#include <iostream>
#include <mutex>
using namespace std;

class Singleton
{
    private:
        Singleton()
        {}

        static Singleton *instance;

    public:
        static Singleton * getInstance()
        {
            if (instance == nullptr)
            {
                instance = new Singleton();
            }

            return instance;
        }
};

Singleton* Singleton::instance = new Singleton();

mutex mut;
class MulThreadSingleton
{
    private:
        MulThreadSingleton()
        {}

        static MulThreadSingleton *instance;

    public:
        static MulThreadSingleton * getInstance()
        {
            if (instance == nullptr)
            {
                mut.lock();
                instance = new MulThreadSingleton();
                mut.unlock();
            }

            return instance;
        }
};

MulThreadSingleton* MulThreadSingleton::instance = new MulThreadSingleton();


int main()
{
    Singleton *s1 = Singleton::getInstance();
    Singleton *s2 = Singleton::getInstance();
    if (s1 == s2)
    {
        cout << "test Singleton "<< endl;
    }

	MulThreadSingleton *s3 = MulThreadSingleton::getInstance();
	MulThreadSingleton *s4 = MulThreadSingleton::getInstance();
	if (s3 == s4)
	{
		cout << "test multhread singleton " << endl;
	}

    return 0;
}
