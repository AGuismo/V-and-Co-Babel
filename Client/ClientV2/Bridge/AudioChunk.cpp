#include		"AudioChunk.hh"

// Methods

bool					AudioChunk::empty() const
{
	return (_size == 0);
}

unsigned int			AudioChunk::size() const
{
	return (_size);
}

unsigned char			*AudioChunk::getContent() const
{
	return (_content);
}

void					AudioChunk::assign(const unsigned char *str, unsigned int size)
{
	_content = new (unsigned char[size]);
	_size = size;
	std::copy(str, str + size, _content);
}

// Constructor & Destructor

AudioChunk::AudioChunk() :
	_content(NULL)
{
}

AudioChunk::~AudioChunk()
{
	delete [] _content;
}