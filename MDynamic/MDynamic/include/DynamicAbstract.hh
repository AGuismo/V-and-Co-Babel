#ifndef DYNAMIC_ABSTRACT
# define	DYNAMIC_ABSTRACT

# include	"MDynamicAbstract.hh"
# include	<string>

#ifdef WIN32

# include	<Windows.h>

typedef void  *(__stdcall *Fptr)();

class DynamicAbstract : public MDynamicAbstract
{
private:
  HMODULE	handle;
public:
  virtual bool DynamicOpen(const std::string &path);
  virtual void *DynamicLoadSym(const std::string &symName);
  virtual bool DynamicClose(void);
  virtual const char	*error() const;

private:
  std::string	_error;
};

#elif	defined (linux)

# include	<dlfcn.h>

typedef void	*(*Fptr)();

class DynamicAbstract : public MDynamicAbstract
{
private:
  void	*handle;
public:
  virtual bool DynamicOpen(const std::string &path);
  virtual void *DynamicLoadSym(const std::string &symName);
  virtual bool DynamicClose(void);
  virtual const char	*error() const;

private:
  std::string	_error;
};
#else
error "Unsupported operating system"
#endif // WIN32
#endif // !DYNAMIC_ABSTRACT
