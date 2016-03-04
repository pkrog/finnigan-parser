#ifndef FINNIGAN_HEADER
#define FINNIGAN_HEADER

#include "Element.hpp"

namespace org::openscience::ms::finnigan {

	class Header : public Element {

		public:
			void define_children();
	};

}

#endif // FINNIGAN_HEADER
