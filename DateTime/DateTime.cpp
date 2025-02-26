#include <iostream>
#include "Datime.hpp"

using namespace std;
using namespace Datime;

int main()
{
	tanggal tgl{2024,12,29};
	for (int i = 0; i < 10; i++)
	{
		cout << tgl << endl;
		tgl -= hari{7 };
	}
}

