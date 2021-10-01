

#include "include/ttsService.hpp"
#include "include/textIds.hpp"
#include "include/ttsAudio.hpp"
#include "include/ttsMain.hpp"

int ttsMainHandle(const char **argvv)
{

	tts_textIds tts_textIdsobj(argvv[1]);

	std::vector<int32_t> Buffer_ids = tts_textIdsobj.textIds(argvv[2]);

	ttsBaseMel ttsBaseObj(argvv[3]);

	ttsBasevocodoer ttsBasevocodoerObj(argvv[4]);

	MelGenData output = ttsBaseObj.interpreterBuildMel(Buffer_ids);

	std::vector<float> audio = ttsBasevocodoerObj.interpreterBuildvocoder(output);

	std::vector<s_stereo16PCM> buffer_p(audio.size());

	std::ofstream file("example.wav", std::ios::binary);

	Create16stereo(file,SAMPLE_RATE,audio.size());

	for(unsigned int count=0;count < audio.size();count++)

	{
		buffer_p[count].left  = audio.at(count);
		buffer_p[count].right = audio.at(count);
	}

	write_PCM16wav_data(file,buffer_p);

	return 0;
}
