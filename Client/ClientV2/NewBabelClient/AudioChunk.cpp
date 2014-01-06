#include		<cstring>
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
	memset(_content, 0, _capacity);
}

void					AudioChunk::assign(const SAMPLE *str, unsigned int size)
{
	if (size > _capacity)
		_size = _capacity;
	else
		_size = size;
	for (std::size_t it = 0; it < _size; ++it)
		_content[it] = str[it];
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
