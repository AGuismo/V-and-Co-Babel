#ifndef							AUDIOCHUNK
# define						 AUDIOCHUNK

# include						<vector>

class							AudioChunk
{
private:
	unsigned char				*_content;
	unsigned int				_size;
	unsigned int				_capacity;

public:
	bool						empty() const;
	void						clean();
	unsigned int				size() const;
	unsigned char				*getContent() const;
	void						assign(const unsigned char *str, unsigned int size);

	AudioChunk(std::size_t capacity);
	~AudioChunk();
};

#endif							// !AUDIOCHUNK
