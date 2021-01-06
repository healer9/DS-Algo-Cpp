//leetcode.com/problems/lru-cache/
#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

class LRUCache
{
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> myMap; //(key,address) pair
    int cacheSize;

    void reorderCache(int key, int value)
    {
        cache.erase(myMap[key]); // deletion takes place in O(1) if we know the pointer of the node
        cache.push_front({key, value});
        myMap[key] = cache.begin();
    }

public:
    LRUCache(int size) : cacheSize(size) {}
    int get(int key)
    {
        if (myMap.find(key) != myMap.end())
        {
            reorderCache(key, (*myMap[key]).second);
            return (*myMap[key]).second;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (myMap.find(key) != myMap.end())
        {
            reorderCache(key, value);
        }
        else
        {
            cache.push_front({key, value});
            myMap[key] = cache.begin();
            if (cache.size() > cacheSize)
            {
                myMap.erase(cache.back().first);
                cache.pop_back();
            }
        }
    }
};

int main(int argc, char *argv[])
{
    LRUCache C1(2);
    C1.put(1, 1);
    C1.put(2, 2);

    C1.get(1);
    cout << endl;

    C1.put(3, 3);

    C1.get(2);
    cout << endl;

    C1.put(4, 4);
    C1.get(1);
    cout << endl;
    C1.get(3);
    cout << endl;
    C1.get(4);
    cout << endl;

    return 0;
}