#pragma	once

# include	<boost/enable_shared_from_this.hpp>
# include	"Protocol.hpp"

class IClient : public boost::enable_shared_from_this<IClient>
{
public:
  typedef boost::shared_ptr<IClient>			Pointer;
  typedef Protocol::serialized_data			buffer;

public:
  virtual				~IClient() {};

public:
  virtual bool				serialize_data(const ARequest &) = 0;
  virtual void				start() = 0;
  virtual void				async_write(const buffer &) = 0;
  virtual void				reset_pong() = 0;
  virtual void				close() = 0;
  virtual void				addRequest(const ARequest &) = 0;

public:
  virtual const request::Username	&Username() const = 0;
  virtual void				Username(const request::Username &) = 0;
  virtual bool				Authenticated() const = 0;
  virtual void				Authenticated(bool) = 0;
  virtual request::Privacy		privacy() const = 0;
  virtual void				privacy(request::Privacy) = 0;
  virtual request::Status		status() const = 0;
  virtual void				status(request::Status) = 0;
  virtual request::StatusDetail		statusDetail() const = 0;
  virtual void				statusDetail(request::StatusDetail &) = 0;
  virtual request::IP			IP() const = 0;
  virtual const request::Stream		&AutoAnswer() const = 0;
  virtual void				updateAutoAnswer(const request::Stream &) = 0;
  virtual void				cleanAutoAnswer() = 0;
  virtual Serializer			&serializeAnswer() = 0;
  virtual request::PingPongID		pong() const = 0;
  virtual void				pong(request::PingPongID) = 0;
};
