//通过将多个处理对象组成一条链，每个处理对象都有机会处理请求。
//如果某个对象不能处理请求，则将请求传递给下一个对象依次处理，直到请求被处理为止。

#include <iostream>
#include <string>

enum RequestType
{
	REQ_HANDLER1,
	REQ_HANDLER2,
	REQ_HANDLER3
};

class Request
{
	std::string description;
	RequestType reqType;
public:
	Request(const std::string& desc, RequestType type) : description(desc), reqType(type)
	{
	
	}
	RequestType GetReqType() const
	{
		return reqType;
	}

	const std::string& GetDescription() const
	{
		return description;
	}

};

class ChainHandler
{
	ChainHandler* nextChain;
	void SendRequestToNextHandler(const Request& req)
	{
		if (nextChain)
		{
			nextChain->Handle(req);
		}
	}
protected:
	virtual bool CanHandleRequest(const Request& req) = 0;
	virtual void ProcessRequest(const Request& req) = 0;
public:
	ChainHandler() : nextChain(nullptr)
	{
	
	}

	void SetNextChain(ChainHandler* next)
	{
		nextChain = next;
	}
	void Handle(const Request& req)
	{
		if (CanHandleRequest(req))
		{
			ProcessRequest(req);
		}
		else
		{
			SendRequestToNextHandler(req);
		}
	}
};

class Handler1 : public ChainHandler
{
protected:
	bool CanHandleRequest(const Request& req) override
	{
		return req.GetReqType() == RequestType::REQ_HANDLER1;
	}
	void ProcessRequest(const Request& req) override
	{
		std::cout << "Handler1 is handle request:" << req.GetDescription() << std::endl;
	}
};

class Handler2 : public ChainHandler
{
protected:
	bool CanHandleRequest(const Request& req) override
	{
		return req.GetReqType() == RequestType::REQ_HANDLER2;
	}
	void ProcessRequest(const Request& req) override
	{
		std::cout << "Handler2 is handle request:" << req.GetDescription() << std::endl;
	}
};

class Handler3 : public ChainHandler
{
protected:
	bool CanHandleRequest(const Request& req) override
	{
		return req.GetReqType() == RequestType::REQ_HANDLER3;
	}
	void ProcessRequest(const Request& req) override
	{
		std::cout << "Handler2 is handle request:" << req.GetDescription() << std::endl;
	}
};

//int main()
//{
//	Handler1 h1;
//	Handler2 h2;
//	Handler3 h3;
//	h1.SetNextChain(&h2);
//	h2.SetNextChain(&h3);
//
//	Request req("process task ", RequestType::REQ_HANDLER3);
//	h1.Handle(req);
//}