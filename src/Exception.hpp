#ifndef FINNIGAN_EXCEPTION
#define FINNIGAN_EXCEPTION

#include <string>
#include <sstream>
#include "common.hpp"

namespace org{ namespace openscience { namespace ms{ namespace finnigan {

	class Exception {
		public:
			virtual std::wstring what() const = 0;
	};

	class CannotConvertToType : public Exception {
		public:
			CannotConvertToType(const std::wstring& type_name) : type_name(type_name) {}
			std::wstring what() const {
				return std::wstring(L"Cannot convert internal value to type \"") + this->type_name + L"\".";
			}
		private:
			std::wstring type_name;
	};

	class WrongMagicNumber : public Exception {
		public:
			WrongMagicNumber(const std::string& file, int magic) : file(file), magic(magic) {}
			std::wstring what() const {
				std::wstringstream wss;
				wss << L"File \"" << arr2wstring(file.c_str()) << L"\" is not a Finnigan file or has been corrupted. Its magic number is " << std::hex << std::showbase << magic << L" instead of " << FINNIGAN_MAGIC << L".";
				return wss.str();
			}
		private:
			std::string file;
			int magic;
	};

	class WrongSignature : public Exception {
		public:
			WrongSignature(const std::string& file, const std::wstring& signature) : file(file), signature(signature) {}
			std::wstring what() const {
				std::wstringstream wss;
				wss << L"File \"" << arr2wstring(file.c_str()) << L"\" is not a Finnigan file or has been corrupted. Its signature is \"" << signature << L"\" instead of \"" << FINNIGAN_SIGNATURE << L"\".";
				return wss.str();
			}
		private:
			std::string file;
			std::wstring signature;
	};

	class WrongRunHeader : public Exception {
		public:
			WrongRunHeader(const int index) : index(index) {}
			std::wstring what() const {
				std::wstringstream wss;
				wss << L"RunHeader \"" << index << L" could not be found.";
				return wss.str();
			}
		private:
            int index;
	};

}}}}

#endif // FINNIGAN_EXCEPTION
