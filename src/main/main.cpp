#include "ttsService.hpp"
#include "textIds.hpp"
#include "ttsAudio.hpp"
#include "ttsMain.hpp"

int main(int argc,const char **argv)
{

	if (argc != 5) {
		std::cout << "Error : json_path ,  text , model_path , vocoder model_path" << std::endl;
		exit(EXIT_FAILURE);
	} 

	if (0 != ttsMainHandle(argv))
	{
		exit(EXIT_FAILURE);
	}
	return 0;
}
