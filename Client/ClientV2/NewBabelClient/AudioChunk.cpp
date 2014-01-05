#define			_SCL_SECURE_NO_WARNINGS
#include		"AudioChunk.hh"
#include		"AudioParams.hh"

// Methods

bool					AudioChunk::empty() const
{
	return (_size == 0);
}

unsigned int			AudioChunk::size() const
{
	return (_size);
}

SAMPLE					*AudioChunk::getContent() const
{
	return (_content);
}

void					AudioChunk::clean()
{
	_size = 0;
}

void					AudioChunk::assign(const SAMPLE *str, unsigned int size)
{
	if (size > _capacity)
		_size = _capacity;
	else
		_size = size;
	std::copy(str, str + _size, _content);
}

// Constructor & Destructor

AudioChunk::AudioChunk(std::size_t capacity) :
	_content(NULL), _capacity(capacity)
{
	_content = new SAMPLE[capacity];
}

AudioChunk::~AudioChunk()
{
}