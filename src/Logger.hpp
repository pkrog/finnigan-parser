#ifndef FINNIGAN_LOGGER
#define FINNIGAN_LOGGER

#include "Observer.hpp"
#include <ostream>
#include <string>

namespace org::openscience::ms::finnigan {

	class Logger : public Observer {

		public:

			Logger(std::wostream&);

//			virtual void wrong_magic_number(const std::string& file, magic_t magic);
//			virtual void wrong_signature(const std::string& file, const std::wstring& signature);
//			virtual void file_version(const std::string& file, version_t version);

//			void field_value_changed(const Field&);
			void new_child_added(const Element*);
			void data_read(const Element*);
//			 void field_pos_computed(const Field&);

		private:

			void errortag(const std::string& file);

			std::wostream& out;
	};
}

#endif // FINNIGAN_LOGGER
