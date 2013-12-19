#ifndef IMUTEX_HH
#define IMUTEX_HH

template <typename Lock>
class MutexGuard
{
public:
  MutexGuard(Lock &lock) :
    _lock(lock)
  {
    _lock.lock();
  }

  ~MutexGuard()
  {
    _lock.unlock();
  }
private:
  Lock  _lock;
};

#endif // IMUTEX_HH
