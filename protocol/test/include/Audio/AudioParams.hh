#ifndef			AUDIOPARAMS_H
# define		 AUDIOPARAMS_H

# define		ABS(value)			((value < 0) ? (- (value)) : (value))
# define		SAMPLE_RATE			(48000)
# define		CBUFF_SIZE			(65536)
# define		FRAME_PACKET_SIZE	(4096)
# define		FRAMES_PER_BUFFER	(512)
# define		NUM_SECONDS			(5)
# define		NUM_CHANNELS		(2)
# define		DITHER_FLAG			(0)

# define		WRITE_TO_FILE		(0)
# define		PA_SAMPLE_TYPE		paInt16
# define		SAMPLE_SILENCE		(0)
typedef			float				SAMPLE;

#endif