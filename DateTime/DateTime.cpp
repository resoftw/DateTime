#include <iostream>
#include "Datime.hpp"

using namespace std;
using namespace Datime;

int main()
{
    auto y1 = tahun{ 1950 };
    cout << y1 << "\n";
    cout << y1++ << "\n";
    y1 += 100;
    cout << y1 << "\n";
    y1 += tahun{50};
    cout << y1 << "\n";
}

