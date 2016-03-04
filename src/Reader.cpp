#include "Reader.hpp"
#include "Header.hpp"
#include "SequencerRow.hpp"
#include "common.hpp"
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

/////////////////////
// DEFINE CHILDREN //
/////////////////////

void Reader::define_children() {
	if (this->children.empty()) {
		this->add_child(FEN_HEADER, new Header());
		this->add_child(FEN_SEQUENCER_ROW, new SequencerRow());
		// AutoSamplerInfo
		// RawFileInfo --> this is where are the addresses of the data.
	}
}

//////////////////
// ADD OBSERVER //
//////////////////

void Reader::add_observer(Observer* obs) {
	this->observers.push_back(obs);
}
