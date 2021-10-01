
#ifndef INC_TTSAUDIO_HPP_
#define INC_TTSAUDIO_HPP_

#include <iostream>
#include <fstream>
#include <vector>


#define SUBCHUNK1SIZE   (16)
#define AUDIO_FORMAT    (3)
#define NUM_CHANNELS    (2)
#define SAMPLE_RATE     (22050)

#define BITS_PER_SAMPLE (32)

#define BYTE_RATE       (SAMPLE_RATE * NUM_CHANNELS * BITS_PER_SAMPLE/8)
#define BLOCK_ALIGN     (NUM_CHANNELS * BITS_PER_SAMPLE/8)


typedef struct wavfileHeader
{
	char    ChunkID[4];     /*  4   */
	int32_t ChunkSize;      /*  4   */
	char    Format[4];      /*  4   */

	char    Subchunk1ID[4]; /*  4   */
	int32_t Subchunk1Size;  /*  4   */
	int16_t AudioFormat;    /*  2   */
	int16_t NumChannels;    /*  2   */
	int32_t SampleRate;     /*  4   */
	int32_t ByteRate;       /*  4   */
	int16_t BlockAlign;     /*  2   */
	int16_t BitsPerSample;  /*  2   */

	char    Subchunk2ID[4];
	int32_t Subchunk2Size;
} s_wavfileHeader;

/*Data structure to hold a single frame with two channels*/

typedef struct stereo16PCM
{
	float left;
	float right;
} s_stereo16PCM;

	void Create16stereo(std::ostream& file_p,int32_t SampleRate,int32_t FrameCount);
	void  write_PCM16wav_data(std::ostream& file_p, std::vector<s_stereo16PCM> buffer_p1);



#endif /* INC_TTSAUDIO_HPP_ */
