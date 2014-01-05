#ifndef						IAUDIOCODEC_H
# define					 IAUDIOCODEC_H

# include					"AudioParams.hh"

class						IAudioCodec
{
public:
  virtual bool		init() = 0;
  virtual bool		stop() = 0;
  virtual unsigned char	*encode(SAMPLE *frame, unsigned int frameSize, unsigned int &encodedSize) = 0;
  virtual SAMPLE	*decode(unsigned char *compressed, unsigned int frameSize) = 0;

public:
  virtual ~IAudioCodec() {};
};

#endif
