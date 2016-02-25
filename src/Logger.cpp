#include "Logger.hpp"

using namespace org::openscience::ms::finnigan;

/////////////////
// CONSTRUCTOR //
/////////////////

Logger::Logger(std::wostream& o) : out(o) {
}

////////////////////////
// WRONG MAGIC NUMBER //
////////////////////////

void Logger::wrong_magic_number(const std::wstring& file, magic_t magic) {
	this->out << L"Wrong magic number " << std::hex << std::showbase << magic << L" ; should be " << MAGIC << L".\n";
}

/////////////////////
// WRONG SIGNATURE //
/////////////////////

void Logger::wrong_signature(const std::wstring& file, const std::wstring& signature) {
	this->out << L"Wrong signature \"" << signature << L"\" ; should be \"" << SIGNATURE << L"\".\n";
}
