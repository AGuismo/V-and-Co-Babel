#ifndef		OPUS_AUDIOCODEC_H
# define	OPUS_AUDIOCODEC_H

# include			"IAudioCodec.hh"
#if defined(linux)
# include			"opus/opus.h"
#elif defined(_WINDOWS)
#include			"opus.h"
#endif

class				OpAudioCodec : public IAudioCodec
{
private:
  OpusEncoder			*_encoder;
  OpusDecoder			*_decoder;
  unsigned char			*_encodeBuff;
  SAMPLE				*_decodeBuff;

public:
  virtual bool			init();
  virtual bool			stop();
  virtual unsigned int	encode(SAMPLE *in, unsigned int inSize, unsigned char *out, unsigned int outSize);
  virtual unsigned int	decode(const unsigned char *in, unsigned int inSize, SAMPLE *out, unsigned int outSize);
  bool					printOpusError(int error) const;

public:
  OpAudioCodec();
  ~OpAudioCodec();
};

#endif
