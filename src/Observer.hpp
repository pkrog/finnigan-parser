#ifndef FINNIGAN_OBSERVER
#define FINNIGAN_OBSERVER

#include "types.hpp"
#include <string>

namespace org::openscience::ms::finnigan {

	class Observer {

		public:

			virtual void wrong_magic_number(const std::string& file, magic_t magic) {}

			virtual void wrong_signature(const std::string& file, const std::wstring& signature) {}

			virtual void file_version(const std::string& file, version_t version) {}

	};
}

#endif // FINNIGAN_OBSERVER
