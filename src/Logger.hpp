#ifndef FINNIGAN_LOGGER
#define FINNIGAN_LOGGER

#include "Observer.hpp"
#include <ostream>
#include <string>

namespace org::openscience::ms::finnigan {

	class Logger : public Observer {

		public:

			Logger(std::wostream&);

			void new_child_added(const Element*);
			void data_read(const Element*);

		private:

			std::wostream& out;
	};
}

#endif // FINNIGAN_LOGGER
