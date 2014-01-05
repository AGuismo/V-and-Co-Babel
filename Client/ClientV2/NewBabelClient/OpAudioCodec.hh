#ifndef		OPUS_AUDIOCODEC_H
# define	OPUS_AUDIOCODEC_H

# include			"IAudioCodec.hh"
#if defined(linux)
# include			"opus/opus.h"
#elif defined(WIN32)
#include			"opus.h"
#endif

class				OpAudioCodec : public IAudioCodec
{
private:
  unsigned char			*_encBuffer;
  SAMPLE				*_decBuffer;
  OpusEncoder			*_encoder;
  OpusDecoder			*_decoder;
  opus_int32			_encodedSize;

public:
  virtual bool			init();
  virtual bool			stop();
  virtual opus_int32	getEncodedSize() const;
  virtual unsigned char	*encode(SAMPLE *frame, unsigned int frameSize, unsigned int &encodedSize);
  virtual SAMPLE		*decode(unsigned char *compressed, unsigned int frameSize);

public:
  OpAudioCodec();
  ~OpAudioCodec();
};

#endif
