#include "../Unpacker2/EventIII.h"
#include "../Unpacker2/TDCHitIII.h"
#include "../Unpacker2/Event.h"
#include "./calculate_times.cc"
#include "./calculate_hits.cc"
#include "../Unpacker2/Unpacker2.h"
#include <TH1F.h>
#include <TF1.h>
#include <TMath.h>
#include <TH2F.h>
#include <TTree.h>
#include <TChain.h>
#include <TCanvas.h>
#include <TFile.h>


#define CHANNELS_NUMBER 32

int run_analysis(int eventsNum, char* fileName, char* confFile, int referenceChannel)
{
  
	string newFileName(fileName);
	newFileName += ".root";

	Unpacker2(fileName, confFile, eventsNum);

	calculate_times(eventsNum, newFileName.c_str());

	newFileName = newFileName.substr(0, newFileName.size() - 5);
	newFileName += "_times.root";

	calculate_hits(eventsNum, newFileName.c_str(), referenceChannel);


	return 0;
}
