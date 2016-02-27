#ifndef FINNIGAN_READER
#define FINNIGAN_READER

#include <list>
#include <string>
#include <fstream>
#include <map>
#include <boost/any.hpp>
#include "types.hpp"
#include "common.hpp"

namespace org::openscience::ms::finnigan {

	class Observer;

	class Reader : public Section {

		public:

			Reader(const std::string& file);

			void add_observer(Observer*);
		
			boost::any get_property(Property prop) {
				return this->properties[prop];
			}

		private:

			//TODO Move this methods in a mother class called Parser or Section.

			template<typename T> int read_int() {
				T x;
				this->ifs.read(reinterpret_cast<char*>(&x), sizeof(x));
				return static_cast<int>(x);
			}

			std::wstring read_cstring(int size) {
				uint16_t buf[size];
				this->ifs.read(reinterpret_cast<char*>(buf), sizeof(buf));
				return arr2wstring(buf);
			}

			void read_property(Property property);

			void read_header();

			std::string file;
			std::list<Observer*> observers;
			std::ifstream        ifs;
			std::map<Property, boost::any>  properties;
	};

}

#endif // FINNIGAN_READER
