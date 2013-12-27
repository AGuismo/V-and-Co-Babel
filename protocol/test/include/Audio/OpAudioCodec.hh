#ifndef						OPUS_AUDIOCODEC_H
# define					 OPUS_AUDIOCODEC_H

# include					"IAudioCodec.hh"
# include					"opus/opus.h"

class						OpAudioCodec : public IAudioCodec
{
private:
	unsigned char			*_encBuffer;
	SAMPLE					*_decBuffer;
	OpusEncoder				*_encoder;
	OpusDecoder				*_decoder;
	opus_int32				_encodedSize;

public:
	virtual bool			init();
	virtual unsigned char	*encode(SAMPLE *frame, unsigned int frameSize, unsigned int &encodedSize);
	virtual SAMPLE			*decode(const unsigned char *frame, unsigned int frameSize);

public:
	OpAudioCodec();
	~OpAudioCodec();
};

#endif
