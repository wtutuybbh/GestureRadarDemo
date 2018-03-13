// GestureRadarDemo.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "GestureRadarSDK.h"

#include <string>
#include <Windows.h>
#include <iostream>

using namespace std;

#pragma comment(lib,"GestureRadarSDK.lib")  


int CallBackFun(int x, int y, int reserver, int z)
{
	cout << "X: " << x << " Y:"<< y << " reserve:" << reserver << " Z:" << z << endl;
	return 0;
}
int main()
{
	/*
		First Way : Asynchronous call 
		Developer register self define function. The function will invoking it self when gesture radar data are coming.
	*/
	//registerLoopCallBack(CallBackFun);
	//getchar();
	//releaseCallBack();



	/*
		Second Way : Synchronous mode
		1. inial hw
		2. get data
		3. release hw
	*/
	if (initialHW(-1))
	{
		while (true)
		{
			int x, y, reserver, z;
			getRawData(x, y, reserver, z);
			cout << "X: " << x << " Y:" << y << " reserve:" << reserver << " Z:" << z << endl;
		}
	}
	releaseHW();
	getchar();

    return 0;
}

