#include "AudioBridge.hh"

AudioBridge::AudioBridge()
{
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

bool  AudioBridge::outputEmpty() const
{
  return (ABridge<input, output>::outputEmpty());
}
