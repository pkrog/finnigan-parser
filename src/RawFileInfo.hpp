#ifndef FINNIGAN_RAW_FILE_INFO
#define FINNIGAN_RAW_FILE_INFO

#include "Element.hpp"

namespace org{ namespace openscience { namespace ms{ namespace finnigan {
	class RawFileInfo : public Element {

		public:
			void define_children();
	};
}}}}
