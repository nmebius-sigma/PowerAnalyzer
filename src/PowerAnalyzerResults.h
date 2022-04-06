#ifndef POWER_ANALYZER_RESULTS
#define POWER_ANALYZER_RESULTS

#include <AnalyzerResults.h>

class PowerAnalyzer;
class PowerAnalyzerSettings;

class PowerAnalyzerResults : public AnalyzerResults
{
public:
	PowerAnalyzerResults( PowerAnalyzer* analyzer, PowerAnalyzerSettings* settings );
	virtual ~PowerAnalyzerResults();

	virtual void GenerateBubbleText( U64 frame_index, Channel& channel, DisplayBase display_base );
	virtual void GenerateExportFile( const char* file, DisplayBase display_base, U32 export_type_user_id );

	virtual void GenerateFrameTabularText(U64 frame_index, DisplayBase display_base );
	virtual void GeneratePacketTabularText( U64 packet_id, DisplayBase display_base );
	virtual void GenerateTransactionTabularText( U64 transaction_id, DisplayBase display_base );

protected: //functions

protected:  //vars
	PowerAnalyzerSettings* mSettings;
	PowerAnalyzer* mAnalyzer;
};

#endif //POWER_ANALYZER_RESULTS
