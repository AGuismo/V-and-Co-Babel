#ifndef FRIENDLIST_HH
# define	FRIENDLIST_HH

# include	<iostream>
# include	<string>
# include	<list>
# include	<map>

enum Status
{
	DISCONNECTED = 0,
	CONNECTED,
	ABSENT,
	OCCUPIED,
	DELETED,
	INVISIBLE
};

struct Message
{
	std::string		header;
	std::string		content;

  Message() {}
  Message(const Message &src): header(src.header), content(src.content) {}
  Message	&operator=(const Message &src)
  {
    if (this != &src)
      {
		header = src.header;
		content = src.content;
      }
    return (*this);
  }
};

typedef	std::list<Message>	convers_type;
typedef	std::string			msg_type;

struct Friend
{
	std::string		name;
	std::string		personalMsg;
	Status			status;
	convers_type	conversation;
	msg_type		currentTypingMsg;
};

class FriendList
{
private:
	std::string									_userName;

private:
	typedef	std::map<std::string, Friend>		friend_list_type;

private:
	friend_list_type							_friendList;

private:
	Friend										*getFriend(std::string &friendName);

public:
	void										insertFriend(std::string &friendName, std::string &friendMsgPerso, Status status);
	bool										removeFriend(std::string &friendName);

public:
	bool										updateFriendStatus(std::string &friendName, Status newStatus);
	bool										updateFriendPersonalMsg(std::string &friendName, std::string &newPersonalMsg);

public:
	bool										insertIncomingMsg(std::string &friendName, std::string &header, std::string &msg);
	bool										insertOutcomingMsg(std::string &friendName, std::string &msg);
	bool										saveCurrentTypingMsg(std::string &friendName, std::string &msg);

public:
	convers_type								*getFriendConversation(std::string &friendName);
	msg_type									*getFriendCurrentTypingMsg(std::string &friendName);

public:
	void										setUserName(std::string &userName);

public:
	FriendList(std::string	&userName);
	~FriendList();

private:
	 FriendList(const FriendList &);
	 FriendList									operator=(const FriendList &);
};

#endif // !FRIENDLIST_HH
