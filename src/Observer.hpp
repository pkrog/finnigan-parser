#ifndef FINNIGAN_OBSERVER
#define FINNIGAN_OBSERVER

#include <string>

namespace org::openscience::ms::finnigan {

	class Element;

	class Observer {

		public:

			//virtual void field_value_changed(const Field&) {}
			virtual void new_child_added(const Element*) {}
			virtual void data_read(const Element*) {}
			//virtual void field_pos_computed(const Field&) {}
//			virtual void wrong_magic_number(const std::string& file, int magic) {}

//			virtual void wrong_signature(const std::string& file, const std::wstring& signature) {}

	};
}

#endif // FINNIGAN_OBSERVER
