#include	"DynamicAbstract.hh"

#ifdef WIN32

void	handle_error(DWORD error, std::string &errorMsg)
{
	LPVOID lpMsgBuf;
	DWORD bufLen = FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER |
		FORMAT_MESSAGE_FROM_SYSTEM |
		FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL,
		error,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR)&lpMsgBuf,
		0, NULL);
	if (bufLen)
	{
		LPCSTR lpMsgStr = (LPCSTR)lpMsgBuf;
		errorMsg = std::string(lpMsgStr, lpMsgStr + bufLen);

		LocalFree(lpMsgBuf);
		std::cerr << errorMsg << std::endl;
	}
}

bool DynamicAbstract::DynamicOpen(const std::string &path)
{
	SetLastError(0);
	std::cout << std::endl << path.c_str() << std::endl;
	if ((handle = LoadLibrary(path.c_str())) == NULL)
	{
		handle_error(GetLastError(), _error);
		return false;
	}
  return true;
}

void *DynamicAbstract::DynamicLoadSym(const std::string &symName)
{
	SetLastError(0);
	void	*symbol = GetProcAddress(handle, symName.c_str());
	DWORD	error;

	if ((error = GetLastError()))
	{
		handle_error(error, _error);
	}

  return (symbol);
}

bool DynamicAbstract::DynamicClose(void)
{
	SetLastError(0);
	if (FreeLibrary(handle) == 0)
	{
		handle_error(GetLastError(), _error);
		return false;
	}
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
