#include						"FriendList.hh"

Friend							*FriendList::getFriend(std::string &friendName)
{
	friend_list_type::iterator	it = _friendList.find(friendName);

	if (it != _friendList.end())
		return &(it)->second;
	return NULL;
}

void							FriendList::insertFriend(std::string &friendName, std::string &friendPersonalMsg, Status friendStatus)
{
	Friend						newFriend;

	newFriend.name = friendName;
	newFriend.personalMsg = friendPersonalMsg;
	newFriend.status = friendStatus;
	_friendList[friendName] = newFriend;
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

bool							FriendList::insertOutcomingMsg(std::string &friendName, std::string &msg)
{
	Friend						*tmpFriend;
	Message						newMsg;

	if ((tmpFriend = getFriend(friendName)) != NULL)
	{
		newMsg.header = _userName += " [a timestamp to code]: "; // need work here
		newMsg.content = msg;
		tmpFriend->conversation.push_back(newMsg);
		return true;
	}
	return false;
}

bool							FriendList::insertIncomingMsg(std::string &friendName, std::string &header, std::string &msg)
{
	Friend						*tmpFriend;
	Message						newMsg;

	if ((tmpFriend = getFriend(friendName)) != NULL)
	{
		newMsg.header = header; // need work here probably
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

void							FriendList::setUserName(std::string &userName)
{
	_userName = userName;
}

FriendList::FriendList(std::string &userName)
{
	_userName = userName;
}

FriendList::~FriendList()
{
	_friendList.clear();
}
