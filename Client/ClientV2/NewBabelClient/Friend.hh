#ifndef FRIEND_H
# define	FRIEND_H

# include	<iostream>
# include	<List>



struct Message
{
	std::string		header;
	std::string		content;
};

class Friend
{
private:
	std::string						_name;
	std::string						_personalMsg;
	Status							_status;

private:
	typedef	std::list<Message>		convers_type;
	typedef	std::string				msg_type;

private:
	convers_type					_clientConversation;
	msg_type						_curentMsg;

public:
	void							setPersonalMessage(std::string &newPm);
	void							setCallStatus(bool newCallStatus);
	void							setStatus(Status newStatus);

public:
	void							insertMsg(std::string &header, std::string &content);
	void							setCurrentMsg(std::string &curMsg);

public:
	convers_type					*getConversation();
	msg_type						*getCurrentMsg();

public:
	Friend(std::string &friendName, std::string &friendMsgPerso, Status friendStatus);
	~Friend();

private:
	Friend(const Friend &);
	Friend					operator=(const Friend &);
};

#endif // !FRIEND_HH
