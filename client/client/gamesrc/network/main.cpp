#include <WinSock2.h>
#include <windows.h>
#include <iostream>
using namespace std;

void main()
{
	auto socketTCP = socket(AF_INET, SOCK_STREAM, 0);
	cout << "walkout_client" << endl;
	shutdown(socketTCP, SD_BOTH);
}