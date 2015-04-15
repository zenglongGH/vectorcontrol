/*
 * UAVCAN data structure definition for libuavcan.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /mnt/hgfs/workspace/uavcan/dsdl/uavcan/protocol/560.EnumerationRequest.uavcan
 */

#ifndef UAVCAN_PROTOCOL_ENUMERATIONREQUEST_HPP_INCLUDED
#define UAVCAN_PROTOCOL_ENUMERATIONREQUEST_HPP_INCLUDED

#include <uavcan/build_config.hpp>
#include <uavcan/node/global_data_type_registry.hpp>
#include <uavcan/marshal/types.hpp>

/******************************* Source text **********************************
#
# Automated enumeration request; designed for broadcast transfers only.
#
# If the node supports direct input from the user (e.g. a button), it can be used for automated Node ID assignment:
#
#  1. The node subscribes to this message (normally this happens while the node is in passive mode, but that's
#     not necessary). In many cases it might be wise to subscribe to this message automatically if Node ID is not
#     yet assigned (for instance if the node is not configured yet).
#
#  2. Some configuration tool or other node (let's call it master node) selects an appropriate Node ID and
#     broadcasts it via this message.
#
#  3. User performs a confirmation input on the node that is being configured (e.g. pressing a button).
#
#  4. The node saves the newly assigned Node ID and begins normal operation (possibly restarts).
#
#  5. The master node makes sure that the node with the specified Node ID is now online. If it is not, it waits till
#     the timeout expires and asks the user to repeat the procedure.
#
# An example use case for this feature is enumeration of actuator nodes or multiple motor controller nodes.
#

uint8 TIMEOUT_INFINITE = 0
uint8 timeout_sec    # If the confirmation input was not detected in this time, enumeration request will be aborted

uint7 node_id        # This Node ID will be assigned if the confirmation input has been detected. Must be valid.
******************************************************************************/

/********************* DSDL signature source definition ***********************
uavcan.protocol.EnumerationRequest
saturated uint8 timeout_sec
saturated uint7 node_id
******************************************************************************/

#undef timeout_sec
#undef node_id
#undef TIMEOUT_INFINITE

#ifndef UAVCAN_PACK_STRUCTS
# error UAVCAN_PACK_STRUCTS
#endif

namespace uavcan
{
namespace protocol
{

#if UAVCAN_PACK_STRUCTS
UAVCAN_PACKED_BEGIN
#endif

template <int _tmpl>
struct UAVCAN_EXPORT EnumerationRequest_
{
    typedef const EnumerationRequest_<_tmpl>& ParameterType;
    typedef EnumerationRequest_<_tmpl>& ReferenceType;

    struct ConstantTypes
    {
        typedef ::uavcan::IntegerSpec< 8, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > TIMEOUT_INFINITE;
    };

    struct FieldTypes
    {
        typedef ::uavcan::IntegerSpec< 8, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > timeout_sec;
        typedef ::uavcan::IntegerSpec< 7, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > node_id;
    };

    enum
    {
        MinBitLen
            = FieldTypes::timeout_sec::MinBitLen
            + FieldTypes::node_id::MinBitLen
    };

    enum
    {
        MaxBitLen
            = FieldTypes::timeout_sec::MaxBitLen
            + FieldTypes::node_id::MaxBitLen
    };

    // Constants
    static const typename ::uavcan::StorageType< typename ConstantTypes::TIMEOUT_INFINITE >::Type TIMEOUT_INFINITE; // 0

    // Fields
    typename ::uavcan::StorageType< typename FieldTypes::timeout_sec >::Type timeout_sec;
    typename ::uavcan::StorageType< typename FieldTypes::node_id >::Type node_id;

    EnumerationRequest_()
        : timeout_sec()
        , node_id()
    {
        enum { MaxByteLen = ::uavcan::BitLenToByteLen<MaxBitLen>::Result };
        ::uavcan::StaticAssert<int(MaxByteLen) <= int(::uavcan::MaxTransferPayloadLen)>::check();

        ::uavcan::StaticAssert<_tmpl == 0>::check();  // Usage check

#if UAVCAN_DEBUG
        /*
         * Cross-checking MaxBitLen provided by the DSDL compiler.
         * This check shall never be performed in user code because MaxBitLen value
         * actually depends on the nested types, thus it is not invariant.
         */
        ::uavcan::StaticAssert<15 == MaxBitLen>::check();
#endif
    }

    bool operator==(ParameterType rhs) const;
    bool operator!=(ParameterType rhs) const { return !operator==(rhs); }

    /**
     * This comparison is based on @ref uavcan::areClose(), which ensures proper comparison of
     * floating point fields at any depth.
     */
    bool isClose(ParameterType rhs) const;

    static int encode(ParameterType self, ::uavcan::ScalarCodec& codec,
                      ::uavcan::TailArrayOptimizationMode tao_mode = ::uavcan::TailArrayOptEnabled);

    static int decode(ReferenceType self, ::uavcan::ScalarCodec& codec,
                      ::uavcan::TailArrayOptimizationMode tao_mode = ::uavcan::TailArrayOptEnabled);

    /*
     * Static type info
     */
    enum { DataTypeKind = ::uavcan::DataTypeKindMessage };
    enum { DefaultDataTypeID = 560 };

    static const char* getDataTypeFullName()
    {
        return "uavcan.protocol.EnumerationRequest";
    }

    static void extendDataTypeSignature(::uavcan::DataTypeSignature& signature)
    {
        signature.extend(getDataTypeSignature());
    }

    static ::uavcan::DataTypeSignature getDataTypeSignature();

};

#if UAVCAN_PACK_STRUCTS
UAVCAN_PACKED_END
#endif

/*
 * Out of line struct method definitions
 */

template <int _tmpl>
bool EnumerationRequest_<_tmpl>::operator==(ParameterType rhs) const
{
    return
        timeout_sec == rhs.timeout_sec &&
        node_id == rhs.node_id;
}

template <int _tmpl>
bool EnumerationRequest_<_tmpl>::isClose(ParameterType rhs) const
{
    return
        ::uavcan::areClose(timeout_sec, rhs.timeout_sec) &&
        ::uavcan::areClose(node_id, rhs.node_id);
}

template <int _tmpl>
int EnumerationRequest_<_tmpl>::encode(ParameterType self, ::uavcan::ScalarCodec& codec,
    ::uavcan::TailArrayOptimizationMode tao_mode)
{
    (void)self;
    (void)codec;
    (void)tao_mode;
    int res = 1;
    res = FieldTypes::timeout_sec::encode(self.timeout_sec, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::node_id::encode(self.node_id, codec,  tao_mode);
    return res;
}

template <int _tmpl>
int EnumerationRequest_<_tmpl>::decode(ReferenceType self, ::uavcan::ScalarCodec& codec,
    ::uavcan::TailArrayOptimizationMode tao_mode)
{
    (void)self;
    (void)codec;
    (void)tao_mode;
    int res = 1;
    res = FieldTypes::timeout_sec::decode(self.timeout_sec, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::node_id::decode(self.node_id, codec,  tao_mode);
    return res;
}

/*
 * Out of line type method definitions
 */
template <int _tmpl>
::uavcan::DataTypeSignature EnumerationRequest_<_tmpl>::getDataTypeSignature()
{
    ::uavcan::DataTypeSignature signature(0x1BCD97C781C0DFA1ULL);

    FieldTypes::timeout_sec::extendDataTypeSignature(signature);
    FieldTypes::node_id::extendDataTypeSignature(signature);

    return signature;
}

/*
 * Out of line constant definitions
 */

template <int _tmpl>
const typename ::uavcan::StorageType< typename EnumerationRequest_<_tmpl>::ConstantTypes::TIMEOUT_INFINITE >::Type
    EnumerationRequest_<_tmpl>::TIMEOUT_INFINITE = 0U; // 0

/*
 * Final typedef
 */
typedef EnumerationRequest_<0> EnumerationRequest;

namespace
{

const ::uavcan::DefaultDataTypeRegistrator< ::uavcan::protocol::EnumerationRequest > _uavcan_gdtr_registrator_EnumerationRequest;

}

} // Namespace uavcan
} // Namespace protocol

/*
 * YAML streamer specialization
 */
namespace uavcan
{

template <>
class UAVCAN_EXPORT YamlStreamer< ::uavcan::protocol::EnumerationRequest >
{
public:
    template <typename Stream>
    static void stream(Stream& s, ::uavcan::protocol::EnumerationRequest::ParameterType obj, const int level);
};

template <typename Stream>
void YamlStreamer< ::uavcan::protocol::EnumerationRequest >::stream(Stream& s, ::uavcan::protocol::EnumerationRequest::ParameterType obj, const int level)
{
    (void)s;
    (void)obj;
    (void)level;
    if (level > 0)
    {
        s << '\n';
        for (int pos = 0; pos < level; pos++)
        {
            s << "  ";
        }
    }
    s << "timeout_sec: ";
    YamlStreamer< ::uavcan::protocol::EnumerationRequest::FieldTypes::timeout_sec >::stream(s, obj.timeout_sec, level + 1);
    s << '\n';
    for (int pos = 0; pos < level; pos++)
    {
        s << "  ";
    }
    s << "node_id: ";
    YamlStreamer< ::uavcan::protocol::EnumerationRequest::FieldTypes::node_id >::stream(s, obj.node_id, level + 1);
}

}

namespace uavcan
{
namespace protocol
{

template <typename Stream>
inline Stream& operator<<(Stream& s, ::uavcan::protocol::EnumerationRequest::ParameterType obj)
{
    ::uavcan::YamlStreamer< ::uavcan::protocol::EnumerationRequest >::stream(s, obj, 0);
    return s;
}

}
}

#endif // UAVCAN_PROTOCOL_ENUMERATIONREQUEST_HPP_INCLUDED