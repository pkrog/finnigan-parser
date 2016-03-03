#ifndef FINNIGAN_EXCEPTION
#define FINNIGAN_EXCEPTION 

#include <string>

namespace org::openscience::ms::finnigan {

	class Exception {
		public:
			virtual std::wstring what() const = 0;
	};

	class WrongType : public Exception {
		public:
			WrongType(const std::wstring& type_name) : type_name(type_name) {}
			std::wstring what() const {
				return std::wstring(L"Wrong type \"") + this->type_name + L"\".";
			}
		private:
			std::wstring type_name;
	};
}

#endif // FINNIGAN_EXCEPTION
