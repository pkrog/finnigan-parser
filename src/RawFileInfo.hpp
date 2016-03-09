#ifndef FINNIGAN_RAW_FILE_INFO
#define FINNIGAN_RAW_FILE_INFO

#include "Element.hpp"

namespace org::openscience::ms::finnigan {
	class RawFileInfo : public Element {

		public:
			void define_children();
	};
}
