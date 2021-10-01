

#ifndef INC_TTSSERVICE_HPP_
#define INC_TTSSERVICE_HPP_

#include <iostream>
#include <vector>
#include <cstdint>
#include <cstring>
#include <string>
#include <chrono>
#include <fstream>
#include <tensorflow/lite/interpreter.h>
#include <tensorflow/lite/kernels/register.h>
#include <tensorflow/lite/model.h>
#include <tensorflow/lite/optional_debug_tools.h>

typedef struct
{
	float *mel_Data;
	std::vector<int32_t> mel_Shape;
	int32_t mel_bytes;
} MelGenData;


#define TFLITE_MINIMAL_CHECK(x)                              \
	if (!(x)) {                                                \
		fprintf(stderr, "Error at %s:%d\n", __FILE__, __LINE__); \
		exit(1);                                                 \
	}

class ttsBase
{

	public:

		std::unique_ptr<tflite::FlatBufferModel> model;
		std::unique_ptr<tflite::Interpreter> interpreter;
		tflite::ops::builtin::BuiltinOpResolver resolver;

};


class ttsBaseMel:public ttsBase
{

	private:

		const char* melgenPath;

	public:
		ttsBaseMel(const char* melgenfile): melgenPath(melgenfile)
	{
		std::cout << "TTSModel melgenPath" << std::endl;
	};

		MelGenData interpreterBuildMel(std::vector<int32_t> &localbuf);

};


class ttsBasevocodoer:public ttsBase
{

	private:

		const char* vocoderPath;

	public:

		ttsBasevocodoer(const char* vocoderfile): vocoderPath(vocoderfile)
	{
		std::cout << "TTSModel vocoderfile" << std::endl;
	};

		std::vector<float> interpreterBuildvocoder(MelGenData &localbufV);

};


#endif /* INC_TTSSERVICE_HPP_ */
