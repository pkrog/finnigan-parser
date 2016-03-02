#ifndef FINNIGAN_HEADER
#define FINNIGAN_HEADER

#include "Element.hpp"

namespace org::openscience::ms::finnigan {

	class Header : public Element {

		public:

			Header(const std::string& file, std::shared_ptr<std::ifstream>);
	};
}

#endif // FINNIGAN_HEADER
