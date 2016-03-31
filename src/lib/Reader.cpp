#include "Reader.hpp"
#include "Header.hpp"
#include "SequencerRow.hpp"
#include "RawFileInfo.hpp"
#include "RunHeader.hpp"
#include "constants.hpp"
#include "names.hpp"
#include <iostream>

using namespace org::openscience::ms::finnigan;

// TODO Remove Factory, because Reader can read version from header.
// TODO Rename Property to Field.

/////////////////
// CONSTRUCTOR //
/////////////////

Reader::Reader(const std::string& file, Observer *obs) :
	file(file),
	ifs(file.c_str(), std::ios::in | std::ios_base::binary),
	Element(0)
{
	// Set observer
	if (obs)
		this->add_observer(obs);

	// Check magic number
	int magic = this->get_child(FEN_HEADER)->get_child(FEN_MAGIC)->get_int();
	if (magic != FINNIGAN_MAGIC)
		throw WrongMagicNumber(file, magic);

	// Check signature
	std::wstring sig = this->get_child(FEN_HEADER)->get_child(FEN_SIGNATURE)->get_string();
	if (sig != FINNIGAN_SIGNATURE)
		throw WrongSignature(file, sig);
}

Element* Reader::get_run_header(int i){

	// Check run header index
	int n = this->get_child(FEN_RAW_FILE_INFO)->get_child(FEN_N_CONTROLLERS)->get_int();
    if (i >= n)
		throw WrongRunHeader(i);

    // Get run header
    std::wstring name = FEN_RUN_HEADER L"_" + std::to_wstring(i);
    Element* e = this->get_child(name);

	// Create run header if needed
    if ( ! e ) {
	    auto pos = this->get_child(FEN_RAW_FILE_INFO)->get_child(FEN_INFO_PREAMBLE)->get_child(FEN_N_CONTROLLERS)->get_child(FEN_RUN_HEADER_ADDRESS L"_" + std::to_wstring(i))->get_int();
	    e = new RunHeader(pos);
	    this->add_child(name, e);
	}

    return e;
}

/////////////////////
// DEFINE CHILDREN //
/////////////////////

void Reader::define_children() {
	if (this->children.empty()) {
		this->add_child(FEN_HEADER, new Header());
		this->add_child(FEN_SEQUENCER_ROW, new SequencerRow());
		// TODO AutoSamplerInfo
		// XXX this->add_child(FEN_RAW_FILE_INFO, new RawFileInfo());
	}
}

//////////////////
// ADD OBSERVER //
//////////////////

void Reader::add_observer(Observer* obs) {
	this->observers.push_back(obs);
}
