#ifndef FINNIGAN_LOGGER
#define FINNIGAN_LOGGER

#include "Observer.hpp"
#include <ostream>
#include <string>

namespace org::openscience::ms::finnigan {

	class Logger : public Observer {

		public:

			Logger(std::wostream&);

			void tag(const std::string& file);
			virtual void wrong_magic_number(const std::string& file, magic_t magic);

			virtual void wrong_signature(const std::string& file, const std::wstring& signature);

		private:

			std::wostream& out;
	};
}

#endif // FINNIGAN_LOGGER
