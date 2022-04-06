#ifndef POWER_SIMULATION_DATA_GENERATOR
#define POWER_SIMULATION_DATA_GENERATOR

#include <SimulationChannelDescriptor.h>
#include <string>
class PowerAnalyzerSettings;

class PowerSimulationDataGenerator
{
public:
	PowerSimulationDataGenerator();
	~PowerSimulationDataGenerator();

	void Initialize( U32 simulation_sample_rate, PowerAnalyzerSettings* settings );
	U32 GenerateSimulationData( U64 newest_sample_requested, U32 sample_rate, SimulationChannelDescriptor** simulation_channel );

protected:
	PowerAnalyzerSettings* mSettings;
	U32 mSimulationSampleRateHz;

protected:
	void CreateSerialByte();
	std::string mSerialText;
	U32 mStringIndex;

	SimulationChannelDescriptor mSerialSimulationData;

};
#endif //POWER_SIMULATION_DATA_GENERATOR