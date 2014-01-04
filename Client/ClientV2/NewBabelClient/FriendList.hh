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

typedef	std::map<std::string, Friend>		friend_list_type;


class FriendList
{
public:

private:
	friend_list_type							_friendList;

public:
	Friend										*getFriend(const std::string &friendName);
	const friend_list_type						&getFriendList();

public:
	void										insertFriend(const std::string &friendName, const std::string &friendMsgPerso, Status status);
	bool										removeFriend(std::string &friendName);

public:
	bool										updateFriendStatus(std::string &friendName, Status newStatus);
	bool										updateFriendPersonalMsg(std::string &friendName, std::string &newPersonalMsg);

public:
	bool										insertIncomingMsg(const std::string &friendName,  const std::string &msg);
	bool										insertOutcomingMsg(const std::string &friendName, const std::string &msg);
	bool										saveCurrentTypingMsg(std::string &friendName, std::string &msg);

public:
	convers_type								*getFriendConversation(std::string &friendName);
	msg_type									*getFriendCurrentTypingMsg(std::string &friendName);

public:
	FriendList();
	~FriendList();

private:
	 FriendList(const FriendList &);
	 FriendList									operator=(const FriendList &);
};

#endif // !FRIENDLIST_HH
