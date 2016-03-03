#ifndef FINNIGAN_EXCEPTION
#define FINNIGAN_EXCEPTION 

#include <string>

namespace org::openscience::ms::finnigan {

	class Exception {
		public:
			virtual std::wstring what() const = 0;
	};

#if 0
	class UnknownType : public Exception {
		public:
			UnknownType(const std::wstring& type_name) : type_name(type_name) {}
			std::wstring what() const {
				return std::wstring(L"Unknown type \"") + this->type_name + L"\".";
			}
		private:
			std::wstring type_name;
	};
#endif
}

#endif // FINNIGAN_EXCEPTION
