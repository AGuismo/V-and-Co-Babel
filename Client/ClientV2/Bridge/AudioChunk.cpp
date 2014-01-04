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

void					AudioChunk::clean()
{
	_size = 0;
}

void					AudioChunk::assign(const unsigned char *str, unsigned int size)
{
	if (size > _capacity)
		_size = _capacity;
	else
		_size = size;
	std::copy(str, str + _size, _content);
}

// Constructor & Destructor

AudioChunk::AudioChunk(std::size_t capacity) :
	_content(NULL)
{
	_content = new unsigned char[capacity];
}

AudioChunk::~AudioChunk()
{
	delete [] _content;
}