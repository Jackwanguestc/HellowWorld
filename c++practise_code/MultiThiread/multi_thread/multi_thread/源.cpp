#include<Windows.h>
#include<iostream>
using namespace std;
DWORD WINAPI Fun1Proc(
	LPVOID lpParameter
	);
DWORD WINAPI Fun2Proc(
	LPVOID lpParameter
	);
int index = 0;
int tickets = 200;
HANDLE hMutex;
int main()
{
	HANDLE hThread1;
	HANDLE hThread2;
	
	
	hThread1 = CreateThread(NULL, 0, Fun1Proc, NULL, 0, NULL);
	hThread2 = CreateThread(NULL, 0, Fun2Proc, NULL, 0, NULL);
	CloseHandle(hThread1);
	CloseHandle(hThread2);
	hMutex = CreateMutex(NULL, FALSE, NULL);
	if (hMutex == NULL)
	{
		printf("CreateMutex error: %d\n", GetLastError());
		return -1;
	}
	while (tickets > 0)
	{
		
	}
	//Sleep(4000);
	system("pause");
	return 0;
}

DWORD WINAPI Fun1Proc(LPVOID lpParameter)
{
	while (true)
	{
		WaitForSingleObject(hMutex, INFINITE);
		if (tickets > 0)
			cout << "thread1 sell tickets:" << tickets-- << endl;
		else
			break;
		ReleaseMutex(hMutex);
	}
	return 0;
}

DWORD WINAPI Fun2Proc(LPVOID lpParameter)
{
	while (true)
	{
		WaitForSingleObject(hMutex, INFINITE);
		if (tickets > 0)
			cout << "thread2 sell tickets:" <<tickets--<< endl;
		else
			break;
		ReleaseMutex(hMutex);
	}
	return 0;
}
