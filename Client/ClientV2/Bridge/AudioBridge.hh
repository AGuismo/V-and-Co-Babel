#ifndef AUDIOBRIDGE_HH
#define AUDIOBRIDGE_HH

# include "Abridge.hh"

class AudioBridge : ABridge<char, char>
{
public:
  typedef ABridge::input_buffer   input_buffer;
  typedef ABridge::output_buffer  output_buffer;
  typedef char                    input;
  typedef char                    output;

public:
  AudioBridge();
  virtual ~AudioBridge();

protected:
  virtual void    inputRead(input_buffer &, std::size_t);
  virtual void    inputWrite(const input_buffer &);

  virtual void    outputRead(output_buffer &, std::size_t size);
  virtual void    outputWrite(const output_buffer &);

public:
  virtual void    inputReady() = 0;
  virtual void    outputReady() = 0;
};

#endif // AUDIOBRIDGE_HH
