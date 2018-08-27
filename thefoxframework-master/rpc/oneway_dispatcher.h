#ifndef _THEFOX_NET_RPC_ONEWAYDISPATCHER_H_
#define _THEFOX_NET_RPC_ONEWAYDISPATCHER_H_

#include <map>
#include <base/common.h>
#include <rpc/common.h>
#include <rpc/task.h>
#include <rpc/rpc_codec.h>
#include <rpc/rpc.pb.h>

namespace thefox
{

class OnewayDispatcher
{
public:
	explicit OnewayDispatcher(const OnewayCallback &defaultCb)
		: _defaultCallback(defaultCb) {}
	~OnewayDispatcher(void) {}

	void onMessage(TcpConnection *sender, const rpc::OnewayMessage &oneway, Timestamp recvTime) const
	{
		std::shared_ptr<gpb::Message> message(RpcCodec::createMessage(oneway.type()));
		if (NULL == message) // oneway��Ϣ����ʧ��
			return;

		message->ParseFromString(oneway.body());

		const gpb::Descriptor* descriptor = 
			gpb::DescriptorPool::generated_pool()->FindMessageTypeByName(oneway.type());
		
		if (descriptor) {
			CallbackMap::const_iterator it = _callbacks.find(descriptor);
			if (it != _callbacks.end())
				it->second(sender, oneway.type(), message.get(), recvTime);
			else
				_defaultCallback(sender, oneway.type(), message.get(), recvTime);
		}
	}

	void setDefaultCallback(const OnewayCallback &cb)
	{ _defaultCallback = cb; }

	void registerCallback(const gpb::Descriptor *desc, const OnewayCallback &cb)
	{ _callbacks[desc] = cb; }

private:
	typedef std::map<const gpb::Descriptor *, OnewayCallback> CallbackMap;
	CallbackMap _callbacks;
	OnewayCallback _defaultCallback;
};

} // namespace thefox

#endif // _THEFOX_NET_RPC_ONEWAYDISPATCHER_H_