#pragma once
# include	<vector>
# include	<map>

class Administrator
{
public:
	typedef std::string						buffer;
	typedef std::vector<buffer>				args;
	typedef void (Administrator::*callback)(const args &, buffer &);
	typedef std::map<std::string, callback> callback_map;

public:
	static const std::string			BAD_REQUEST;
	static const std::string			OK;
	static const std::string			CONTENT;
	static const std::string			NOT_IMPLEMENT;

private:
	void	shutdown(const args &, buffer &response);
	void	dropDB(const args &, buffer &response);
	void	saveDB(const args &, buffer &response);

public:
	Administrator();
	~Administrator();
	void	operator()(const args &, buffer &response);

private:
	callback_map		_calls;
};
