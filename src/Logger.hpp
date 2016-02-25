#ifndef FINNIGAN_LOGGER
#define FINNIGAN_LOGGER

#include "Observer.hpp"
#include <ostream>
#include <string>

namespace org::openscience::ms::finnigan {

	class Logger : public Observer {

		public:

			Logger(std::wostream&);

			virtual void wrong_magic_number(const std::wstring& file, magic_t magic);

			virtual void wrong_signature(const std::wstring& file, const std::wstring& signature);

		private:

			std::wostream& out;
	};
}

#endif // FINNIGAN_LOGGER
