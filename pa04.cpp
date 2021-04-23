#include "MyVector.h"

int main()
{
    MyVector<int> v;

    cout << v.size() << endl;
    v.push_back(4000);
    cout << v.at(0) << endl;
    cout << v.capacity() << endl;
    v.reserve(10);
    cout << v.capacity() << endl;

    v.push_back(200);
    v.push_back(100);
    v.insert(v.begin(), 3);
    v.insert(v.end(), 20);
    int j = 0;

    for(auto i = v.begin(); i < v.end(); i++)
    {
        cout << v.at(j) << endl;
        j++;
    }

    j = 0;

    for(auto i = 0; i < v.size(); i++)
    {
        cout << v[j] << endl;
        j++;
    }
    return 0;
}
