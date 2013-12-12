#ifndef IENV_H_
# define IENV_H_

class IEnv
{
protected:
  virtual ~IEnv();

  virtual bool	loadFile(const std::string &) = 0;
};

#endif /* IENV_H_ */
