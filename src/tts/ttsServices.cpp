// SPDX-FileCopyrightText: 2021 MBition GmbH
//
// SPDX-License-Identifier: Closed software


#include"include/ttsService.hpp"


MelGenData ttsBaseMel::interpreterBuildMel(std::vector<int32_t> &localbuf)
{
	model = tflite::FlatBufferModel::BuildFromFile(melgenPath);

	TFLITE_MINIMAL_CHECK(model != nullptr);

	tflite::InterpreterBuilder builder(*model, resolver);

	builder(&interpreter);

	TFLITE_MINIMAL_CHECK(interpreter != nullptr);

	int32_t ouptIndex;

	std::vector<int32_t> inputIndexs;

	MelGenData output;

	std::vector<int32_t> _speakerId{0};
	std::vector<float> _speedRatio{1.0};
	std::vector<float> _f0Ratio{1.0};
	std::vector<float> _enegyRatio{1.0};


	inputIndexs = (interpreter->inputs());
	ouptIndex = (interpreter->outputs()[0]);

	int idsLen = localbuf.size();


	std::vector<std::vector<int32_t>> inputIndexsShape{ {1, idsLen}, {1}, {1}, {1}, {1} };

	int32_t shapeI = 0;

	for (auto index : inputIndexs)
	{
		interpreter->ResizeInputTensor(index, inputIndexsShape[shapeI]);
		shapeI++;
	}

	TFLITE_MINIMAL_CHECK(interpreter->AllocateTensors() == kTfLiteOk);  //  0 milli sec......


	int32_t* input_ids_ptr = interpreter->typed_tensor<int32_t>(inputIndexs[0]);
	memcpy(input_ids_ptr, localbuf.data(), sizeof(int) * idsLen);

	int32_t* speaker_ids_ptr = interpreter->typed_tensor<int32_t>(inputIndexs[1]);
	memcpy(speaker_ids_ptr, _speakerId.data(), sizeof(int));

	float* speed_ratios_ptr = interpreter->typed_tensor<float>(inputIndexs[2]);
	memcpy(speed_ratios_ptr, _speedRatio.data(), sizeof(float));

	float* speed_ratios2_ptr = interpreter->typed_tensor<float>(inputIndexs[3]);
	memcpy(speed_ratios2_ptr, _f0Ratio.data(), sizeof(float));

	float* speed_ratios3_ptr = interpreter->typed_tensor<float>(inputIndexs[4]);
	memcpy(speed_ratios3_ptr, _enegyRatio.data(), sizeof(float));

	// Run inference
	TFLITE_MINIMAL_CHECK(interpreter->Invoke() == kTfLiteOk);  //  4000 milli sec. to 2600 milli

	TfLiteTensor* melGenTensor = interpreter->tensor(ouptIndex);

	for (int i=0; i<melGenTensor->dims->size; i++)
	{
		output.mel_Shape.push_back(melGenTensor->dims->data[i]);
	}

	output.mel_bytes = melGenTensor->bytes;

	output.mel_Data = interpreter->typed_tensor<float>(ouptIndex);


	return output;
}


std::vector<float> ttsBasevocodoer::interpreterBuildvocoder(MelGenData &localbufV)
{
	model = tflite::FlatBufferModel::BuildFromFile(vocoderPath);

	TFLITE_MINIMAL_CHECK(model != nullptr);

	tflite::InterpreterBuilder builder1(*model, resolver);

	builder1(&interpreter);

	TFLITE_MINIMAL_CHECK(interpreter != nullptr);


	const int32_t inputIndexV = (interpreter->inputs()[0]);;


	const  int32_t outputIndexV = (interpreter->outputs()[0]);;

	std::vector<float> audio;

	interpreter->ResizeInputTensor(inputIndexV, localbufV.mel_Shape);

	TFLITE_MINIMAL_CHECK(interpreter->AllocateTensors() == kTfLiteOk); // 3 milli

	float* melDataPtr = interpreter->typed_input_tensor<float>(inputIndexV);

	memcpy(melDataPtr, localbufV.mel_Data, localbufV.mel_bytes);

	TFLITE_MINIMAL_CHECK(interpreter->Invoke() == kTfLiteOk);  // 3485 milli  lowest 1450 milli

	TfLiteTensor* audioTensor = interpreter->tensor(outputIndexV);

	float* outputPtr = interpreter->typed_output_tensor<float>(0);

	int32_t audio_len = audioTensor->bytes / sizeof(float);


	for (int i=0; i<audio_len; ++i)
	{
		audio.push_back(outputPtr[i]);
	}

	return audio;

}
