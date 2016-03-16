#ifndef FINNIGAN_OBSERVER
#define FINNIGAN_OBSERVER

#include <string>

namespace org{ namespace openscience { namespace ms{ namespace finnigan {

	class Element;

	class Observer {

		public:

			virtual void new_child_added(const Element*) {}
			virtual void data_read(const Element*) {}

	};
}}}}

#endif // FINNIGAN_OBSERVER
