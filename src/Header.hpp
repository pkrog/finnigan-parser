#ifndef FINNIGAN_HEADER
#define FINNIGAN_HEADER

#include "Element.hpp"

namespace org{ namespace openscience { namespace ms{ namespace finnigan {

	class Header : public Element {

		public:
			void define_children();
	};

}}}}

#endif // FINNIGAN_HEADER
