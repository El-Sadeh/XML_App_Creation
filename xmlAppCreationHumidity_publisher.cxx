/* xmlAppCreationHumidity_publisher.cxx

A publication of data of type HumidityInfo

This file is derived from code automatically generated by the rtiddsgen 
command:

rtiddsgen -language C++03 -example <arch> xmlAppCreationHumidity.idl

Example publication of type HumidityInfo automatically generated by 
'rtiddsgen'. To test them follow these steps:

(1) Compile this file and the example subscription.

(2) Start the subscription on the same domain used for RTI Data Distribution
Service with the command
objs/<arch>/xmlAppCreationHumidity_subscriber <domain_id> <sample_count>

(3) Start the publication on the same domain used for RTI Data Distribution
Service with the command
objs/<arch>/xmlAppCreationHumidity_publisher <domain_id> <sample_count>

(4) [Optional] Specify the list of discovery initial peers and 
multicast receive addresses via an environment variable or a file 
(in the current working directory) called NDDS_DISCOVERY_PEERS. 

You can run any number of publishers and subscribers programs, and can 
add and remove them dynamically from the domain.

Example:

To run the example application on domain <domain_id>:

On Unix: 

objs/<arch>/xmlAppCreationHumidity_publisher <domain_id> 
objs/<arch>/xmlAppCreationHumidity_subscriber <domain_id> 

On Windows:

objs\<arch>\xmlAppCreationHumidity_publisher <domain_id>  
objs\<arch>\xmlAppCreationHumidity_subscriber <domain_id>   
*/
#include<random>
#include <iostream>

#include <dds/pub/ddspub.hpp>
#include <rti/util/util.hpp> // for sleep()

#include <dds/core/QosProvider.hpp>
#include <dds/sub/DataReader.hpp>
#include <dds/sub/find.hpp>
#include <dds/pub/DataWriter.hpp>
#include <dds/pub/find.hpp>


#include "xmlAppCreationHumidity.hpp"




class PercisionCommandReaderListener : public dds::sub::NoOpDataReaderListener<PercisionCommand> {
public:


	PercisionCommandReaderListener(PercisionCommand* pointerToData) : count_(0)
	{
		recentDataHolder = pointerToData;
	}

	void on_data_available(dds::sub::DataReader<PercisionCommand>& reader)
	{
		// Take all samples
		dds::sub::LoanedSamples<PercisionCommand> samples = reader.take();

		for (dds::sub::LoanedSamples<PercisionCommand>::iterator sample_it = samples.begin();
			sample_it != samples.end(); sample_it++) {

			if (sample_it->info().valid()) {
				count_++;
				recentData = (sample_it->data());
				*recentDataHolder = recentData;
				std::cout << sample_it->data() << std::endl;
			}
		}
	}

	int count() const
	{
		return count_;
	}

	PercisionCommand recentData;	// A place to hold the pointer to send
	PercisionCommand *recentDataHolder;
private:

	int count_;
};



void publisher_main(int domain_id, int sample_count)
{
	//Reading everything form the XML
	auto eladQosProvider = dds::core::QosProvider("mySystemProfiles.xml");
	rti::core::QosProviderParams provider_params;

	// When using user-generated types, you must register the type with RTI 
// Connext DDS before creating the participants and the rest of the entities
// in your system 
	rti::domain::register_type<HumidityInfo>("HumidityInfo");
	rti::domain::register_type<PercisionCommand>("PercisionCommand");

	//Create participant using eladQosProvider instead of dds::core::QosProvider::Default()
	auto participant = eladQosProvider->create_participant_from_config("XmlAppDPLib::XmlAppPublisherDP");

	//create a data writer
	dds::pub::DataWriter<HumidityInfo> writer = rti::pub::find_datawriter_by_name<dds::pub::DataWriter<HumidityInfo>>(
		participant,
		"HumidityPublisher::HumidityDw");

	//Creating data reader
	dds::sub::DataReader<PercisionCommand> reader = rti::sub::find_datareader_by_name<dds::sub::DataReader<PercisionCommand>>(
		participant,
		"PrecisionSubscriber::PercisionDR"
		);



	//Create a  'PercisionCommand' variable and a pointer to that variable.
//The purpose: to enable access from the listener. 
	PercisionCommand percision;		//Will hold the most recent resolution (LOW or HIGH)
	percision.requestedResolution(Resolution::LOW); //Initialize the resolution.
	PercisionCommand* pointerToLastDataRecieved = &percision;	//Create a pointer to 'percision'
	
																//Create a listener
	PercisionCommandReaderListener listener(pointerToLastDataRecieved);
	reader->listener(&listener, dds::core::status::StatusMask::data_available());


	short intRandomHumidity;





	//creating a random generator
	std::default_random_engine generator;
	std::uniform_int_distribution<short> distributionForFloat(0, 10000);
	std::uniform_int_distribution<short> distributionForInt(0, 100);

    HumidityInfo sample;
	for (int count = 0; count < sample_count || sample_count == 0; count++) {
		// Modify the data to be written here

		//When the requested resolution is HIGH:
		if ((pointerToLastDataRecieved->requestedResolution()) == Resolution::HIGH)
		{
			//Generate a float number in the range [0.00,100.00]
			intRandomHumidity = (short)distributionForFloat(generator);
			sample.humidity().floatHumidity(((float)intRandomHumidity) / 100);

		}
		else  //When the requested resolution is LOW:
		{
			//Generate a short int number in the range [0,100]
			sample.humidity().shortHumidity(((short)distributionForInt(generator)));
		}

		std::cout << "Writing ResolutionCommand, count " << count << std::endl;
		writer.write(sample);

		rti::util::sleep(dds::core::Duration(1));
	}
}

int main(int argc, char *argv[])
{

    int domain_id = 0;
    int sample_count = 0; // infinite loop

    if (argc >= 2) {
        domain_id = atoi(argv[1]);
    }
    if (argc >= 3) {
        sample_count = atoi(argv[2]);
    }

    // To turn on additional logging, include <rti/config/Logger.hpp> and
    // uncomment the following line:
    // rti::config::Logger::instance().verbosity(rti::config::Verbosity::STATUS_ALL);

    try {
        publisher_main(domain_id, sample_count);
    } catch (const std::exception& ex) {
        // This will catch DDS exceptions
        std::cerr << "Exception in publisher_main(): " << ex.what() << std::endl;
        return -1;
    }

    // RTI Connext provides a finalize_participant_factory() method
    // if you want to release memory used by the participant factory singleton.
    // Uncomment the following line to release the singleton:
    //
    // dds::domain::DomainParticipant::finalize_participant_factory();

    return 0;
}

