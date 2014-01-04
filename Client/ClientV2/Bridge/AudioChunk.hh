#ifndef							AUDIOCHUNK
# define						 AUDIOCHUNK

# include						<vector>

class							AudioChunk
{
private:
	unsigned char				*_content;
	unsigned int				_size;

public:
	bool						empty() const;
	unsigned int				size() const;
	unsigned char				*getContent() const;
	void						assign(const unsigned char *str, unsigned int size);

	AudioChunk();
	~AudioChunk();
};

#endif							// !AUDIOCHUNK
