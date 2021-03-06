char* to_cstring(const char* text) {
	return ((char*)text);
}

char* to_cstring(std::string& text) {
	return ((char*)text.c_str());
}

int string_length(char* text) {
	return strlen(text);
}

int string_length(std::string text) {
	return text.size();
}

int string_width(char* text, int size = 10) {
	return (string_length(text) * size);
}

int string_width(std::string text, int size = 10) {
	return (string_length(text) * size);
}

std::string string_format(int num, int len) {
	std::string str;
	str = std::to_string(long long(num));
	str = std::string(max(0, len-string_length(str)),'0') + str;
	return str;
}