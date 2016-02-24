#ifndef FINNIGAN_FILE_READER_FACTORY
#define FINNIGAN_FILE_READER_FACTORY

namespace org::openscience::ms {

	class FinniganFileReader;

	FinniganFileReader* make_finnigan_file_reader(const char* file);

}

#endif // FINNIGAN_FILE_READER_FACTORY
