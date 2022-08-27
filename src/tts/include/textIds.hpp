

#ifndef INC_TEXTIDS_HPP_
#define INC_TEXTIDS_HPP_

#include <iostream>
#include <vector>
#include <cstdint>
#include <cstring>
#include <string>
#include <chrono>
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class tts_textIds
{

private:
	const char* jsonPath;

public:
	tts_textIds(const char* path):jsonPath(path){}

	std::vector<int32_t> textIds(const std::string &text);
};

#endif /* INC_TEXTIDS_HPP_ */
