

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from xmlAppCreationHumidity.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#include <iosfwd>
#include <iomanip>

#include "rti/topic/cdr/Serialization.hpp"

#include "xmlAppCreationHumidity.hpp"
#include "xmlAppCreationHumidityPlugin.hpp"

#include <rti/util/ostream_operators.hpp>

std::ostream& operator << (std::ostream& o,const Resolution& sample)
{
    rti::util::StreamFlagSaver flag_saver (o);
    switch(sample.underlying()){
        case Resolution::LOW:
        o << "Resolution::LOW" << " ";
        break;
        case Resolution::HIGH:
        o << "Resolution::HIGH" << " ";
        break;
    }
    return o;
}

// ---- HumidityUnion: 

#ifdef RTI_CXX11_RVALUE_REFERENCES
#ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
HumidityUnion::HumidityUnion(HumidityUnion&& other_) OMG_NOEXCEPT 
{
    _d(std::move(other_._d()));
    switch(rti::topic::cdr::integer_case(_d())){
        case (Resolution::LOW):
            {  
                shortHumidity( std::move(other_.shortHumidity()));
        } break;
        case (Resolution::HIGH):
            {  
                floatHumidity( std::move(other_.floatHumidity()));
        } break;

    }

}

HumidityUnion& HumidityUnion::operator=(HumidityUnion&&  other_) OMG_NOEXCEPT {
    HumidityUnion tmp(std::move(other_));
    swap(tmp); 
    return *this;
}
#endif
#endif 

HumidityUnion::Union_::Union_() :
    m_shortHumidity_ (0) ,
    m_floatHumidity_ (0.0f)  {
}

HumidityUnion::Union_::Union_(
    int16_t shortHumidity,
    float floatHumidity)
    :
        m_shortHumidity_( shortHumidity ),
        m_floatHumidity_( floatHumidity ) {
}

HumidityUnion::HumidityUnion() :m_d_(default_discriminator())
{
}

void HumidityUnion::swap(HumidityUnion& other_)  OMG_NOEXCEPT 
{
    using std::swap;
    swap (m_d_,other_.m_d_);
    switch(rti::topic::cdr::integer_case(_d())){
        case (Resolution::LOW):
            {  
                swap(m_u_.m_shortHumidity_, other_.m_u_.m_shortHumidity_);
        } break;
        case (Resolution::HIGH):
            {  
                swap(m_u_.m_floatHumidity_, other_.m_u_.m_floatHumidity_);
        } break;

    }
    if (_d() != other_._d()){
        switch(rti::topic::cdr::integer_case(other_._d())){
            case (Resolution::LOW):
                {  
                    swap(m_u_.m_shortHumidity_, other_.m_u_.m_shortHumidity_);
            } break;
            case (Resolution::HIGH):
                {  
                    swap(m_u_.m_floatHumidity_, other_.m_u_.m_floatHumidity_);
            } break;

        }
    }
}  

bool HumidityUnion::operator == (const HumidityUnion& other_) const {
    if (_d() != other_._d()){
        return false;
    }
    switch(rti::topic::cdr::integer_case(_d())){
        case (Resolution::LOW):
            {  
                if ( m_u_.m_shortHumidity_ != other_.m_u_.m_shortHumidity_) {
                    return false;
            }
        } break ;
        case (Resolution::HIGH):
            {  
                if ( m_u_.m_floatHumidity_ != other_.m_u_.m_floatHumidity_) {
                    return false;
            }
        } break ;
    }
    return true;
}
bool HumidityUnion::operator != (const HumidityUnion& other_) const {
    return !this->operator ==(other_);
}

// --- Getters and Setters: -------------------------------------------------
Resolution& HumidityUnion::_d()  {
    return m_d_;
}

const Resolution& HumidityUnion::_d() const  {
    return m_d_;
}

void HumidityUnion::_d(const Resolution& value) {
    m_d_ = value;
}

int16_t& HumidityUnion::shortHumidity()  {
    if ( _d() != (Resolution::LOW)) {
        throw dds::core::PreconditionNotMetError(
            "HumidityUnion::shortHumidity not selected by the discriminator" );
    }
    return m_u_.m_shortHumidity_;
}

const int16_t& HumidityUnion::shortHumidity() const  {
    if ( _d() != (Resolution::LOW)) {
        throw dds::core::PreconditionNotMetError(
            "HumidityUnion::shortHumidity not selected by the discriminator" );
    }
    return m_u_.m_shortHumidity_;
}

void HumidityUnion::shortHumidity(int16_t value) {
    m_u_.m_shortHumidity_ = value;
    m_d_= (Resolution::LOW);
}

float& HumidityUnion::floatHumidity()  {
    if ( _d() != (Resolution::HIGH)) {
        throw dds::core::PreconditionNotMetError(
            "HumidityUnion::floatHumidity not selected by the discriminator" );
    }
    return m_u_.m_floatHumidity_;
}

const float& HumidityUnion::floatHumidity() const  {
    if ( _d() != (Resolution::HIGH)) {
        throw dds::core::PreconditionNotMetError(
            "HumidityUnion::floatHumidity not selected by the discriminator" );
    }
    return m_u_.m_floatHumidity_;
}

void HumidityUnion::floatHumidity(float value) {
    m_u_.m_floatHumidity_ = value;
    m_d_= (Resolution::HIGH);
}

std::ostream& operator << (std::ostream& o,const HumidityUnion& sample)
{
    rti::util::StreamFlagSaver flag_saver (o);
    o <<"[";
    o << "_d: " << sample._d() <<", ";
    switch(rti::topic::cdr::integer_case(sample._d())){
        case (Resolution::LOW):
            {  
                o << "shortHumidity: " << sample.shortHumidity()<<", ";
        } break ;
        case (Resolution::HIGH):
            {  
                o << "floatHumidity: " << std::setprecision(9) <<sample.floatHumidity() ;        } break ;

    }
    o <<"]";
    return o;
}

Resolution HumidityUnion::default_discriminator() {
    return Resolution(static_cast<Resolution::type>(0));
}  

// ---- PercisionCommand: 

PercisionCommand::PercisionCommand() :
    m_requestedResolution_(Resolution::get_default())  {
}   

PercisionCommand::PercisionCommand (
    const Resolution& requestedResolution)
    :
        m_requestedResolution_( requestedResolution ) {
}

#ifdef RTI_CXX11_RVALUE_REFERENCES
#ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
PercisionCommand::PercisionCommand(PercisionCommand&& other_) OMG_NOEXCEPT  :m_requestedResolution_ (std::move(other_.m_requestedResolution_))
{
} 

PercisionCommand& PercisionCommand::operator=(PercisionCommand&&  other_) OMG_NOEXCEPT {
    PercisionCommand tmp(std::move(other_));
    swap(tmp); 
    return *this;
}
#endif
#endif   

void PercisionCommand::swap(PercisionCommand& other_)  OMG_NOEXCEPT 
{
    using std::swap;
    swap(m_requestedResolution_, other_.m_requestedResolution_);
}  

bool PercisionCommand::operator == (const PercisionCommand& other_) const {
    if (m_requestedResolution_ != other_.m_requestedResolution_) {
        return false;
    }
    return true;
}
bool PercisionCommand::operator != (const PercisionCommand& other_) const {
    return !this->operator ==(other_);
}

// --- Getters and Setters: -------------------------------------------------
Resolution& PercisionCommand::requestedResolution() OMG_NOEXCEPT {
    return m_requestedResolution_;
}

const Resolution& PercisionCommand::requestedResolution() const OMG_NOEXCEPT {
    return m_requestedResolution_;
}

void PercisionCommand::requestedResolution(const Resolution& value) {
    m_requestedResolution_ = value;
}

std::ostream& operator << (std::ostream& o,const PercisionCommand& sample)
{
    rti::util::StreamFlagSaver flag_saver (o);
    o <<"[";
    o << "requestedResolution: " << sample.requestedResolution() ;
    o <<"]";
    return o;
}

// ---- HumidityInfo: 

HumidityInfo::HumidityInfo()  {
}   

HumidityInfo::HumidityInfo (
    const HumidityUnion& humidity)
    :
        m_humidity_( humidity ) {
}

#ifdef RTI_CXX11_RVALUE_REFERENCES
#ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
HumidityInfo::HumidityInfo(HumidityInfo&& other_) OMG_NOEXCEPT  :m_humidity_ (std::move(other_.m_humidity_))
{
} 

HumidityInfo& HumidityInfo::operator=(HumidityInfo&&  other_) OMG_NOEXCEPT {
    HumidityInfo tmp(std::move(other_));
    swap(tmp); 
    return *this;
}
#endif
#endif   

void HumidityInfo::swap(HumidityInfo& other_)  OMG_NOEXCEPT 
{
    using std::swap;
    swap(m_humidity_, other_.m_humidity_);
}  

bool HumidityInfo::operator == (const HumidityInfo& other_) const {
    if (m_humidity_ != other_.m_humidity_) {
        return false;
    }
    return true;
}
bool HumidityInfo::operator != (const HumidityInfo& other_) const {
    return !this->operator ==(other_);
}

// --- Getters and Setters: -------------------------------------------------
HumidityUnion& HumidityInfo::humidity() OMG_NOEXCEPT {
    return m_humidity_;
}

const HumidityUnion& HumidityInfo::humidity() const OMG_NOEXCEPT {
    return m_humidity_;
}

void HumidityInfo::humidity(const HumidityUnion& value) {
    m_humidity_ = value;
}

std::ostream& operator << (std::ostream& o,const HumidityInfo& sample)
{
    rti::util::StreamFlagSaver flag_saver (o);
    o <<"[";
    o << "humidity: " << sample.humidity() ;
    o <<"]";
    return o;
}

// --- Type traits: -------------------------------------------------

namespace rti { 
    namespace topic {

        template<>
        struct native_type_code<Resolution> {
            static DDS_TypeCode * get()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member Resolution_g_tc_members[2]=
                {

                    {
                        (char *)"LOW",/* Member name */
                        {
                            0, /* Ignored */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        Resolution::LOW, 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL/* Ignored */
                    }, 
                    {
                        (char *)"HIGH",/* Member name */
                        {
                            0, /* Ignored */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        Resolution::HIGH, 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL/* Ignored */
                    }
                };

                static DDS_TypeCode Resolution_g_tc =
                {{
                        DDS_TK_ENUM,/* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"Resolution", /* Name */
                        NULL,     /* Base class type code is assigned later */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        2, /* Number of members */
                        Resolution_g_tc_members, /* Members */
                        DDS_VM_NONE   /* Type Modifier */        
                    }}; /* Type code for Resolution*/

                if (is_initialized) {
                    return &Resolution_g_tc;
                }

                is_initialized = RTI_TRUE;

                return &Resolution_g_tc;
            }
        }; // native_type_code

        const dds::core::xtypes::EnumType& dynamic_type<Resolution>::get()
        {
            return static_cast<const dds::core::xtypes::EnumType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<Resolution>::get())));
        }

        template<>
        struct native_type_code<HumidityUnion> {
            static DDS_TypeCode * get()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member HumidityUnion_g_tc_members[2]=
                {

                    {
                        (char *)"shortHumidity",/* Member name */
                        {
                            1,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        1, /* Number of labels */
                        (Resolution::LOW), /* First label cpp03stl (Resolution::LOW) */
                        NULL, /* Labels (it is NULL when there is only one label)*/
                        RTI_CDR_NONKEY_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }, 
                    {
                        (char *)"floatHumidity",/* Member name */
                        {
                            2,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        1, /* Number of labels */
                        (Resolution::HIGH), /* First label cpp03stl (Resolution::HIGH) */
                        NULL, /* Labels (it is NULL when there is only one label)*/
                        RTI_CDR_NONKEY_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }
                };

                static DDS_TypeCode HumidityUnion_g_tc =
                {{
                        DDS_TK_UNION,/* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"HumidityUnion", /* Name */
                        NULL,     /* Base class type code is assigned later */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        2, /* Number of members */
                        HumidityUnion_g_tc_members, /* Members */
                        DDS_VM_NONE   /* Type Modifier */        
                    }}; /* Type code for HumidityUnion*/

                if (is_initialized) {
                    return &HumidityUnion_g_tc;
                }

                HumidityUnion_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_short;

                HumidityUnion_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

                /* Discriminator type code */
                HumidityUnion_g_tc._data._typeCode = (RTICdrTypeCode *)&rti::topic::dynamic_type< Resolution>::get().native();

                is_initialized = RTI_TRUE;

                return &HumidityUnion_g_tc;
            }
        }; // native_type_code

        const dds::core::xtypes::UnionType& dynamic_type<HumidityUnion>::get()
        {
            return static_cast<const dds::core::xtypes::UnionType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<HumidityUnion>::get())));
        }

        template<>
        struct native_type_code<PercisionCommand> {
            static DDS_TypeCode * get()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member PercisionCommand_g_tc_members[1]=
                {

                    {
                        (char *)"requestedResolution",/* Member name */
                        {
                            0,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }
                };

                static DDS_TypeCode PercisionCommand_g_tc =
                {{
                        DDS_TK_STRUCT,/* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"PercisionCommand", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        PercisionCommand_g_tc_members, /* Members */
                        DDS_VM_NONE  /* Ignored */         
                    }}; /* Type code for PercisionCommand*/

                if (is_initialized) {
                    return &PercisionCommand_g_tc;
                }

                PercisionCommand_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&rti::topic::dynamic_type< Resolution>::get().native();

                is_initialized = RTI_TRUE;

                return &PercisionCommand_g_tc;
            }
        }; // native_type_code

        const dds::core::xtypes::StructType& dynamic_type<PercisionCommand>::get()
        {
            return static_cast<const dds::core::xtypes::StructType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<PercisionCommand>::get())));
        }

        template<>
        struct native_type_code<HumidityInfo> {
            static DDS_TypeCode * get()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member HumidityInfo_g_tc_members[1]=
                {

                    {
                        (char *)"humidity",/* Member name */
                        {
                            0,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }
                };

                static DDS_TypeCode HumidityInfo_g_tc =
                {{
                        DDS_TK_STRUCT,/* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"HumidityInfo", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        HumidityInfo_g_tc_members, /* Members */
                        DDS_VM_NONE  /* Ignored */         
                    }}; /* Type code for HumidityInfo*/

                if (is_initialized) {
                    return &HumidityInfo_g_tc;
                }

                HumidityInfo_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&rti::topic::dynamic_type< HumidityUnion>::get().native();

                is_initialized = RTI_TRUE;

                return &HumidityInfo_g_tc;
            }
        }; // native_type_code

        const dds::core::xtypes::StructType& dynamic_type<HumidityInfo>::get()
        {
            return static_cast<const dds::core::xtypes::StructType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<HumidityInfo>::get())));
        }

    }
}  

namespace dds { 
    namespace topic {
        void topic_type_support<HumidityUnion>:: register_type(
            dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            rti::domain::register_type_plugin(
                participant,
                type_name,
                HumidityUnionPlugin_new,
                HumidityUnionPlugin_delete);
        }

        std::vector<char>& topic_type_support<HumidityUnion>::to_cdr_buffer(
            std::vector<char>& buffer, const HumidityUnion& sample)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = HumidityUnionPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = HumidityUnionPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support<HumidityUnion>::from_cdr_buffer(HumidityUnion& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = HumidityUnionPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create HumidityUnion from cdr buffer");
        }

        void topic_type_support<HumidityUnion>::reset_sample(HumidityUnion& sample) 
        {
            sample._d() = (Resolution::LOW);
            rti::topic::reset_sample(sample.shortHumidity());
            sample._d() = (Resolution::HIGH);
            rti::topic::reset_sample(sample.floatHumidity());

            sample._d() = HumidityUnion::default_discriminator();
        }

        void topic_type_support<HumidityUnion>::allocate_sample(HumidityUnion& sample, int, int) 
        {

            sample._d() = HumidityUnion::default_discriminator();
        }

        void topic_type_support<PercisionCommand>:: register_type(
            dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            rti::domain::register_type_plugin(
                participant,
                type_name,
                PercisionCommandPlugin_new,
                PercisionCommandPlugin_delete);
        }

        std::vector<char>& topic_type_support<PercisionCommand>::to_cdr_buffer(
            std::vector<char>& buffer, const PercisionCommand& sample)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = PercisionCommandPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = PercisionCommandPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support<PercisionCommand>::from_cdr_buffer(PercisionCommand& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = PercisionCommandPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create PercisionCommand from cdr buffer");
        }

        void topic_type_support<PercisionCommand>::reset_sample(PercisionCommand& sample) 
        {
            rti::topic::reset_sample(sample.requestedResolution());
        }

        void topic_type_support<PercisionCommand>::allocate_sample(PercisionCommand& sample, int, int) 
        {
            rti::topic::allocate_sample(sample.requestedResolution(),  -1, -1);
        }

        void topic_type_support<HumidityInfo>:: register_type(
            dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            rti::domain::register_type_plugin(
                participant,
                type_name,
                HumidityInfoPlugin_new,
                HumidityInfoPlugin_delete);
        }

        std::vector<char>& topic_type_support<HumidityInfo>::to_cdr_buffer(
            std::vector<char>& buffer, const HumidityInfo& sample)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = HumidityInfoPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = HumidityInfoPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support<HumidityInfo>::from_cdr_buffer(HumidityInfo& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = HumidityInfoPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create HumidityInfo from cdr buffer");
        }

        void topic_type_support<HumidityInfo>::reset_sample(HumidityInfo& sample) 
        {
            rti::topic::reset_sample(sample.humidity());
        }

        void topic_type_support<HumidityInfo>::allocate_sample(HumidityInfo& sample, int, int) 
        {
            rti::topic::allocate_sample(sample.humidity(),  -1, -1);
        }

    }
}  

