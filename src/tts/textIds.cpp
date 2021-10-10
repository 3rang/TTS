
// SPDX-FileCopyrightText: 2021 MBition GmbH
//
// SPDX-License-Identifier: Closed software

#include"include/textIds.hpp"

std::vector<int32_t> tts_textIds::textIds(const std::string &text)
{
	json j;

	std::ifstream in(jsonPath);

	in >> j;

	std::string str;

	std::vector<std::string> buffer;

	for (int i = 0; i < text.size(); i++){

		str =text.at(i);

		buffer.push_back(to_string(j["symbol_to_id"][str])+", ");

	}

	buffer.insert(buffer.end(),std::to_string(148));

	std::vector<int32_t> localBuffer_ids;

	for (int iu = 0 ; iu < buffer.size(); iu++)
	{
		int pas = atoi(buffer.at(iu).c_str());
		localBuffer_ids.push_back(pas);
	}
	return localBuffer_ids;
}
