#include <iostream>
#include <string>
#include <set>
#include <sstream> 
#include <regex>

// function declarations
std::string clean_message(std::string);

int main()
{
	// var declarations
	std::string chat_message;
	std::set<std::string> banned_words;

	// insert banned words into set
	banned_words.insert("heck");
	banned_words.insert("hecking");
	banned_words.insert("shoot");


	// enter message char output
	std::cout << "Enter in a message\n";

	// read chars from input stream and place them in `chat_message` var
	std::getline(std::cin, chat_message);

	// clean chat message
	chat_message = clean_message(chat_message);

	// create string stream of words in message
	std::stringstream string_stream(chat_message);

	do {
		// currently streamed word declaration
		std::string word;
		// stream and assign word
		string_stream >> word;

		// flag if word is banned
		const bool is_in = banned_words.find(word) != banned_words.end();

		// replace word
		if (is_in) {
			chat_message.replace(chat_message.find(word), word.size(), "****");
		}
	} while (string_stream);

	// censored message char output 
	std::cout << chat_message;
}

std::string clean_message(std::string message) {
	// var declartions
	std::regex replace_special_chars("[^a-zA-Z ]"); // only keep letters and spaces
	std::stringstream cleaned_message;

	// replace special chars
	std::regex_replace(std::ostream_iterator<char>(cleaned_message), message.begin(), message.end(), replace_special_chars, "");

	return cleaned_message.str();
}