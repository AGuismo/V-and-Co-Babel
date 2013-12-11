#include	"DynamicAbstract.hh"

#ifdef WIN32

bool DynamicAbstract::DynamicOpen(const std::string &path)
{
  if ((handle = LoadLibrary(path.c_str())) == NULL)
    return false;
  return true;
}

void *DynamicAbstract::DynamicLoadSym(const std::string &symName)
{
  return (GetProcAddress(handle, symName.c_str()));
}

bool DynamicAbstract::DynamicClose(void)
{
  if (FreeLibrary(handle) == 0)
    return false;
  return true;
}

#elif	defined (linux)

bool DynamicAbstract::DynamicOpen(const std::string &path)
{
  const char	*error;

  if ((handle = dlopen(path.c_str(), RTLD_LAZY)) == NULL)
    {

      if ((error = dlerror()) != 0)
	_error = std::string(error);
      return false;
    }
  return true;
}

void *DynamicAbstract::DynamicLoadSym(const std::string &symName)
{
  dlerror();
  void		*sym = dlsym(handle, symName.c_str());
  const char	*error = dlerror();

  if (sym == NULL || error != 0)
    {
      _error = std::string(error);
      return (0);
    }
  return (sym);
}

bool DynamicAbstract::DynamicClose(void)
{
  if (dlclose(handle) != 0)
    {
      const char	*error = dlerror();

      if (error != 0)
	_error = std::string(error);
      return false;
    }
  return true;
}

#else
error "Unsupported operating system"
#endif // WIN32

const char	*DynamicAbstract::error() const
{
  return (_error.c_str());
}
