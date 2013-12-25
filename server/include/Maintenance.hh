#ifndef MAINTENANCE_H_
# define MAINTENANCE_H_

# include	<list>
# include	<string>
# include	"MaintenanceConnection.hh"

namespace boost
{
  namespace asio
  {
    class io_service;
  }
}
class	Administrator;

class Maintenance
{
public:
  class Exception
  {
  public:
    Exception(const std::string &) throw();
    virtual ~Exception() throw();

  public:
    Exception(Exception const&) throw();
    Exception& operator=(Exception const&) throw();

  public:
    const char	*what() const throw();

  private:
    std::string	_what;
  };

public:
  Maintenance(boost::asio::io_service &service, Administrator &);
  ~Maintenance();

public:
  void			init();

private:
  void	start_accept();
  void	handle_accept(MaintenanceConnection::Pointer, const boost::system::error_code &error);

private:
  Maintenance(Maintenance const&);
  Maintenance& operator=(Maintenance const&);

private:
  boost::asio::io_service		&_service;
  boost::asio::ip::tcp::acceptor	_acceptor;
  Administrator				&_adm;
};


#endif /* MAINTENANCE_H_ */
