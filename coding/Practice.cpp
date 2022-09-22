#include <iostream>
#include <string>
#include <fstream>

#include <vector>
#include <deque>
#include <algorithm>

using namespace std;



void printDeque(deque<int>& d) 
{
	for (deque<int>::iterator it = d.begin(); it != d.end(); it++) {
		cout << *it << " ";

	}
	cout << endl;
}

int main()
{
    vector<int> v;
    for(int i=0; i<10;i++)
    {
        v.push_back(i);
    }

    deque<int> d;
    d.assign(v.begin(),v.end());

    deque<int>::iterator p = d.begin();
    while(p!=d.end())
    {
        cout<< *(p++) <<endl;
    }

    d.insert(d.begin()+1,d.begin(),p);
    sort(d.begin(),d.end());
    reverse(d.begin(),d.end());

    p = d.begin();
    while(p!=d.end())
    {
        cout<< *(p++) <<endl;
    }

    system("pause"); 
    return 0;
}