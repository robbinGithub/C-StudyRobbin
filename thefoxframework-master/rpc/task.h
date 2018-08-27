#ifndef _THEFOX_NET_RPC_TASK_H_
#define _THEFOX_NET_RPC_TASK_H_

#include <base/timestamp.h>
#include <net/callbacks.h>
#include <rpc/common.h>
#include <rpc/rpc.pb.h>

namespace thefox
{

/// @brief ��ʾһ����Ϣ
class Task
{
public:
	explicit Task(TcpConnection *sender, 
					const Timestamp &receiveTime, 
					const BoxPtr &msg)
		: _sender(sender) 
		, _time(receiveTime) 
		, _box(msg) 
	{}

	const Timestamp &time() const { return _time; }
	TcpConnection *sender() { return _sender; }
	bool hasCall() const { return _box->has_call(); }
	bool hasReply() const { return _box->has_reply(); }
	bool hasOneway() const { return _box->has_oneway(); }
	const rpc::Call &call() const { return _box->call(); }
	const rpc::Reply &reply() const { return _box->reply(); }
	const rpc::OnewayMessage &oneway() const { return _box->oneway(); }

	const gpb::Descriptor *onewayDescriptor() const 
	{ 
		if (hasOneway())
			return gpb::DescriptorPool::generated_pool()->FindMessageTypeByName(_box->oneway().type());
	}

private:
	THEFOX_DISALLOW_EVIL_CONSTRUCTORS(Task);
	const Timestamp _time;
	TcpConnection *_sender;
	const BoxPtr _box;
};

typedef std::shared_ptr<Task> TaskPtr;

} // namespace thefox

#endif // _THEFOX_NET_RPC_TASK_H_
