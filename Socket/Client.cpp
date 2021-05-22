#include <windows.h>
#include <winsock.h>
#include <iostream>

using namespace std;

#pragma comment(lib, "wsock32.lib")

#define CS_ERROR 1
#define CS_OK 0

void sError(char*);

int main()
{

	WORD version;
	WSADATA wsaData;
	int rVal=0;

	version = MAKEWORD(1,1);

	WSAStartup(version,(LPWSADATA)&wsaData);

	LPHOSTENT hostEntry;

	//store information about the server
	hostEntry = gethostbyname("127.0.0.1");

	if(!hostEntry)
	{
		sError("Failed gethostbyname()");
		//WSACleanup();
		return CS_ERROR;
	}

	//create the socket
	SOCKET theSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

	if(theSocket == SOCKET_ERROR)
	{
		sError("Failed socket()");
		return CS_ERROR;
	}

	//Fill in the sockaddr_in struct
	SOCKADDR_IN serverInfo;

	serverInfo.sin_family = PF_INET;
	serverInfo.sin_addr = *((LPIN_ADDR)*hostEntry->h_addr_list);

	serverInfo.sin_port = htons(8888);

	rVal=connect(theSocket,(LPSOCKADDR)&serverInfo, sizeof(serverInfo));
	if(rVal==SOCKET_ERROR)
	{
		sError("Failed connect()");
		return CS_ERROR;
	}

	char *buf = "simpleservermessage\n";

	rVal = send(theSocket, buf, strlen(buf), 0);

	if(rVal == SOCKET_ERROR)
	{
		sError("Failed send()");
		return CS_ERROR;
	}


	closesocket(theSocket);
	cout << "closing client"<< endl;
	WSACleanup();
	
	return CS_OK;
}

void sError(char *str)
{
	MessageBox(NULL, str, "SOCKET ERROR", MB_OK);
	WSACleanup();
}

