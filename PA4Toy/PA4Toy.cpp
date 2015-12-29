// PA4Toy.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
void output(int *a) {
	for (int i = 0; i < 8; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
void exchange(int *a,int &count) {
	for (int i = 0; i <4; i++)
	{
		swap(a[i], a[i + 4]);
	}
	count++;
}
void shift(int *a,int &count) {
	int temp[4] = {0};
	temp[0] = a[1];
	temp[1] = a[2];
	temp[2] = a[3];
	temp[3] = a[0];
	for (size_t i = 0; i < 4; i++)
	{
		a[i] = temp[i];
	}
	output(a);
	temp[0] = a[5];
	temp[1] = a[6];
	temp[2] = a[7];
	temp[3] = a[4];
	for (size_t i = 0; i < 4; i++)
	{
		a[i] = temp[i+4];
	}
	output(a);
	count++;
}
void turn(int *a,int &count) {
	int temp[4];
	temp[0] = a[1];
	temp[1] = a[2];
	temp[2] = a[6];
	temp[3] = a[5];
	a[1] = temp[3];
	a[2] = temp[0];
	a[6] = temp[1];
	a[5] = temp[2];
	count++;
}
bool check(int *a) {
	int standard[8] = { 1,2,3,4,8,7,6,5 };
	for (int i = 0; i < 8; i++)
	{
		if (a[i] != standard[i])return false;
	}
	return true;
}
int main()
{
	int a[8];
	for (int i = 0; i < 8; i++)
	{
		cin >> a[i];
	}
	int count=0;
	int result=-1;
	swap(a[4], a[7]);
	swap(a[5], a[6]);
	if (check(a))
	{
		result = 0;
	}
	else
	{
		for (int i = 0; i < 3; i++)
		{
			shift(a, count);
			if (check(a)) {
				result = count;
				break;
			}
		}
	}
	count = 0;
	if (result==-1)
	{
		exchange(a, count);
		if (check(a))
		{
			result = count;
		}
		else
		{
			for (int i = 0; i < 3; i++)
			{
				shift(a, count);
				if (check(a)) {
					result = count;
					break;
				}
			}
		}
	}
	cout << result << endl;
    return 0;

}

