#include <iostream>
#include "Datime.hpp"

using namespace std;
using namespace Datime;

int main()
{
	tanggalwaktu tgl{ {2025,2,1},{0,0,0} };
	for (int i = 0; i < 30; i++)
	{
		cout << tgl << endl;
		tgl += detik{ 12382 };
	}
}

