#ifndef FINNIGAN_READER
#define FINNIGAN_READER

#include "Element.hpp"
#include <string>
#include <fstream>

namespace org{ namespace openscience { namespace ms{ namespace finnigan {

	class Observer;

	class Reader : public Element {

		public:

			Reader(const std::string& file, Observer* obs = nullptr);

			void add_observer(Observer*);

			std::wstring get_path() const { return L""; }

			Element * get_run_header(int i);

		protected:

			std::ifstream& get_stream() { return this->ifs; }
			Reader* get_top() { return this; }
			std::list<Observer*>* get_observers() { return &(this->observers); }
			void define_children();

		private:
			std::list<Observer*> observers;
			std::string    file;
			std::ifstream  ifs;
	};

}}}}

#endif // FINNIGAN_READER
