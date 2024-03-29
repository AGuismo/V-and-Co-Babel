#include	"Protocol.hpp"
#include	"PersoRequest.hh"

namespace	request
{

  namespace	perso
  {

    Perso::Perso(const request::ID id):
      ARequest(id)
    {

    }

    Perso::~Perso()
    {

    }

    Perso::Perso(Perso const&src):
      ARequest(src)
    {

    }

    Perso&	Perso::operator=(Perso const&src)
    {
      if (&src != this)
	{
	  _code = src._code;
	}
      return (*this);
    }

    Protocol	&Perso::serialize(Protocol &rhs) const
    {
      rhs << _code;
      return (rhs);
    }

    Protocol	&Perso::unserialize(Protocol &rhs)
    {
      return (rhs);
    }

    namespace	client
    {
      const char *ModifyPrivacy::PRIVACY_MODE = "Private mode client request";
      const char *StatusClient::STATUS = "Status client request";
      const char *MissedCallClient::MISSED_CALLS = "Missed Call client request";
      const char *GetMissedClient::GET_MISSED = "Get Missed client request";
      const char *DelMissedClient::DEL_MISSED = "Del Missed client request";
      const char *SetAutoAnswerClient::SET_AUTO_ANSWER = "Set AutoAnswer Client request";
      const char *UnsetAutoAnswer::UNSET_AUTO_ANSWER="Unset AutoAnswer Client request";
      const char *LetMessage::LET_MESSAGE="Let a message to another client";

      ModifyPrivacy::ModifyPrivacy():
	Perso(request::client::perso::PRIVACY_MODE)
      {
      }

      ModifyPrivacy::ModifyPrivacy(const request::Privacy privacy):
	Perso(request::client::perso::PRIVACY_MODE), _privacy(privacy)
      {
      }
      ModifyPrivacy::~ModifyPrivacy()
      {
      }

      ModifyPrivacy::ModifyPrivacy(const ModifyPrivacy &src) :
	Perso(request::client::perso::PRIVACY_MODE), _privacy(src._privacy)
      {
      }

      ModifyPrivacy	&ModifyPrivacy::operator=(const ModifyPrivacy &src)
      {
	if (this != &src)
	  {
	    _privacy = src._privacy;
	  }
	return (*this);
      }

      ARequest	*ModifyPrivacy::clone() const
      {
	return (new ModifyPrivacy(*this));
      }

      bool	ModifyPrivacy::operator==(const ARequest *req) const
      {
	if (ARequest::operator!=(req))
	  return (false);

	const ModifyPrivacy	*tmp = dynamic_cast<const ModifyPrivacy *>(req);
	return (tmp->_privacy == _privacy);
      }

      bool	ModifyPrivacy::operator!=(const ARequest *req) const
      {
	return (!operator==(req));
      }

      Protocol		&ModifyPrivacy::serialize(Protocol &rhs) const
      {
	Perso::serialize(rhs);

	rhs << _privacy;

	return (rhs);
      }

      Protocol	&ModifyPrivacy::unserialize(Protocol &rhs)
      {
	Perso::unserialize(rhs);

	rhs >> _privacy;
	return (rhs);
      }

      StatusClient::StatusClient():
	Perso(request::client::perso::STATUS)
      {
      }

      StatusClient::StatusClient(const request::Status &status,
				 const request::StatusDetail &statusDetails):
	Perso(request::client::perso::STATUS), _status(status), _statusDetails(statusDetails)
      {
      }

      StatusClient::~StatusClient()
      {
      }

      StatusClient::StatusClient(const StatusClient &src) :
	Perso(request::client::perso::STATUS), _status(src._status), _statusDetails(src._statusDetails)
      {
      }

      StatusClient	&StatusClient::operator=(const StatusClient &src)
      {
	if (this != &src)
	  {
	    _status = src._status;
	    _statusDetails = src._statusDetails;
	  }
	return (*this);
      }

      ARequest	*StatusClient::clone() const
      {
	return (new StatusClient(*this));
      }

      bool	StatusClient::operator==(const ARequest *req) const
      {
	if (ARequest::operator!=(req))
	  return (false);

	const StatusClient	*tmp = dynamic_cast<const StatusClient *>(req);
	return (tmp->_status == _status && tmp->_statusDetails == _statusDetails);
      }

      bool	StatusClient::operator!=(const ARequest *req) const
      {
	return (!operator==(req));
      }

      Protocol		&StatusClient::serialize(Protocol &rhs) const
      {
	StatusDetailLen	DetailsLen;

	Perso::serialize(rhs);

	rhs << _status;

	DetailsLen = _statusDetails.size();
	rhs << DetailsLen;

	rhs.push(_statusDetails, DetailsLen);

	return (rhs);
      }

      Protocol	&StatusClient::unserialize(Protocol &rhs)
      {
	StatusDetailLen	DetailsLen;

	Perso::unserialize(rhs);

	rhs >> _status;

	rhs >> DetailsLen;

	rhs.pop(_statusDetails, DetailsLen);

	return (rhs);
      }

      MissedCallClient::MissedCallClient():
	Perso(request::client::perso::MISSED_CALLS)
      {
      }

      MissedCallClient::~MissedCallClient()
      {
      }

      ARequest	*MissedCallClient::clone() const
      {
	return (new MissedCallClient(*this));
      }

      Protocol		&MissedCallClient::serialize(Protocol &rhs) const
      {
	Perso::serialize(rhs);
	return (rhs);
      }

      Protocol	&MissedCallClient::unserialize(Protocol &rhs)
      {
	Perso::unserialize(rhs);
	return (rhs);
      }

      GetMissedClient::GetMissedClient():
	Perso(request::client::perso::GET_MISSED)
      {
      }

      GetMissedClient::GetMissedClient(const request::IdxAnswer &idxAnswer):
	Perso(request::client::perso::GET_MISSED), _idxAnswer(idxAnswer)
      {
      }

      GetMissedClient::~GetMissedClient()
      {
      }

      GetMissedClient::GetMissedClient(const GetMissedClient &src) :
	Perso(request::client::perso::GET_MISSED), _idxAnswer(src._idxAnswer)
      {
      }

      GetMissedClient	&GetMissedClient::operator=(const GetMissedClient &src)
      {
	if (this != &src)
	  {
	    _idxAnswer = src._idxAnswer;
	  }
	return (*this);
      }

      ARequest	*GetMissedClient::clone() const
      {
	return (new GetMissedClient(*this));
      }

      bool	GetMissedClient::operator==(const ARequest *req) const
      {
	if (ARequest::operator!=(req))
	  return (false);

	const GetMissedClient	*tmp = dynamic_cast<const GetMissedClient *>(req);
	return (tmp->_idxAnswer== _idxAnswer);
      }

      bool	GetMissedClient::operator!=(const ARequest *req) const
      {
	return (!operator==(req));
      }

      Protocol		&GetMissedClient::serialize(Protocol &rhs) const
      {
	Perso::serialize(rhs);

	rhs << _idxAnswer;

	return (rhs);
      }

      Protocol	&GetMissedClient::unserialize(Protocol &rhs)
      {
	Perso::unserialize(rhs);

	rhs >> _idxAnswer;

	return (rhs);
      }

      DelMissedClient::DelMissedClient():
	Perso(request::client::perso::DEL_MISSED)
      {
      }

      DelMissedClient::DelMissedClient(const request::IdxAnswer &idxAnswer):
	Perso(request::client::perso::DEL_MISSED), _idxAnswer(idxAnswer)
      {
      }

      DelMissedClient::~DelMissedClient()
      {
      }

      DelMissedClient::DelMissedClient(const DelMissedClient &src) :
	Perso(request::client::perso::DEL_MISSED), _idxAnswer(src._idxAnswer)
      {
      }

      DelMissedClient	&DelMissedClient::operator=(const DelMissedClient &src)
      {
	if (this != &src)
	  {
	    _idxAnswer = src._idxAnswer;
	  }
	return (*this);
      }

      ARequest	*DelMissedClient::clone() const
      {
	return (new DelMissedClient(*this));
      }

      bool	DelMissedClient::operator==(const ARequest *req) const
      {
	if (ARequest::operator!=(req))
	  return (false);

	const DelMissedClient	*tmp = dynamic_cast<const DelMissedClient *>(req);
	return (tmp->_idxAnswer== _idxAnswer);
      }

      bool	DelMissedClient::operator!=(const ARequest *req) const
      {
	return (!operator==(req));
      }

      Protocol		&DelMissedClient::serialize(Protocol &rhs) const
      {
	Perso::serialize(rhs);

	rhs << _idxAnswer;

	return (rhs);
      }

      Protocol	&DelMissedClient::unserialize(Protocol &rhs)
      {
	Perso::unserialize(rhs);

	rhs >> _idxAnswer;

	return (rhs);
      }

      SetAutoAnswerClient::SetAutoAnswerClient():
	Perso(request::client::perso::SET_AUTO_ANSWER)
      {
      }

      SetAutoAnswerClient::SetAutoAnswerClient(const request::Answer &answer):
	Perso(request::client::perso::SET_AUTO_ANSWER), _answer(answer)
      {
      }

      SetAutoAnswerClient::~SetAutoAnswerClient()
      {
      }

      SetAutoAnswerClient::SetAutoAnswerClient(const SetAutoAnswerClient &src) :
	Perso(request::client::perso::SET_AUTO_ANSWER), _answer(src._answer)
      {
      }

      SetAutoAnswerClient	&SetAutoAnswerClient::operator=(const SetAutoAnswerClient &src)
      {
	if (this != &src)
	  {
	    _answer = src._answer;
	  }
	return (*this);
      }

      ARequest	*SetAutoAnswerClient::clone() const
      {
	return (new SetAutoAnswerClient(*this));
      }

      bool	SetAutoAnswerClient::operator==(const ARequest *req) const
      {
	if (ARequest::operator!=(req))
	  return (false);

	const SetAutoAnswerClient	*tmp = dynamic_cast<const SetAutoAnswerClient *>(req);
	return (tmp->_answer== _answer);
      }

      bool	SetAutoAnswerClient::operator!=(const ARequest *req) const
      {
	return (!operator==(req));
      }

      Protocol		&SetAutoAnswerClient::serialize(Protocol &rhs) const
      {
	AnswerLen	len;
	Perso::serialize(rhs);

	len = _answer.size();
	rhs << len;

	rhs.push(_answer, len);

	return (rhs);
      }

      Protocol	&SetAutoAnswerClient::unserialize(Protocol &rhs)
      {
	AnswerLen	len;

	Perso::unserialize(rhs);

	rhs >> len;

	rhs.pop(_answer, len);

	return (rhs);
      }

      Pong::Pong():
	Perso(request::client::perso::PONG)
      {
      }

      Pong::Pong(const request::ID &id):
	Perso(request::client::perso::PONG), _id(id)
      {
      }

      Pong::~Pong()
      {
      }

      Pong::Pong(const Pong &src) :
	Perso(request::client::perso::PONG), _id(src._id)
      {
      }

      Pong	&Pong::operator=(const Pong &src)
      {
	if (this != &src)
	  {
	    _id = src._id;
	  }
	return (*this);
      }

      ARequest	*Pong::clone() const
      {
	return (new Pong(*this));
      }

      bool	Pong::operator==(const ARequest *req) const
      {
	if (ARequest::operator!=(req))
	  return (false);

	const Pong	*tmp = dynamic_cast<const Pong *>(req);
	return (tmp->_id == _id);
      }

      bool	Pong::operator!=(const ARequest *req) const
      {
	return (!operator==(req));
      }

      Protocol		&Pong::serialize(Protocol &rhs) const
      {
	Perso::serialize(rhs);

	rhs << _id;

	return (rhs);
      }

      Protocol	&Pong::unserialize(Protocol &rhs)
      {
	Perso::unserialize(rhs);

	rhs >> _id;

	return (rhs);
      }

      UnsetAutoAnswer::UnsetAutoAnswer():
	Perso(request::client::perso::UNSET_AUTO_ANSWER)
      {
      }

      UnsetAutoAnswer::~UnsetAutoAnswer()
      {
      }

      ARequest	*UnsetAutoAnswer::clone() const
      {
	return (new UnsetAutoAnswer(*this));
      }

      Protocol		&UnsetAutoAnswer::serialize(Protocol &rhs) const
      {
	Perso::serialize(rhs);
	return (rhs);
      }

      Protocol	&UnsetAutoAnswer::unserialize(Protocol &rhs)
      {
	Perso::unserialize(rhs);
	return (rhs);
      }

      LetMessage::LetMessage():
	Perso(request::client::perso::LET_MESSAGE)
      {
      }

      LetMessage::LetMessage(const request::Username &from,
			     const request::Username &to,
			     const request::Time &time,
			     const request::Stream &stream):
	Perso(request::client::perso::LET_MESSAGE), _from(from), _to(to), _time(time), _stream(stream)
      {
      }

      LetMessage::~LetMessage()
      {
      }

      LetMessage::LetMessage(const LetMessage &src) :
	Perso(request::client::perso::LET_MESSAGE), _from(src._from), _to(src._to), _time(src._time), _stream(src._stream)
      {
      }

      LetMessage	&LetMessage::operator=(const LetMessage &src)
      {
	if (this != &src)
	  {
	    _from = src._from;
	    _to = src._to;
	    _time = src._time;
	    _stream = src._stream;
	  }
	return (*this);
      }

      ARequest	*LetMessage::clone() const
      {
	return (new LetMessage(*this));
      }

      bool	LetMessage::operator==(const ARequest *req) const
      {
	if (ARequest::operator!=(req))
	  return (false);

	const LetMessage	*tmp = dynamic_cast<const LetMessage *>(req);
	return (tmp->_from == _from && tmp->_to == _to && tmp->_time == _time && tmp->_stream == _stream);
      }

      bool	LetMessage::operator!=(const ARequest *req) const
      {
	return (!operator==(req));
      }

      Protocol		&LetMessage::serialize(Protocol &rhs) const
      {
	Perso::serialize(rhs);
	request::UsernameLen		toLen;
	request::StreamLen		streamLen;
	request::UsernameLen		fromLen;

	fromLen = _from.size();
	rhs << fromLen;
	rhs.push(_from, fromLen);

	toLen = _to.size();
	rhs << toLen;
	rhs.push(_to, toLen);

	streamLen = _stream.size();
	rhs << streamLen;
	rhs.push(_stream, streamLen);

	return (rhs);
      }

      Protocol	&LetMessage::unserialize(Protocol &rhs)
      {
	Perso::unserialize(rhs);
	request::UsernameLen	toLen;
	request::UsernameLen	fromLen;
	request::StreamLen	streamLen;

	rhs >> fromLen;
	rhs.pop(_from, fromLen);

	rhs >> toLen;
	rhs.pop(_to, toLen);

	rhs >> streamLen;
	rhs.pop(_stream, streamLen);

	return (rhs);
      }

    } // !client

    namespace server
    {
      const char *MissedCallServer::MISSED_CALLS = "Missed Call request Server";
      const char *GetMissedServer::GET_MISSED = "Get Missed request Server";
      const char *AutoAnswerServer::AUTO_ANSWER = "Auto Answer request Server";

      MissedCallServer::MissedCallServer():
	Perso(request::server::perso::MISSED_CALLS)
      {
      }

      MissedCallServer::MissedCallServer(int nbMissed):
	Perso(request::server::perso::MISSED_CALLS), _nbMissed(nbMissed)
      {
      }

      MissedCallServer::~MissedCallServer()
      {
      }

      MissedCallServer::MissedCallServer(const MissedCallServer &src) :
	Perso(request::server::perso::MISSED_CALLS), _nbMissed(src._nbMissed)
      {
      }

      MissedCallServer	&MissedCallServer::operator=(const MissedCallServer &src)
      {
	if (this != &src)
	  {
	    _nbMissed = src._nbMissed;
	  }
	return (*this);
      }

      ARequest	*MissedCallServer::clone() const
      {
	return (new MissedCallServer(*this));
      }

      bool	MissedCallServer::operator==(const ARequest *req) const
      {
	if (ARequest::operator!=(req))
	  return (false);

	const MissedCallServer	*tmp = dynamic_cast<const MissedCallServer *>(req);
	return (tmp->_nbMissed == _nbMissed);
      }

      bool	MissedCallServer::operator!=(const ARequest *req) const
      {
	return (!operator==(req));
      }

      Protocol		&MissedCallServer::serialize(Protocol &rhs) const
      {
	Perso::serialize(rhs);

	rhs << _nbMissed;

	return (rhs);
      }

      Protocol	&MissedCallServer::unserialize(Protocol &rhs)
      {
	Perso::unserialize(rhs);

	rhs >> _nbMissed;

	return (rhs);
      }

      GetMissedServer::GetMissedServer():
	Perso(request::server::perso::GET_MISSED)
      {
      }

      GetMissedServer::GetMissedServer(const request::IdxAnswer &idxAnswer,
				       const request::FromLen &fromLen,
				       const request::From &from,
				       const request::SinceWhen &since):
	Perso(request::server::perso::GET_MISSED), _idxAnswer(idxAnswer), _fromLen(fromLen), _from(from), _since(since)
      {
      }

      GetMissedServer::~GetMissedServer()
      {
      }

      GetMissedServer::GetMissedServer(const GetMissedServer &src) :
	Perso(request::server::perso::GET_MISSED), _idxAnswer(src._idxAnswer), _fromLen(src._fromLen), _from(src._from), _since(src._since)
      {
      }

      GetMissedServer	&GetMissedServer::operator=(const GetMissedServer &src)
      {
	if (this != &src)
	  {
	    _idxAnswer = src._idxAnswer;
	    _fromLen = src._fromLen;
	    _from = src._from;
	    _since = src._since;
	  }
	return (*this);
      }

      ARequest	*GetMissedServer::clone() const
      {
	return (new GetMissedServer(*this));
      }

      bool	GetMissedServer::operator==(const ARequest *req) const
      {
	if (ARequest::operator!=(req))
	  return (false);

	const GetMissedServer	*tmp = dynamic_cast<const GetMissedServer *>(req);
	return (tmp->_idxAnswer == _idxAnswer && tmp->_fromLen == _fromLen && tmp->_from == _from && tmp->_since == _since);
      }

      bool	GetMissedServer::operator!=(const ARequest *req) const
      {
	return (!operator==(req));
      }

      Protocol		&GetMissedServer::serialize(Protocol &rhs) const
      {
	Perso::serialize(rhs);
	request::FromLen	fromLen;

	rhs << _idxAnswer;

	fromLen = _from.size();
	rhs << fromLen;

	rhs.push(_from, fromLen);

	rhs << _since;

	return (rhs);
      }

      Protocol	&GetMissedServer::unserialize(Protocol &rhs)
      {
	Perso::unserialize(rhs);
	request::FromLen	fromLen;

	rhs >> _idxAnswer;

	rhs >> fromLen;

	rhs.pop(_from, fromLen);

	rhs >> _since;

	return (rhs);
      }

      Ping::Ping():
	Perso(request::server::perso::PING)
      {
      }

      Ping::Ping(const request::ID &id):
	Perso(request::server::perso::PING), _id(id)
      {
      }

      Ping::~Ping()
      {
      }

      Ping::Ping(const Ping &src) :
	Perso(request::server::perso::PING), _id(src._id)
      {
      }

      Ping	&Ping::operator=(const Ping &src)
      {
	if (this != &src)
	  {
	    _id = src._id;
	  }
	return (*this);
      }

      ARequest	*Ping::clone() const
      {
	return (new Ping(*this));
      }

      bool	Ping::operator==(const ARequest *req) const
      {
	if (ARequest::operator!=(req))
	  return (false);

	const Ping	*tmp = dynamic_cast<const Ping *>(req);
	return (tmp->_id == _id);
      }

      bool	Ping::operator!=(const ARequest *req) const
      {
	return (!operator==(req));
      }

      Protocol		&Ping::serialize(Protocol &rhs) const
      {
	Perso::serialize(rhs);

	rhs << _id;

	return (rhs);
      }

      Protocol	&Ping::unserialize(Protocol &rhs)
      {
	Perso::unserialize(rhs);

	rhs >> _id;

	return (rhs);
      }

      StreamData::StreamData():
	Perso(request::server::perso::STREAM_DATA)
      {
      }

      StreamData::StreamData(const request::IdxAnswer &answer,
			     const request::StreamLen &streamLen,
			     const request::Stream    &stream):
	Perso(request::server::perso::STREAM_DATA), _answer(answer), _streamLen(streamLen), _stream(stream)
      {
      }

      StreamData::~StreamData()
      {
      }

      StreamData::StreamData(const StreamData &src) :
	Perso(request::server::perso::STREAM_DATA), _answer(src._answer), _streamLen(src._streamLen), _stream(src._stream)
      {
      }

      StreamData	&StreamData::operator=(const StreamData &src)
      {
	if (this != &src)
	  {
	    _answer = src._answer;
	    _streamLen = src._streamLen;
	    _stream = src._stream;
	  }
	return (*this);
      }

      ARequest	*StreamData::clone() const
      {
	return (new StreamData(*this));
      }

      bool	StreamData::operator==(const ARequest *req) const
      {
	if (ARequest::operator!=(req))
	  return (false);

	const StreamData	*tmp = dynamic_cast<const StreamData *>(req);
	return (tmp->_answer == _answer && tmp->_streamLen == _streamLen && tmp->_stream == _stream);
      }

      bool	StreamData::operator!=(const ARequest *req) const
      {
	return (!operator==(req));
      }

      Protocol		&StreamData::serialize(Protocol &rhs) const
      {
	Perso::serialize(rhs);
	request::StreamLen	streamLen;
	request::Stream		stream;

	rhs << _answer;

	streamLen = _stream.size();
	rhs << streamLen;
	rhs.push(_stream, streamLen);

	return (rhs);
      }

      Protocol	&StreamData::unserialize(Protocol &rhs)
      {
	Perso::unserialize(rhs);
	request::StreamLen	streamLen;
	request::Stream		stream;

	rhs >> _answer;

	rhs >> streamLen;
	rhs.pop(_stream, streamLen);

	return (rhs);
      }

      AutoAnswerServer::AutoAnswerServer():
	Perso(request::server::perso::AUTO_ANSWER)
      {
      }

      AutoAnswerServer::AutoAnswerServer(const request::From &from,
					 const request::Answer &answer):
	Perso(request::server::perso::AUTO_ANSWER), _from(from), _answer(answer)
      {
      }

      AutoAnswerServer::~AutoAnswerServer()
      {
      }

      AutoAnswerServer::AutoAnswerServer(const AutoAnswerServer &src) :
	Perso(request::server::perso::AUTO_ANSWER), _from(src._from), _answer(src._answer)
      {
      }

      AutoAnswerServer	&AutoAnswerServer::operator=(const AutoAnswerServer &src)
      {
	if (this != &src)
	  {
	    _from = src._from;
	    _answer = src._answer;
	  }
	return (*this);
      }

      ARequest	*AutoAnswerServer::clone() const
      {
	return (new AutoAnswerServer(*this));
      }

      bool	AutoAnswerServer::operator==(const ARequest *req) const
      {
	if (ARequest::operator!=(req))
	  return (false);

	const AutoAnswerServer	*tmp = dynamic_cast<const AutoAnswerServer *>(req);
	return (tmp->_from == _from && tmp->_answer == _answer);
      }

      bool	AutoAnswerServer::operator!=(const ARequest *req) const
      {
	return (!operator==(req));
      }

      Protocol		&AutoAnswerServer::serialize(Protocol &rhs) const
      {
	Perso::serialize(rhs);
	request::FromLen	fromLen;
	request::AnswerLen	answerLen;

	fromLen = _from.size();
	rhs << fromLen;
	rhs.push(_from, fromLen);

	answerLen = _answer.size();
	rhs << answerLen;
	rhs.push(_answer, answerLen);

	return (rhs);
      }

      Protocol	&AutoAnswerServer::unserialize(Protocol &rhs)
      {
	Perso::unserialize(rhs);
	request::FromLen	fromLen;
	request::AnswerLen	answerLen;

	rhs >> fromLen;
	rhs.pop(_from, fromLen);

	rhs >> answerLen;
	rhs.pop(_answer, answerLen);

	return (rhs);
      }

    } // !server

  } // !perso

} // !request
