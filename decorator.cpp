//装饰器模式是用来给对象增加某些特性或者对被装饰对象进行某些修改
//典型应用场景：Java的IO流
#include <iostream>

class Stream
{
public:
	virtual void Read(int number) = 0;
	virtual void Seek(int position) = 0;
	virtual void Write(char data) = 0;

	virtual ~Stream() {}
};

//主体类
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

//扩展操作
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
		std::cout << "CryptoSteram加密操作" << std::endl;
		stream->Read(number);
	}
	virtual void Seek(int position)
	{
		std::cout << "CryptoSteram加密操作" << std::endl;
		stream->Seek(position);
	}
	virtual void Write(char data)
	{
		std::cout << "CryptoSteram加密操作" << std::endl;
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
		std::cout << "BufferedStream加密操作" << std::endl;
		stream->Read(number);
	}
	virtual void Seek(int position)
	{
		std::cout << "BufferedStream加密操作" << std::endl;
		stream->Seek(position);
	}
	virtual void Write(char data)
	{
		std::cout << "BufferedStream加密操作" << std::endl;
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