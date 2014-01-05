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
  opus_int32			_encodedSize;

public:
  virtual bool			init();
  virtual bool			stop();
  virtual int			getEncodedSize() const;
  virtual unsigned char	*encode(SAMPLE *frame, unsigned int frameSize);
  virtual SAMPLE		*decode(const unsigned char *compressed, unsigned int frameSize);

public:
  OpAudioCodec();
  ~OpAudioCodec();
};

#endif
