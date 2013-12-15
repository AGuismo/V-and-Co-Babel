#ifndef PERSOREQUEST_H_
# define PERSOREQUEST_H_

# include	"ARequest.hh"

namespace	request
{

  namespace	perso
  {
    class Perso : public ARequest
    {
    protected:
      Perso(const request::ID id);
      virtual ~Perso();
      Perso(Perso const&);
      Perso& operator=(Perso const&);

    public:
      virtual Protocol		&serialize(Protocol &) const;
      virtual Protocol		&unserialize(Protocol &);
      virtual ARequest		*clone() = 0;
    };

    namespace	client
    {
      struct	ModifyPrivacy : public Perso
      {
	static const char	*PRIVACY_MODE;

	ModifyPrivacy();
	ModifyPrivacy(const request::Privacy privacy);
	~ModifyPrivacy();
	ModifyPrivacy(const ModifyPrivacy &);
	ModifyPrivacy	&operator=(const ModifyPrivacy &);

	ARequest			*clone();
	Protocol			&serialize(Protocol &) const;
	Protocol			&unserialize(Protocol &);

	bool			operator==(const ARequest *req) const;
	bool			operator!=(const ARequest *req) const;

	request::Privacy	_privacy;
      };

      struct	StatusClient : public Perso
      {
	static const char	*STATUS;

	StatusClient();
	StatusClient(const request::Status &status,
		     const request::StatusDetail &statusDetails);
	~StatusClient();
	StatusClient(const StatusClient &);
	StatusClient	&operator=(const StatusClient &);

	ARequest			*clone();
	Protocol			&serialize(Protocol &) const;
	Protocol			&unserialize(Protocol &);

	bool			operator==(const ARequest *req) const;
	bool			operator!=(const ARequest *req) const;

	request::Status		_status;
	request::StatusDetail	_statusDetails;
      };

      struct	MissedCallClient : public Perso
      {
	static const char	*MISSED_CALLS;

	MissedCallClient();
	~MissedCallClient();

	ARequest			*clone();
	Protocol			&serialize(Protocol &) const;
	Protocol			&unserialize(Protocol &);

      };

      struct	GetMissedClient : public Perso
      {
	static const char	*GET_MISSED;

	GetMissedClient();
	GetMissedClient(const request::IdxAnswer &IdxAnswer);
	~GetMissedClient();
	GetMissedClient(const GetMissedClient &);
	GetMissedClient	&operator=(const GetMissedClient &);

	ARequest			*clone();
	Protocol			&serialize(Protocol &) const;
	Protocol			&unserialize(Protocol &);

	bool			operator==(const ARequest *req) const;
	bool			operator!=(const ARequest *req) const;

	request::IdxAnswer	_idxAnswer;
      };

      struct	DelMissedClient : public Perso
      {
	static const char	*DEL_MISSED;

	DelMissedClient();
	DelMissedClient(const request::IdxAnswer &idxAnswer);
	~DelMissedClient();
	DelMissedClient(const DelMissedClient &);
	DelMissedClient	&operator=(const DelMissedClient &);

	ARequest			*clone();
	Protocol			&serialize(Protocol &) const;
	Protocol			&unserialize(Protocol &);

	bool			operator==(const ARequest *req) const;
	bool			operator!=(const ARequest *req) const;

	request::IdxAnswer	_idxAnswer;
      };

      struct	SetAutoAnswerClient : public Perso
      {
	static const char	*SET_AUTO_ANSWER;

	SetAutoAnswerClient();
	SetAutoAnswerClient(const request::Answer &answer);
	~SetAutoAnswerClient();
	SetAutoAnswerClient(const SetAutoAnswerClient &);
	SetAutoAnswerClient	&operator=(const SetAutoAnswerClient &);

	ARequest			*clone();
	Protocol			&serialize(Protocol &) const;
	Protocol			&unserialize(Protocol &);

	bool			operator==(const ARequest *req) const;
	bool			operator!=(const ARequest *req) const;

	request::Answer	_answer;
      };

      struct	UnsetAutoAnswer : public Perso
      {
	static const char	*UNSET_AUTO_ANSWER;

	UnsetAutoAnswer();
	~UnsetAutoAnswer();

	ARequest			*clone();
	Protocol			&serialize(Protocol &) const;
	Protocol			&unserialize(Protocol &);
      };

    } // !client

    namespace	server
    {
      struct	MissedCallServer : public Perso
      {
	static const char	*MISSED_CALLS;

	MissedCallServer();
	MissedCallServer(const int nbMissed);
	~MissedCallServer();
	MissedCallServer(const MissedCallServer &);
	MissedCallServer	&operator=(const MissedCallServer &);

	ARequest			*clone();
	Protocol			&serialize(Protocol &) const;
	Protocol			&unserialize(Protocol &);

	bool			operator==(const ARequest *req) const;
	bool			operator!=(const ARequest *req) const;

	int		_nbMissed;
      };

      struct	GetMissedServer : public Perso
      {
	static const char	*GET_MISSED;

	GetMissedServer();
	GetMissedServer(const request::IdxAnswer &idxAnswer,
			const request::From &from,
			const request::SinceWhen &since);
	~GetMissedServer();
	GetMissedServer(const GetMissedServer &);
	GetMissedServer	&operator=(const GetMissedServer &);

	ARequest			*clone();
	Protocol			&serialize(Protocol &) const;
	Protocol			&unserialize(Protocol &);

	bool			operator==(const ARequest *req) const;
	bool			operator!=(const ARequest *req) const;

	request::IdxAnswer	_idxAnswer;
	request::From		_from;
	request::SinceWhen	_since;
      };

      struct	AutoAnswerServer : public Perso
      {
	static const char	*AUTO_ANSWER;

	AutoAnswerServer();
	AutoAnswerServer(const request::From &from,
			 const request::Answer &answer);
	~AutoAnswerServer();
	AutoAnswerServer(const AutoAnswerServer &);
	AutoAnswerServer	&operator=(const AutoAnswerServer &);

	ARequest			*clone();
	Protocol			&serialize(Protocol &) const;
	Protocol			&unserialize(Protocol &);

	bool			operator==(const ARequest *req) const;
	bool			operator!=(const ARequest *req) const;

	request::From		_from;
	request::Answer		_answer;
      };


    } // !server
  } // !perso


} // !request


#endif /* PERSOREQUEST_H_ */
