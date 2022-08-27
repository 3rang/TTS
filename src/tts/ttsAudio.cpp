

#include "include/ttsAudio.hpp"

void Create16stereo(std::ostream& file_p,int32_t SampleRate,int32_t FrameCount)
{

	s_wavfileHeader wavHeader;
	float subchunk2_size;
	float chunk_size;

	subchunk2_size  = FrameCount * NUM_CHANNELS * BITS_PER_SAMPLE/8;
	chunk_size      = 4 + (8 + SUBCHUNK1SIZE) + (8 + subchunk2_size);

	wavHeader.ChunkID[0] = 'R';
	wavHeader.ChunkID[1] = 'I';
	wavHeader.ChunkID[2] = 'F';
	wavHeader.ChunkID[3] = 'F';

	wavHeader.ChunkSize = chunk_size;

	wavHeader.Format[0] = 'W';
	wavHeader.Format[1] = 'A';
	wavHeader.Format[2] = 'V';
	wavHeader.Format[3] = 'E';

	wavHeader.Subchunk1ID[0] = 'f';
	wavHeader.Subchunk1ID[1] = 'm';
	wavHeader.Subchunk1ID[2] = 't';
	wavHeader.Subchunk1ID[3] = ' ';

	wavHeader.Subchunk1Size = SUBCHUNK1SIZE;
	wavHeader.AudioFormat = AUDIO_FORMAT;
	wavHeader.NumChannels = NUM_CHANNELS;
	wavHeader.SampleRate = SampleRate;
	wavHeader.ByteRate = BYTE_RATE;
	wavHeader.BlockAlign = BLOCK_ALIGN;
	wavHeader.BitsPerSample = BITS_PER_SAMPLE;

	wavHeader.Subchunk2ID[0] = 'd';
	wavHeader.Subchunk2ID[1] = 'a';
	wavHeader.Subchunk2ID[2] = 't';
	wavHeader.Subchunk2ID[3] = 'a';
	wavHeader.Subchunk2Size = subchunk2_size;

	file_p.write((const char*)&wavHeader, sizeof(s_wavfileHeader));

}


void write_PCM16wav_data(std::ostream& file_p, std::vector<s_stereo16PCM> buffer_p1)
{
	for(auto id:buffer_p1){
		file_p.write((const char*)&id, sizeof(s_stereo16PCM));
	}
}
