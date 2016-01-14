#ifndef __TCPMSG__
#define __TCPMSG__

#include "cocos2d.h"
#include "Queue.h"
#include "ODSocket.h"
#include <thread>

//#ifdef WIN32
//#include <windows.h>
//#else
//#include <unistd.h>
//#endif

USING_NS_CC;

#define SLEEP_TIME 50

//TCP������IP&&�˿�;
#define SERVER_HOST "192.168.137.3"
#define SERVER_PORT 11009

class TcpMsg
{
public:
	TcpMsg();
	~TcpMsg();

	static TcpMsg* shareTcpMsg();
	void tcp_start();
	void tcp_stop();
	bool isRuning();

	Pocket* MakePocket(const char* msg, int msgid);
	Pocket* MakePocketFromData(const char* msg);

	//��ȡ������Ϣ����;
	Queue* getRecvQueue();
	Queue* getSendQueue();

	void pushSendQueue(std::string str, int msgType);//���뷢�Ͷ���;
	void pushRecvQueue(std::string str);//������ն���;

	void recvFunc(void);//������Ϣ����;
	void sendFunc(void);//������Ϣ����;
	static std::mutex mutex;


	void th_recv(TcpMsg* TcpMsg);//���������߳�;
	void th_send(TcpMsg* TcpMsg);//���������߳�;
protected:
	void tcpCheck(void);//TCP״̬��ⷽ��;


	

	//������Ϣ����;
	Queue* m_recvQueue;
	//������Ϣ����;
	Queue* m_sendQueue;
private:
	bool m_isRuning;//�߳����б�־;
	ODSocket m_socket;


};

#endif