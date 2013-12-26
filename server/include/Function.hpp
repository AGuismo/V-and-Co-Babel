#ifndef FUNCTION_H_
# define FUNCTION_H_

template <typename T>
struct Function
{
};

template <typename T>
struct	Function<T ()>
{
  typedef T (*func)();
  typedef T	result_type;

  struct	ICallable
  {
    virtual ~ICallable() {};
    virtual T		operator()() = 0;
    virtual ICallable	*clone() = 0;
  };

  template <typename Func>
  struct	InternFunc : public ICallable
  {
    InternFunc(Func f) :
      _f(f)
    {

    }

    InternFunc(const InternFunc &src) :
      _f(src._f)
    {

    }

    InternFunc	&operator=(const InternFunc &src)
    {
      if (&src != this)
	{
	  _f = src._f;
	}
      return (*this);
    }

    virtual ~InternFunc() {};
    virtual T		operator()()
    {
      return (_f());
    }
    virtual ICallable	*clone()
    {
      return (new InternFunc<Func>(_f));
    }

    Func	_f;
  };

  template <typename Func, typename Object>
  struct	InternMethodFunc : public ICallable
  {
    InternMethodFunc(T (Object::*f)(), Object *obj) :
      _f(f), _obj(obj)
    {

    }

    InternMethodFunc(const InternMethodFunc &src) :
      _f(src._f), _obj(src._obj)
    {

    }

    InternMethodFunc	&operator=(const InternMethodFunc &src)
    {
      if (&src != this)
	{
	  _f = src._f;
	  _obj = src._obj;
	}
      return (*this);
    }

    virtual ~InternMethodFunc() {};
    virtual T		operator()()
    {
      return ((_obj->*_f)());
    }
    virtual ICallable	*clone()
    {
      return (new InternMethodFunc<Func, Object>(_f, _obj));
    }

    T		(Object::*_f)();
    Object	*_obj;
  };

  Function():
    _call(0)
  {
  }

  template <typename Any>
  Function(Any f):
    _call(0)
  {
    _call = new InternFunc<Any>(f);
  }

  template <typename Any, typename Object>
  Function(Any f, Object *obj):
    _call(0)
  {
    _call = new InternMethodFunc<Any, Object>(f, obj);
  }

  ~Function()
  {
    delete _call;
  }

  Function(const Function<T ()> &src):
    _call(src._call == 0 ? 0 : src._call->clone())
  {
  }

  Function<T ()>	&operator=(const Function<T ()> &src)
  {
    if (&src != this)
      {
  	this->_call = src._call->clone();
      }
    return (*this);
  }

  T		operator()()
  {
    return ((*this->_call)());
  }

  ICallable	*_call;
};

template <>
struct	Function<void ()>
{
  typedef void (*func)();
  typedef void	result_type;

  struct	ICallable
  {
    virtual ~ICallable() {};
    virtual void		operator()() = 0;
    virtual ICallable	*clone() = 0;
  };

  template <typename Func>
  struct	InternFunc : public ICallable
  {
    InternFunc(Func f) :
      _f(f)
    {

    }

    InternFunc(const InternFunc &src) :
      _f(src._f)
    {

    }

    InternFunc	&operator=(const InternFunc &src)
    {
      if (&src != this)
	{
	  _f = src._f;
	}
      return (*this);
    }

    virtual ~InternFunc() {};
    virtual void		operator()()
    {
      _f();
    }
    virtual ICallable	*clone()
    {
      return (new InternFunc<Func>(_f));
    }

    Func	_f;
  };

  template <typename Func, typename Object>
  struct	InternMethodFunc : public ICallable
  {
    InternMethodFunc(void (Object::*f)(), Object *obj) :
      _f(f), _obj(obj)
    {

    }

    InternMethodFunc(const InternMethodFunc &src) :
      _f(src._f), _obj(src._obj)
    {

    }

    InternMethodFunc	&operator=(const InternMethodFunc &src)
    {
      if (&src != this)
	{
	  _f = src._f;
	  _obj = src._obj;
	}
      return (*this);
    }

    virtual ~InternMethodFunc() {};
    virtual void		operator()()
    {
      (_obj->*_f)();
    }
    virtual ICallable	*clone()
    {
      return (new InternMethodFunc<Func, Object>(_f, _obj));
    }

    void		(Object::*_f)();
    Object	*_obj;
  };

  Function():
    _call(0)
  {
  }

  template <typename Any>
  Function(Any f):
    _call(0)
  {
    _call = new InternFunc<Any>(f);
  }

  template <typename Any, typename Object>
  Function(Any f, Object *obj):
    _call(0)
  {
    _call = new InternMethodFunc<Any, Object>(f, obj);
  }

  ~Function()
  {
    delete _call;
  }

  Function(const Function<void ()> &src):
    _call(src._call == 0 ? 0 : src._call->clone())
  {
  }

  Function<void ()>	&operator=(const Function<void ()> &src)
  {
    if (&src != this)
      {
  	_call = src._call->clone();
      }
    return (*this);
  }

  void		operator()()
  {
    return (*this->_call)();
  }

  ICallable	*_call;
};

template <typename T, typename P1>
struct	Function<T (P1)>
{
  typedef T (*func)(P1);
  typedef T	result_type;

  struct	ICallable
  {
    virtual ~ICallable() {};
    virtual T		operator()(P1) = 0;
    virtual ICallable	*clone() = 0;
  };

  template <typename Func>
  struct	InternFunc : public ICallable
  {
    InternFunc(Func f) :
      _f(f)
    {

    }

    InternFunc(const InternFunc &src) :
      _f(src._f)
    {

    }

    InternFunc	&operator=(const InternFunc &src)
    {
      if (&src != this)
	{
	  _f = src._f;
	}
      return (*this);
    }

    virtual ~InternFunc() {};
    virtual T		operator()(P1 p1)
    {
      return (_f(p1));
    }
    virtual ICallable	*clone()
    {
      return (new InternFunc<Func>(_f));
    }

    Func	_f;
  };

  template <typename Func, typename Object>
  struct	InternMethodFunc : public ICallable
  {
    InternMethodFunc(T (Object::*f)(P1), Object *obj) :
      _f(f), _obj(obj)
    {

    }

    InternMethodFunc(const InternMethodFunc &src) :
      _f(src._f), _obj(src._obj)
    {

    }

    InternMethodFunc	&operator=(const InternMethodFunc &src)
    {
      if (&src != this)
	{
	  _f = src._f;
	  _obj = src._obj;
	}
      return (*this);
    }

    virtual ~InternMethodFunc() {};
    virtual T		operator()(P1 p1)
    {
      return ((_obj->*_f)(p1));
    }
    virtual ICallable	*clone()
    {
      return (new InternMethodFunc<Func, Object>(_f, _obj));
    }

    T		(Object::*_f)(P1);
    Object	*_obj;
  };

  Function():
    _call(0)
  {
  }

  template <typename Any>
  Function(Any f):
    _call(0)
  {
    _call = new InternFunc<Any>(f);
  }

  template <typename Any, typename Object>
  Function(Any f, Object *obj):
    _call(0)
  {
    _call = new InternMethodFunc<Any, Object>(f, obj);
  }

  ~Function()
  {
    delete _call;
  }

  Function(const Function<T (P1)> &src):
    _call(src._call == 0 ? 0 : src._call->clone())
  {
  }

  Function<T (P1)>	&operator=(const Function<T (P1)> &src)
  {
    if (&src != this)
      {
  	this->_call = src._call->clone();
      }
    return (*this);
  }

  T		operator()(P1 p1)
  {
    return ((*this->_call)(p1));
  }

  ICallable	*_call;
};

template <typename P1>
struct	Function<void (P1)>
{
  typedef void (*func)(P1);
  typedef void	result_type;

  struct	ICallable
  {
    virtual ~ICallable() {};
    virtual void		operator()(P1) = 0;
    virtual ICallable	*clone() = 0;
  };

  template <typename Func>
  struct	InternFunc : public ICallable
  {
    InternFunc(Func f) :
      _f(f)
    {

    }

    InternFunc(const InternFunc &src) :
      _f(src._f)
    {

    }

    InternFunc	&operator=(const InternFunc &src)
    {
      if (&src != this)
	{
	  _f = src._f;
	}
      return (*this);
    }

    virtual ~InternFunc() {};
    virtual void		operator()(P1 p1)
    {
      _f(p1);
    }
    virtual ICallable	*clone()
    {
      return (new InternFunc<Func>(_f));
    }

    Func	_f;
  };

  template <typename Func, typename Object>
  struct	InternMethodFunc : public ICallable
  {
    InternMethodFunc(void (Object::*f)(P1), Object *obj) :
      _f(f), _obj(obj)
    {

    }

    InternMethodFunc(const InternMethodFunc &src) :
      _f(src._f), _obj(src._obj)
    {

    }

    InternMethodFunc	&operator=(const InternMethodFunc &src)
    {
      if (&src != this)
	{
	  _f = src._f;
	  _obj = src._obj;
	}
      return (*this);
    }

    virtual ~InternMethodFunc() {};
    virtual void		operator()(P1 p1)
    {
      (_obj->*_f)(p1);
    }
    virtual ICallable	*clone()
    {
      return (new InternMethodFunc<Func, Object>(_f, _obj));
    }

    void		(Object::*_f)(P1);
    Object	*_obj;
  };

  Function():
    _call(0)
  {
  }

  template <typename Any>
  Function(Any f):
    _call(0)
  {
    _call = new InternFunc<Any>(f);
  }

  template <typename Any, typename Object>
  Function(Any f, Object *obj):
    _call(0)
  {
    _call = new InternMethodFunc<Any, Object>(f, obj);
  }

  ~Function()
  {
    delete _call;
  }

  Function(const Function<void (P1)> &src):
    _call(src._call == 0 ? 0 : src._call->clone())
  {
  }

  Function<void (P1)>	&operator=(const Function<void (P1)> &src)
  {
    if (&src != this)
      {
        _call = src._call->clone();
      }
    return (*this);
  }

  void		operator()(P1 p1)
  {
    (*this->_call)(p1);
  }

  ICallable	*_call;
};

template <typename T, typename P1, typename P2>
struct	Function<T (P1, P2)>
{
  typedef T (*func)(P1, P2);
  typedef T	result_type;

  struct	ICallable
  {
    virtual ~ICallable() {};
    virtual T		operator()(P1, P2) = 0;
    virtual ICallable	*clone() = 0;
  };

  template <typename Func>
  struct	InternFunc : public ICallable
  {
    InternFunc(Func f) :
      _f(f)
    {

    }

    InternFunc(const InternFunc &src) :
      _f(src._f)
    {

    }

    InternFunc	&operator=(const InternFunc &src)
    {
      if (&src != this)
	{
	  _f = src._f;
	}
      return (*this);
    }

    virtual ~InternFunc() {};
    virtual T		operator()(P1 p1, P2 p2)
    {
      return (_f(p1, p2));
    }
    virtual ICallable	*clone()
    {
      return (new InternFunc<Func>(_f));
    }

    Func	_f;
  };

  template <typename Func, typename Object>
  struct	InternMethodFunc : public ICallable
  {
    InternMethodFunc(T (Object::*f)(P1, P2), Object *obj) :
      _f(f), _obj(obj)
    {

    }

    InternMethodFunc(const InternMethodFunc &src) :
      _f(src._f), _obj(src._obj)
    {

    }

    InternMethodFunc	&operator=(const InternMethodFunc &src)
    {
      if (&src != this)
	{
	  _f = src._f;
	  _obj = src._obj;
	}
      return (*this);
    }

    virtual ~InternMethodFunc() {};
    virtual T		operator()(P1 p1, P2 p2)
    {
      return ((_obj->*_f)(p1, p2));
    }
    virtual ICallable	*clone()
    {
      return (new InternMethodFunc<Func, Object>(_f, _obj));
    }

    T		(Object::*_f)(P1, P2);
    Object	*_obj;
  };

  Function():
    _call(0)
  {
  }

  template <typename Any>
  Function(Any f):
    _call(0)
  {
    _call = new InternFunc<Any>(f);
  }

  template <typename Any, typename Object>
  Function(Any f, Object *obj):
    _call(0)
  {
    _call = new InternMethodFunc<Any, Object>(f, obj);
  }

  ~Function()
  {
    delete _call;
  }

  Function(const Function<T (P1, P2)> &src):
    _call(src._call == 0 ? 0 : src._call->clone())
  {
  }

  Function<T (P1, P2)>	&operator=(const Function<T (P1, P2)> &src)
  {
    if (&src != this)
      {
  	this->_call = src._call->clone();
      }
    return (*this);
  }

  T		operator()(P1 p1, P2 p2)
  {
    return ((*this->_call)(p1, p2));
  }

  ICallable	*_call;
};

template <typename P1, typename P2>
struct	Function<void (P1, P2)>
{
  typedef void (*func)(P1, P2);
  typedef void	result_type;

  struct	ICallable
  {
    virtual ~ICallable() {};
    virtual void		operator()(P1, P2) = 0;
    virtual ICallable	*clone() = 0;
  };

  template <typename Func>
  struct	InternFunc : public ICallable
  {
    InternFunc(Func f) :
      _f(f)
    {

    }

    InternFunc(const InternFunc &src) :
      _f(src._f)
    {

    }

    InternFunc	&operator=(const InternFunc &src)
    {
      if (&src != this)
	{
	  _f = src._f;
	}
      return (*this);
    }

    virtual ~InternFunc() {};
    virtual void		operator()(P1 p1, P2 p2)
    {
      _f(p1, p2);
    }
    virtual ICallable	*clone()
    {
      return (new InternFunc<Func>(_f));
    }

    Func	_f;
  };

  template <typename Func, typename Object>
  struct	InternMethodFunc : public ICallable
  {
    InternMethodFunc(void (Object::*f)(P1, P2), Object *obj) :
      _f(f), _obj(obj)
    {

    }

    InternMethodFunc(const InternMethodFunc &src) :
      _f(src._f), _obj(src._obj)
    {

    }

    InternMethodFunc	&operator=(const InternMethodFunc &src)
    {
      if (&src != this)
	{
	  _f = src._f;
	  _obj = src._obj;
	}
      return (*this);
    }

    virtual ~InternMethodFunc() {};
    virtual void		operator()(P1 p1, P2 p2)
    {
      (_obj->*_f)(p1, p2);
    }
    virtual ICallable	*clone()
    {
      return (new InternMethodFunc<Func, Object>(_f, _obj));
    }

    void		(Object::*_f)(P1, P2);
    Object	*_obj;
  };

  Function():
    _call(0)
  {
  }

  template <typename Any>
  Function(Any f):
    _call(0)
  {
    _call = new InternFunc<Any>(f);
  }

  template <typename Any, typename Object>
  Function(Any f, Object *obj):
    _call(0)
  {
    _call = new InternMethodFunc<Any, Object>(f, obj);
  }

  ~Function()
  {
    delete _call;
  }

  Function(const Function<void (P1, P2)> &src):
    _call(src._call == 0 ? 0 : src._call->clone())
  {
  }

  Function<void (P1, P2)>	&operator=(const Function<void (P1, P2)> &src)
  {
    if (&src != this)
      {
        _call = src._call->clone();
      }
    return (*this);
  }

  void		operator()(P1 p1, P2 p2)
  {
    (*this->_call)(p1, p2);
  }

  ICallable	*_call;
};

template <typename T, typename P1, typename P2, typename P3>
struct	Function<T (P1, P2, P3)>
{
  typedef T (*func)(P1, P2, P3);
  typedef T	result_type;

  struct	ICallable
  {
    virtual ~ICallable() {};
    virtual T		operator()(P1, P2, P3) = 0;
    virtual ICallable	*clone() = 0;
  };

  template <typename Func>
  struct	InternFunc : public ICallable
  {
    InternFunc(Func f) :
      _f(f)
    {

    }

    InternFunc(const InternFunc &src) :
      _f(src._f)
    {

    }

    InternFunc	&operator=(const InternFunc &src)
    {
      if (&src != this)
	{
	  _f = src._f;
	}
      return (*this);
    }

    virtual ~InternFunc() {};
    virtual T		operator()(P1 p1, P2 p2, P3 p3)
    {
      return (_f(p1, p2, p3));
    }
    virtual ICallable	*clone()
    {
      return (new InternFunc<Func>(_f));
    }

    Func	_f;
  };

  template <typename Func, typename Object>
  struct	InternMethodFunc : public ICallable
  {
    InternMethodFunc(T (Object::*f)(P1, P2, P3), Object *obj) :
      _f(f), _obj(obj)
    {

    }

    InternMethodFunc(const InternMethodFunc &src) :
      _f(src._f), _obj(src._obj)
    {

    }

    InternMethodFunc	&operator=(const InternMethodFunc &src)
    {
      if (&src != this)
	{
	  _f = src._f;
	  _obj = src._obj;
	}
      return (*this);
    }

    virtual ~InternMethodFunc() {};
    virtual T		operator()(P1 p1, P2 p2, P3 p3)
    {
      return ((_obj->*_f)(p1, p2, p3));
    }
    virtual ICallable	*clone()
    {
      return (new InternMethodFunc<Func, Object>(_f, _obj));
    }

    T		(Object::*_f)(P1, P2, P3);
    Object	*_obj;
  };

  Function():
    _call(0)
  {
  }

  template <typename Any>
  Function(Any f):
    _call(0)
  {
    _call = new InternFunc<Any>(f);
  }

  template <typename Any, typename Object>
  Function(Any f, Object *obj):
    _call(0)
  {
    _call = new InternMethodFunc<Any, Object>(f, obj);
  }

  ~Function()
  {
    delete _call;
  }

  Function(const Function<T (P1, P2, P3)> &src):
    _call(src._call == 0 ? 0 : src._call->clone())
  {
  }

  Function<T (P1, P2, P3)>	&operator=(const Function<T (P1, P2, P3)> &src)
  {
    if (&src != this)
      {
  	this->_call = src._call->clone();
      }
    return (*this);
  }

  T		operator()(P1 p1, P2 p2, P3 p3)
  {
    return ((*this->_call)(p1, p2, p3));
  }

  ICallable	*_call;
};

template <typename P1, typename P2, typename P3>
struct	Function<void (P1, P2, P3)>
{
  typedef void (*func)(P1, P2, P3);
  typedef void	result_type;

  struct	ICallable
  {
    virtual ~ICallable() {};
    virtual void		operator()(P1, P2, P3) = 0;
    virtual ICallable	*clone() = 0;
  };

  template <typename Func>
  struct	InternFunc : public ICallable
  {
    InternFunc(Func f) :
      _f(f)
    {

    }

    InternFunc(const InternFunc &src) :
      _f(src._f)
    {

    }

    InternFunc	&operator=(const InternFunc &src)
    {
      if (&src != this)
	{
	  _f = src._f;
	}
      return (*this);
    }

    virtual ~InternFunc() {};
    virtual void		operator()(P1 p1, P2 p2, P3 p3)
    {
      _f(p1, p2, p3);
    }
    virtual ICallable	*clone()
    {
      return (new InternFunc<Func>(_f));
    }

    Func	_f;
  };

  template <typename Func, typename Object>
  struct	InternMethodFunc : public ICallable
  {
    InternMethodFunc(void (Object::*f)(P1, P2, P3), Object *obj) :
      _f(f), _obj(obj)
    {

    }

    InternMethodFunc(const InternMethodFunc &src) :
      _f(src._f), _obj(src._obj)
    {

    }

    InternMethodFunc	&operator=(const InternMethodFunc &src)
    {
      if (&src != this)
	{
	  _f = src._f;
	  _obj = src._obj;
	}
      return (*this);
    }

    virtual ~InternMethodFunc() {};
    virtual void		operator()(P1 p1, P2 p2, P3 p3)
    {
      (_obj->*_f)(p1, p2, p3);
    }
    virtual ICallable	*clone()
    {
      return (new InternMethodFunc<Func, Object>(_f, _obj));
    }

    void		(Object::*_f)(P1, P2, P3);
    Object	*_obj;
  };

  Function():
    _call(0)
  {
  }

  template <typename Any>
  Function(Any f):
    _call(0)
  {
    _call = new InternFunc<Any>(f);
  }

  template <typename Any, typename Object>
  Function(Any f, Object *obj):
    _call(0)
  {
    _call = new InternMethodFunc<Any, Object>(f, obj);
  }

  ~Function()
  {
    delete _call;
  }

  Function(const Function<void (P1, P2, P3)> &src):
    _call(src._call == 0 ? 0 : src._call->clone())
  {
  }

  Function<void (P1, P2, P3)>	&operator=(const Function<void (P1, P2, P3)> &src)
  {
    if (&src != this)
      {
  	_call = src._call->clone();
      }
    return (*this);
  }

  void		operator()(P1 p1, P2 p2, P3 p3)
  {
    (*this->_call)(p1, p2, p3);
  }

  ICallable	*_call;
};

#endif /* FUNCTION_H_ */
