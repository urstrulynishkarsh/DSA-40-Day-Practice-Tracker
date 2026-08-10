#include<iostream>
#include<vector>
#include<list>
#include<map>
using namespace std;


class LRUCache{
    public:
    list<int> dll;
    map<int,pair<list<int>::iterator,int> > mp;
    int n;
    LRUCache(int capacity)
    {
        this->n=capacity;
    }

    void makerecentlyused(int key)
    {
        dll.erase(mp[key].first);
        dll.push_front(key);
        mp[key].first=dll.begin();
    }

    int get(int key)
    {
        if(mp.find(key)==mp.end())
        {
            return -1;
        }
        makerecentlyused(key);
        return mp[key].second;
    }

    void put(int key, int value)
    {
        if(mp.find(key)!=mp.end())
        {
            mp[key].second=value;
            makerecentlyused(key);
        }
        else{
            dll.push_front(key);
            mp[key]={dll.begin(),value};
            n--;
        }
        if(n<0)
        {
            int key_to_be_deleted=dll.back();
            mp.erase(key_to_be_deleted);
            dll.pop_back();
            n++;
        }
    }

};

int main()
{
    int capacity;
    cin >> capacity;

    LRUCache* obj = new LRUCache(capacity);

    int q;
    cin >> q;

    while(q--)
    {
        int type;
        cin >> type;

        if(type == 1)
        {
            // get(key)
            int key;
            cin >> key;

            cout << obj->get(key) << endl;
        }
        else if(type == 2)
        {
            // put(key, value)
            int key, value;
            cin >> key >> value;

            obj->put(key, value);
        }
    }

    delete obj;

    return 0;
}