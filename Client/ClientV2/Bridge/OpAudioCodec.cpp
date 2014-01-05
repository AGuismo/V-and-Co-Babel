#include		<qdebug.h>
#include		"OpAudioCodec.hh"

// Codec

unsigned char	*OpAudioCodec::encode(SAMPLE *frame, unsigned int frameSize)
{
	unsigned char *compressed = new (unsigned char[_encodedSize]);

  opus_encode(_encoder, frame, frameSize, compressed, _encodedSize);
  return (compressed);
}

SAMPLE			*OpAudioCodec::decode(const unsigned char *compressed, unsigned int frameSize)
{
	SAMPLE		*frame = new (SAMPLE[frameSize * NUM_CHANNELS]);

  opus_packet_get_nb_channels(compressed);
  opus_decode(_decoder, compressed, _encodedSize, frame, frameSize, 0);
  return (frame);
}

// Methods

int			OpAudioCodec::getEncodedSize() const
{
	return (_encodedSize);
}

bool		OpAudioCodec::init()
{
  opus_int32	rate;
  int		error;

  _encoder = 0;
  _decoder = 0;

  _encoder = opus_encoder_create(SAMPLE_RATE, NUM_CHANNELS, OPUS_APPLICATION_VOIP, &error);
  _decoder = opus_decoder_create(SAMPLE_RATE, NUM_CHANNELS, &error);

  if (_encoder == 0 || _decoder == 0)
  {
	  qDebug() << "ERROR : ENCODER/DECODER FAILED";
	  return (false);
  }
  opus_encoder_ctl(_encoder, OPUS_GET_BANDWIDTH(&rate));
  _encodedSize = rate;
  _encodeBuff = new unsigned char[_encodedSize];
  _decodeBuff = new SAMPLE[FRAME_PACKET_SIZE];
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
  _encoder(0), _decoder(0), _encodeBuff(0), _decodeBuff(0), _encodedSize(0)
{
}

OpAudioCodec::~OpAudioCodec()
{
  if (_encoder != 0)
    opus_encoder_destroy(_encoder);
  if (_decoder != 0)
    opus_decoder_destroy(_decoder);
}
