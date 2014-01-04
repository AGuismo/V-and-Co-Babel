#include	"AudioParams.hh"
#include "AudioBridge.hh"

AudioBridge::AudioBridge(std::size_t capacity) :
	ABridge<input, output>(capacity)
{
	for (std::size_t it = 0; it < (capacity * 2); ++it)
		_unused.push(new AudioChunk(FRAME_PACKET_SIZE * sizeof(SAMPLE)));
}

AudioBridge::~AudioBridge()
{

}

void  AudioBridge::inputRead(input_buffer &buff, std::size_t size, bool blocking)
{
  ABridge<input, output>::inputRead(buff, size, blocking);
}

void  AudioBridge::inputWrite(const input_buffer &buff)
{
  ABridge<input, output>::inputWrite(buff);
}

void  AudioBridge::inputPush(input &buff)
{
  ABridge<input, output>::inputPush(buff);
}

AudioBridge::input	&AudioBridge::inputPop()
{
	return (ABridge<input, output>::inputPop());
}

bool  AudioBridge::inputEmpty() const
{
  return (ABridge<input, output>::inputEmpty());
}

void  AudioBridge::outputRead(output_buffer &buff, std::size_t size, bool blocking)
{
  ABridge<input, output>::outputRead(buff, size, blocking);
}

void  AudioBridge::outputWrite(const output_buffer &buff)
{
  ABridge<input, output>::outputWrite(buff);
}

void  AudioBridge::outputPush(output &buff)
{
  ABridge<input, output>::outputPush(buff);
}

AudioBridge::output	&AudioBridge::outputPop()
{
	return (ABridge<input, output>::outputPop());
}

bool  AudioBridge::outputEmpty() const
{
  return (ABridge<input, output>::outputEmpty());
}

AudioChunk	*AudioBridge::popUnused()
{
	if (_unused.empty())
		return (0);

	AudioChunk	*chunk = _unused.top();

	_unused.pop();
	return (chunk);
}

void	AudioBridge::pushUnused(AudioChunk *chunk)
{
	_unused.push(chunk);
}