// main.cpp : Defines the entry point for the console application.
//

#include "MBO_Object.h"
#include <cstdlib>  
#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

int main()
{
	srand((unsigned)time(NULL));

	int popsize = 0, maxt = 0, dim;
	// cin>>popsize>>dim>>n>>maxt>>cr>>f;
	popsize = 50;
	dim = 10;
	maxt = 50;

	MBO_Object mbo(popsize, dim, maxt);
	clock_t start = clock();
	mbo.MBO();
	clock_t end = clock();
	mbo.output();

	ofstream fout;  //output file
	fout.open("output.txt", ios::out | ios::app);  //输出文件

	if (!fout.is_open())
	{
		cout << "Error opening file"; exit(1);
	}

	streambuf *coutbackup;
	coutbackup = cout.rdbuf(fout.rdbuf());  //用 rdbuf() 重新定向

	cout << "CLOCKS_PER_SEC  " << CLOCKS_PER_SEC << endl;
	cout << "the time is:  " << (double)(end - start) / CLOCKS_PER_SEC << endl;

	// Close the file
	fout.close();

	cout.rdbuf(coutbackup);  //取消，恢复屏幕输出

	return 0;
}
