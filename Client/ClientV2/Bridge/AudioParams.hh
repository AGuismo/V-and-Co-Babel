#ifndef			AUDIOPARAMS_H
# define		 AUDIOPARAMS_H

# define		WRITE_TO_FILE		(0)
# define		PA_SAMPLE_TYPE		paInt16
# define		SAMPLE_SILENCE		(0)
typedef			short				SAMPLE;

# define		ABS(value)			((value < 0) ? (- (value)) : (value))
# define		SAMPLE_RATE			(24000)
# define		CBUFF_SIZE			(65536)
# define		MAX_PACKET_SIZE		(3 * 1276)
# define		FRAMES_PER_BUFFER	(960)
# define		NUM_SECONDS			(5)
# define		NUM_CHANNELS		(2)
# define		DITHER_FLAG			(0)
# define		MAX_FRAME_SIZE		(FRAMES_PER_BUFFER * 6)
# define		NUM_BYTES			(FRAMES_PER_BUFFER * NUM_CHANNELS * 2)
# define		BITRATE				(128000)

#endif