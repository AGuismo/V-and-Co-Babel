#ifndef AUDIOBRIDGE_HH
#define AUDIOBRIDGE_HH

# include	"Abridge.hh"
# include	"AudioChunk.hh"

class AudioBridge : ABridge<AudioChunk, AudioChunk>
{
public:
  typedef ABridge::input_buffer		input_buffer;
  typedef ABridge::output_buffer	output_buffer;
  typedef AudioChunk				input;
  typedef AudioChunk				output;

public:
  AudioBridge();
  virtual ~AudioBridge();

public:
  virtual void    inputRead(input_buffer &, std::size_t, bool blocking = true);
  virtual void    inputWrite(const input_buffer &);
  virtual bool    inputEmpty() const;

  virtual void    outputRead(output_buffer &, std::size_t size, bool blocking = true);
  virtual void    outputWrite(const output_buffer &);
  virtual bool    outputEmpty() const;

public:
  virtual void    inputReady() = 0;
  virtual void    outputReady() = 0;
};

#endif // AUDIOBRIDGE_HH
