#include <iostream>
#include "Datime.hpp"

using namespace std;
using namespace Datime;

int main()
{
	tanggalwaktu tgl{ 2025,2,1,23,59,50 };
	//for (int i = 0; i < 30; i++)
	//{
	//	cout << tgl << endl;
	//	tgl += detik{1};
	//}
	tanggalwaktu tgl2{ 2025,2,3 };

	cout << tgl2.tanggal() - tgl.tanggal() << "\n";
}

