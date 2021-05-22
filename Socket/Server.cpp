#include <iostream>
#include <winsock.h>
#include <windows.h>
#include <vector>

using namespace std;

#define SERVER_SOCKET_ERROR 1
#define SOCKET_OK 0

#pragma comment(lib, "wsock32.lib")

void socketError(char*);
char * readline(SOCKET *s);

int main()
{
	WORD sockVersion;
	WSADATA wsaData;
	int rVal;

	sockVersion = MAKEWORD(1,1);
	//start dll
	WSAStartup(sockVersion, &wsaData);

	//create socket
	SOCKET s = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

	if(s == INVALID_SOCKET)
	{
		socketError("Failed socket()");
		WSACleanup();
		return SERVER_SOCKET_ERROR;
	}

	//fill in sockaddr_in struct 

	SOCKADDR_IN sin;
	sin.sin_family = PF_INET;
	sin.sin_port = htons(8888);
	sin.sin_addr.s_addr = INADDR_ANY;

	//bind the socket
	rVal = bind(s, (LPSOCKADDR)&sin, sizeof(sin));
	if(rVal == SOCKET_ERROR)
	{
		socketError("Failed bind()");
		WSACleanup();
		return SERVER_SOCKET_ERROR;
	}

	//get socket to listen 
	rVal = listen(s, 2);
	if(rVal == SOCKET_ERROR)
	{
		socketError("Failed listen()");
		WSACleanup();
		return SERVER_SOCKET_ERROR;
	}

	//wait for a client
	SOCKET client;
	cout << "waiting for newclient" << endl;

	client = accept(s, NULL, NULL);

	cout << "newclient found" << endl;

	if(client == INVALID_SOCKET)
	{
		socketError("Failed accept()");
		WSACleanup();
		return SERVER_SOCKET_ERROR;
	}
	
	readline(&client);
	//close process
	closesocket(client);
	closesocket(s);

	WSACleanup();
	cout << "closing down"<< endl;
	return SOCKET_OK;
};

char * readline(SOCKET *client)
{
	vector<char> theVector;
	char buffer;
	int rVal;

	while(true)
	{
		rVal = recv(*(client), &buffer, 1, 0);
		if(rVal == SOCKET_ERROR)
		{
			int errorVal = WSAGetLastError();

			if(errorVal == WSAENOTCONN)
			{
				socketError("Socket not connected!");
			}
			socketError("Failed recv()");
			WSACleanup();
		}
		
		if(buffer == '\n')
		{
			char *data = new char[theVector.size() + 1];
			memset(data, 0, theVector.size()+1);
			
			for(int i=0; i<theVector.size(); i+=1)
			{
				data[i] = theVector[i];
			}

			cout << data << endl;
			return data;
		}
		else
		{
			theVector.push_back(buffer);
		}
	}
}

void socketError(char* str)
{
	MessageBox(NULL, str, "SERVER SOCKET ERROR", MB_OK);
};


