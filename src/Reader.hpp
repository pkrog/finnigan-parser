#ifndef FINNIGAN_READER
#define FINNIGAN_READER

#include "Element.hpp"
#include <string>
#include <fstream>

namespace org::openscience::ms::finnigan {

	class Reader : public Element {

		public:

			Reader(const std::string& file, Observer *obs = nullptr);
	};

}

#endif // FINNIGAN_READER
