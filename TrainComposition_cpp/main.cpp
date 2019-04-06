#include <stdexcept>
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

#define SOL_1 /*delete it if the second solution is desired*/
#ifdef SOL_1
class TrainComposition
{
public:
    vector<int> TrainWagons;
    vector<int>::iterator it;
    void attachWagonFromLeft(int wagonId)
    {
        it = TrainWagons.begin();
        TrainWagons.insert(it,1,wagonId);
    }

    void attachWagonFromRight(int wagonId)
    {
        TrainWagons.push_back(wagonId);
    }

    int detachWagonFromLeft()
    {
        int left = TrainWagons.front();
        TrainWagons.erase(TrainWagons.begin());
        return left;
    }

    int detachWagonFromRight()
    {
        int right  = TrainWagons.back();
        TrainWagons.pop_back();
        return right;
    }
};
#else
class TrainComposition
{
public:
    deque <int> TrainWagons;
    void attachWagonFromLeft(int wagonId)
    {
        TrainWagons.push_front(wagonId);
    }

    void attachWagonFromRight(int wagonId)
    {
        TrainWagons.push_back(wagonId);
    }

    int detachWagonFromLeft()
    {
        int left = TrainWagons.front();
        TrainWagons.pop_front();
        return left;
    }

    int detachWagonFromRight()
    {
        int right  = TrainWagons.back();
        TrainWagons.pop_back();
        return right;
    }
};

#endif

#ifndef RunTests
int main()
{
    TrainComposition tree;
    tree.attachWagonFromLeft(7);
    tree.attachWagonFromLeft(13);
    std::cout << tree.detachWagonFromRight() << "\n"; // 7 
    std::cout << tree.detachWagonFromLeft(); // 13
}
#endif
