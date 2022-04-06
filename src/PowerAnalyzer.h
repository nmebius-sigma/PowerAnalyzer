#ifndef POWER_ANALYZER_H
#define POWER_ANALYZER_H

#include <Analyzer.h>
#include "PowerAnalyzerResults.h"
#include "PowerSimulationDataGenerator.h"

class PowerAnalyzerSettings;
class ANALYZER_EXPORT PowerAnalyzer : public Analyzer2
{
public:
	PowerAnalyzer();
	virtual ~PowerAnalyzer();

	virtual void SetupResults();
	virtual void WorkerThread();

	virtual U32 GenerateSimulationData( U64 newest_sample_requested, U32 sample_rate, SimulationChannelDescriptor** simulation_channels );
	virtual U32 GetMinimumSampleRateHz();

	virtual const char* GetAnalyzerName() const;
	virtual bool NeedsRerun();

protected: //vars
	std::auto_ptr< PowerAnalyzerSettings > mSettings;
	std::auto_ptr< PowerAnalyzerResults > mResults;
	AnalyzerChannelData* mSerial;

	PowerSimulationDataGenerator mSimulationDataGenerator;
	bool mSimulationInitilized;

	//Serial analysis vars:
	U32 mSampleRateHz;
	U32 mStartOfStopBitOffset;
	U32 mEndOfStopBitOffset;
};

extern "C" ANALYZER_EXPORT const char* __cdecl GetAnalyzerName();
extern "C" ANALYZER_EXPORT Analyzer* __cdecl CreateAnalyzer( );
extern "C" ANALYZER_EXPORT void __cdecl DestroyAnalyzer( Analyzer* analyzer );

#endif //POWER_ANALYZER_H
