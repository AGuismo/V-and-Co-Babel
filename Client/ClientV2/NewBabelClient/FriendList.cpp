#include						"FriendList.hh"
#include						"Env.hh"
#include						<QTime>

Friend							*FriendList::getFriend(const std::string &friendName)
{
	friend_list_type::iterator	it = _friendList.find(friendName);

	if (it != _friendList.end())
		return &(it)->second;
	return NULL;
}

void							FriendList::insertFriend(const std::string &friendName, const std::string &friendPersonalMsg, Status friendStatus)
{
	Friend						newFriend;
	friend_list_type::iterator	it = _friendList.find(friendName);

	if (it != _friendList.end())
	{
		it->second.personalMsg = friendPersonalMsg;
		it->second.status = friendStatus;
		return;
	}
	newFriend.name = friendName;
	newFriend.personalMsg = friendPersonalMsg;
	newFriend.status = friendStatus;
	_friendList.insert( std::pair<std::string, Friend>(friendName, newFriend));
}

bool							FriendList::removeFriend(std::string &friendName)
{
	friend_list_type::iterator	it = _friendList.find(friendName);

	if (it != _friendList.end())
	{
		_friendList.erase(it);
		return true;
	}
	return false;
}

bool							FriendList::updateFriendStatus(std::string &friendName, Status newStatus)
{
	Friend						*tmpFriend;

	if ((tmpFriend = getFriend(friendName)) != NULL)
	{
		tmpFriend->status = newStatus;
		return true;
	}
	return false;
}

bool							FriendList::updateFriendPersonalMsg(std::string &friendName, std::string &newPersonalMsg)
{
	Friend						*tmpFriend;

	if ((tmpFriend = getFriend(friendName)) != NULL)
	{
		tmpFriend->personalMsg = newPersonalMsg;
		return true;
	}
	return false;
}

bool							FriendList::insertOutcomingMsg(const std::string &friendName, const std::string &msg)
{
	Friend						*tmpFriend;
	Message						newMsg;
	QTime						timeMsg;

	if ((tmpFriend = getFriend(friendName)) != NULL)
	{
		newMsg.header += "[";
		newMsg.header +=  timeMsg.currentTime().toString().toStdString();
		newMsg.header += "]:[";
		newMsg.header += Env::getInstance().userInfo.login;
		newMsg.header += "]:";
		newMsg.header += msg;
		newMsg.content = msg;
		tmpFriend->conversation.push_back(newMsg);
		return true;
	}
	return false;
}

bool							FriendList::insertIncomingMsg(const std::string &friendName, const std::string &msg)
{
	Friend						*tmpFriend;
	Message						newMsg;
	QTime						timeMsg;

	if ((tmpFriend = getFriend(friendName)) != NULL)
	{
		newMsg.header += "[";
		newMsg.header += timeMsg.currentTime().toString().toStdString();
		newMsg.header += "]:[";
		newMsg.header += friendName;
		newMsg.header += "]:";
		newMsg.header += msg;
		newMsg.content = msg;
		tmpFriend->conversation.push_back(newMsg);
		return true;
	}
	return false;
}

convers_type					*FriendList::getFriendConversation(std::string &friendName)
{
	Friend						*tmpFriend;

	if ((tmpFriend = getFriend(friendName)) != NULL)
		return &(tmpFriend)->conversation;
	return NULL;
}

msg_type						*FriendList::getFriendCurrentTypingMsg(std::string &friendName)
{
	Friend						*tmpFriend;

	if ((tmpFriend = getFriend(friendName)) != NULL)
		return &(tmpFriend)->currentTypingMsg;
	return NULL;
}

const friend_list_type						&FriendList::getFriendList()
{
	return _friendList;
}

FriendList::FriendList()
{
}

FriendList::~FriendList()
{
	_friendList.clear();
}
