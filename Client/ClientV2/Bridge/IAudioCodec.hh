#ifndef						IAUDIOCODEC_H
# define					 IAUDIOCODEC_H

# include					"AudioParams.hh"

class						IAudioCodec
{
public:
  virtual bool				init() = 0;
  virtual bool				stop() = 0;
  virtual unsigned int		encode(SAMPLE *in, unsigned int inSize, unsigned char *out, unsigned int outSize) = 0;
  virtual unsigned int		decode(const unsigned char *in, unsigned int inSize, SAMPLE *out, unsigned int outSize) = 0;

public:
  virtual ~IAudioCodec() {};
};

#endif
