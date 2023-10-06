//װ����ģʽ����������������ĳЩ���Ի��߶Ա�װ�ζ������ĳЩ�޸�
//����Ӧ�ó�����Java��IO��
#include <iostream>

class Stream
{
public:
	virtual void Read(int number) = 0;
	virtual void Seek(int position) = 0;
	virtual void Write(char data) = 0;

	virtual ~Stream() {}
};

//������
class FileStream :public Stream
{
public:
	virtual void Read(int number)
	{
		std::cout << "FileStream Read" << std::endl;
	}

	virtual void Seek(int position)
	{
		std::cout << "FileStream Seek" << std::endl;
	}
	virtual void Write(char data)
	{
		std::cout << "FileStream Write" << std::endl;
	}
};

class NetworkStream :public Stream
{
public:
	virtual void Read(int number)
	{
		std::cout << "NetworkStream Read" << std::endl;
	}

	virtual void Seek(int position)
	{
		std::cout << "NetworkStream Seek" << std::endl;
	}
	virtual void Write(char data)
	{
		std::cout << "NetworkStream Write" << std::endl;
	}
};

class MemoryStream :public Stream
{
public:
	virtual void Read(int number)
	{
		std::cout << "MemoryStream Read" << std::endl;
	}

	virtual void Seek(int position)
	{
		std::cout << "MemoryStream Seek" << std::endl;
	}
	virtual void Write(char data)
	{
		std::cout << "MemoryStream wRITE" << std::endl;
	}
};

//��չ����
class DecoratorStream :public Stream
{
public:
	Stream* stream;
	DecoratorStream(Stream* stm) :stream(stm)
	{

	}
	virtual void Read(int number)
	{
		stream->Read(number);
	}
	virtual void Seek(int position)
	{
		stream->Seek(position);
	}
	virtual void Write(char data)
	{
		stream->Write(data);
	}
};

class CryptoSteram :public DecoratorStream
{
public:
	CryptoSteram(Stream* stm):DecoratorStream(stm)
	{

	}
	virtual void Read(int number)
	{
		std::cout << "CryptoSteram���ܲ���" << std::endl;
		stream->Read(number);
	}
	virtual void Seek(int position)
	{
		std::cout << "CryptoSteram���ܲ���" << std::endl;
		stream->Seek(position);
	}
	virtual void Write(char data)
	{
		std::cout << "CryptoSteram���ܲ���" << std::endl;
		stream->Write(data);
	}

};

class BufferedStream :public DecoratorStream
{
public:
	BufferedStream(Stream* stm) :DecoratorStream(stm)
	{

	}
	virtual void Read(int number)
	{
		std::cout << "BufferedStream���ܲ���" << std::endl;
		stream->Read(number);
	}
	virtual void Seek(int position)
	{
		std::cout << "BufferedStream���ܲ���" << std::endl;
		stream->Seek(position);
	}
	virtual void Write(char data)
	{
		std::cout << "BufferedStream���ܲ���" << std::endl;
		stream->Write(data);
	}
};



//int main()
//{
//	FileStream* s1 = new FileStream();
//	NetworkStream* s2 = new NetworkStream();
//	MemoryStream* s3 = new MemoryStream();
//
//	DecoratorStream* cryp = new CryptoSteram(s1);
//	DecoratorStream* buff = new BufferedStream(new CryptoSteram(s2));
//
//	s1->Read(3);
//	s2->Read(4);
//	s3->Read(5);
//	cryp->Read(6);
//	buff->Read(7);
//	
//}