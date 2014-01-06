#include		<qdebug.h>
#include		"OpAudioCodec.hh"

// Codec

unsigned int	OpAudioCodec::encode(SAMPLE *in, unsigned int inSize, unsigned char *out, unsigned int outSize)
{
	int			numBytes;

	numBytes = opus_encode(_encoder, in, inSize, out, outSize);
	if (numBytes < 0)
		printOpusError(numBytes);
	return (numBytes);
}

unsigned int	OpAudioCodec::decode(const unsigned char *in, unsigned int inSize, SAMPLE *out, unsigned int outSize)
{
	int			numSamples;

	numSamples = opus_decode(_decoder, in, inSize, out, outSize, 0);
	if (numSamples < 0)
		printOpusError(numSamples);
	return (numSamples);
}

// Methods

bool			OpAudioCodec::printOpusError(int error) const
{
  if (error == OPUS_OK)
    return (false);

  switch (error)
    {
    case OPUS_BAD_ARG:
		qDebug() << "One or more invalid/out of range arguments.";
		break;
    case OPUS_BUFFER_TOO_SMALL:
		qDebug() << "The mode struct passed is invalid.";
		break;
    case OPUS_INTERNAL_ERROR:
		qDebug() << "An internal error was detected.";
		break;
    case OPUS_INVALID_PACKET:
		qDebug() << "The compressed data passed is corrupted.";
		break;
    case OPUS_UNIMPLEMENTED:
		qDebug() << "Invalid/unsupported request number.";
		break;
    case OPUS_INVALID_STATE:
		qDebug() << "An encoder or decoder structure is invalid or already freed";
		break;
    case OPUS_ALLOC_FAIL:
		qDebug() << "Memory allocation has failed";
		break;
    default:
      return (false);
    }
  return (true);
}

bool		OpAudioCodec::init()
{
  int			error;

  _encoder = opus_encoder_create(SAMPLE_RATE, NUM_CHANNELS, OPUS_APPLICATION_VOIP, &error);
  if (error < 0)
  {
	  qDebug() << "ERROR : ENCODER ERROR";
	  return (false);
  }
  _decoder = opus_decoder_create(SAMPLE_RATE, NUM_CHANNELS, &error);

  if (error < 0)
  {
	  qDebug() << "ERROR : DECODER ERROR";
	  return (false);
  }
  opus_encoder_ctl(_encoder, OPUS_SET_BITRATE(BITRATE));
  return (true);
}

bool		OpAudioCodec::stop()
{
  if (_encoder != 0)
    opus_encoder_destroy(_encoder);
  if (_decoder != 0)
    opus_decoder_destroy(_decoder);
  return (true);
}

// Constructor / Destructor

OpAudioCodec::OpAudioCodec() :
  _encoder(0), _decoder(0)
{
}

OpAudioCodec::~OpAudioCodec()
{
  if (_encoder != 0)
    opus_encoder_destroy(_encoder);
  if (_decoder != 0)
    opus_decoder_destroy(_decoder);
}
