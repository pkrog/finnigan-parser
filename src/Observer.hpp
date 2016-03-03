#ifndef FINNIGAN_OBSERVER
#define FINNIGAN_OBSERVER

#include "Field.hpp"
#include <string>

namespace org::openscience::ms::finnigan {

	class Observer {

		public:

			virtual void field_value_changed(const Field&) {}
			virtual void new_field_added(const Field&) {}
//			virtual void wrong_magic_number(const std::string& file, int magic) {}

//			virtual void wrong_signature(const std::string& file, const std::wstring& signature) {}

	};
}

#endif // FINNIGAN_OBSERVER
