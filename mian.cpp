/*
Web服务器的编写
根据小破站的demo 实现的

协议： TCP/IP协议， Ftp：文件传输协议
端口： 设备与外界交流的出口  ： 由操作系统分配， 只有整数 0-65535    （2个字节存储，16位）
 0-1023 ：应用程序无法访问
 80端口： 分配给http
 21： ftp
 22: ssh 远程控制

 OSI的七层模型： 物理 、 数据链路 、 网络层、 传输层、 会话层、表示层、 应用层
 五层模型： 物理 、 数据、 网络、 传输层 、应用层

 内容： web服务器、 tcp、http协议
*/

#include<iostream>
#include<winSock2.h>

#pragma comment(lib, "WS2_32.lib")  //引入静态库

using namespace std;

int main()
{
	cout << "欢迎使用 Tiny web 服务器" << endl;

	// 1、买什么手机， 确定使用的socket版本信息
	WSADATA wsdata;
	//第一个参数，期望使用的版本，  第二个参数，获取版本信息
	int isok= WSAStartup( MAKEWORD(2,2), &wsdata);
	if (isok == WSAEINVAL)
	{
		perror("socket创建请求失败");
	}
	//2、 创建一个socket 买手机
	//第一个参数， 协议族， 指定使用什么协议  AF_INET 使用IPV4
	SOCKET server =socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (server == INVALID_SOCKET)
	{
		perror(" socket创建失败");
	}

	//3、绑定端口号和IP地址
	struct sockaddr_in seraddr;
	seraddr.sin_family = AF_INET;
	seraddr.sin_port = htons(80);
	seraddr.sin_addr.S_un.S_addr = INADDR_ANY;

	isok = bind(server,(struct sockaddr*)&seraddr, sizeof(seraddr));
	
	if (isok == SOCKET_ERROR)
	{
		perror(" 创建失败");
	}

	//4、监听, 6代表同时监听5太设备数目
	listen(server, 5);

	while (1)
	{
		SOCKET client = accept(server, NULL, NULL);

		if (client == INVALID_SOCKET)
		{
			perror("accept失败");
		}

		//接受消息
		char buf[1024];
		recv(client, buf, sizeof(buf), 0);
		printf("%s 共接收到 %d 条信息",buf, strlen(buf));

		char senddata[1024]= "hello world";
		send(client,senddata,strlen(senddata),0);

		closesocket(client); //通信完毕，断开客户端
	}

	closesocket(server); //关闭服务器
	WSACleanup();

	return 0;
}