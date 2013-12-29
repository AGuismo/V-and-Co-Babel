#include		"OpAudioCodec.hh"

// Codec

unsigned char	*OpAudioCodec::encode(SAMPLE *frame, unsigned int frameSize, unsigned int &encodedSize)
{
  unsigned char	*compressed;

  compressed = new(unsigned char[_encodedSize]);
  opus_encode_float(_encoder, frame, frameSize, compressed, _encodedSize);
  encodedSize = _encodedSize;
  return (compressed);
}

SAMPLE			*OpAudioCodec::decode(const unsigned char *frame, unsigned int frameSize)
{
  float		*decodedFrame = 0;

  opus_packet_get_nb_channels(frame);
  opus_decode_float(_decoder, frame, _encodedSize, decodedFrame, frameSize, 0);
  return (decodedFrame);
}

// Methods

bool		OpAudioCodec::init()
{
  opus_int32	rate;
  int		error;

  _encoder = opus_encoder_create(SAMPLE_RATE, NUM_CHANNELS, OPUS_APPLICATION_VOIP, &error);
  _decoder = opus_decoder_create(SAMPLE_RATE, NUM_CHANNELS, &error);

  opus_encoder_ctl(_encoder, OPUS_GET_BANDWIDTH(&rate));
  _encodedSize = rate;
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
