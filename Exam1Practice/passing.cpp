#include <iostream>
#include <vector>

using namespace std;

void work(vector<int> &data)
{
    for (auto &x : data)
    {
        x++;
    }
}

int main()
{
    std::vector<int> data = {1, 2, 3, 4, 5};
    work(data);

    for (auto x : data)
    {
        cout << x << endl;
    }

    return 0;
}