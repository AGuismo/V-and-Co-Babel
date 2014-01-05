#ifndef							AUDIOCHUNK
# define						 AUDIOCHUNK

# include						<vector>
# include						"AudioParams.hh"

class							AudioChunk
{
private:
	SAMPLE						*_content;
	unsigned int				_size;
	unsigned int				_capacity;

public:
	bool						empty() const;
	void						clean();
	unsigned int				size() const;
	SAMPLE						*getContent() const;
	void						assign(const SAMPLE *str, unsigned int size);

	AudioChunk(std::size_t capacity);
	~AudioChunk();
};

#endif							// !AUDIOCHUNK
