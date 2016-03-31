#ifndef FINNIGAN_RUN_HEADER
#define FINNIGAN_RUN_HEADER

#include "Element.hpp"

namespace org{ namespace openscience { namespace ms{ namespace finnigan {

	class RunHeader : public Element {

		public:
			RunHeader(int64_t pos);
			void define_children();
	};

}}}}

#endif // FINNIGAN_RUN_HEADER

