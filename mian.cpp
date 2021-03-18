/*
Web�������ı�д
����С��վ��demo ʵ�ֵ�

Э�飺 TCP/IPЭ�飬 Ftp���ļ�����Э��
�˿ڣ� �豸����罻���ĳ���  �� �ɲ���ϵͳ���䣬 ֻ������ 0-65535    ��2���ֽڴ洢��16λ��
 0-1023 ��Ӧ�ó����޷�����
 80�˿ڣ� �����http
 21�� ftp
 22: ssh Զ�̿���

 OSI���߲�ģ�ͣ� ���� �� ������· �� ����㡢 ����㡢 �Ự�㡢��ʾ�㡢 Ӧ�ò�
 ���ģ�ͣ� ���� �� ���ݡ� ���硢 ����� ��Ӧ�ò�

 ���ݣ� web�������� tcp��httpЭ��
*/

#include<iostream>
#include<winSock2.h>

#pragma comment(lib, "WS2_32.lib")  //���뾲̬��

using namespace std;

int main()
{
	cout << "��ӭʹ�� Tiny web ������" << endl;

	// 1����ʲô�ֻ��� ȷ��ʹ�õ�socket�汾��Ϣ
	WSADATA wsdata;
	//��һ������������ʹ�õİ汾��  �ڶ�����������ȡ�汾��Ϣ
	int isok= WSAStartup( MAKEWORD(2,2), &wsdata);
	if (isok == WSAEINVAL)
	{
		perror("socket��������ʧ��");
	}
	//2�� ����һ��socket ���ֻ�
	//��һ�������� Э���壬 ָ��ʹ��ʲôЭ��  AF_INET ʹ��IPV4
	SOCKET server =socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (server == INVALID_SOCKET)
	{
		perror(" socket����ʧ��");
	}

	//3���󶨶˿ںź�IP��ַ
	struct sockaddr_in seraddr;
	seraddr.sin_family = AF_INET;
	seraddr.sin_port = htons(80);
	seraddr.sin_addr.S_un.S_addr = INADDR_ANY;

	isok = bind(server,(struct sockaddr*)&seraddr, sizeof(seraddr));
	
	if (isok == SOCKET_ERROR)
	{
		perror(" ����ʧ��");
	}

	//4������, 6����ͬʱ����5̫�豸��Ŀ
	listen(server, 5);

	while (1)
	{
		SOCKET client = accept(server, NULL, NULL);

		if (client == INVALID_SOCKET)
		{
			perror("acceptʧ��");
		}

		//������Ϣ
		char buf[1024];
		recv(client, buf, sizeof(buf), 0);
		printf("%s �����յ� %d ����Ϣ",buf, strlen(buf));

		char senddata[1024]= "hello world";
		send(client,senddata,strlen(senddata),0);

		closesocket(client); //ͨ����ϣ��Ͽ��ͻ���
	}

	closesocket(server); //�رշ�����
	WSACleanup();

	return 0;
}