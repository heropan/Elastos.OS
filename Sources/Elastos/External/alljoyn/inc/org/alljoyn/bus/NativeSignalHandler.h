
#ifndef __ORG_ALLJOYN_BUS_NATIVESIGNALHANDLER_H__
#define __ORG_ALLJOYN_BUS_NATIVESIGNALHANDLER_H__

#include "_Org.Alljoyn.Bus.h"
#include <alljoyn/BusAttachment.h>
#include <alljoyn/InterfaceDescription.h>
#include <alljoyn/MessageReceiver.h>

namespace Org {
namespace Alljoyn {
namespace Bus {

class NativeSignalHandler : public ajn::MessageReceiver
{
public:
    NativeSignalHandler(
        /* [in] */ IInterface* obj,
        /* [in] */ IMethodInfo* method);

    virtual ~NativeSignalHandler();

    Boolean IsSameObject(
        /* [in] */ IInterface* obj,
        /* [in] */ IMethodInfo* method);

    virtual QStatus Register(
        /* [in] */ ajn::BusAttachment& bus,
        /* [in] */ const char* ifaceName,
        /* [in] */ const char* signalName,
        /* [in] */ const char* ancillary);

    virtual void Unregister(
        /* [in] */ ajn::BusAttachment& bus) = 0;

    void SignalHandler(
        /* [in] */ const ajn::InterfaceDescription::Member* member,
        /* [in] */ const char* sourcePath,
        /* [in] */ ajn::Message& msg);

private:
    NativeSignalHandler(const NativeSignalHandler& other);
    NativeSignalHandler& operator =(const NativeSignalHandler& other);

protected:
    AutoPtr<IWeakReference> mSignalHandler;
    AutoPtr<IMethodInfo> mMethod;
    const ajn::InterfaceDescription::Member* mMember;
    qcc::String mAncillaryData; /* can be both source or matchRule; */
};

class NativeSignalHandlerWithSrc
    : public NativeSignalHandler
{
public:
    NativeSignalHandlerWithSrc(
        /* [in] */ IInterface* obj,
        /* [in] */ IMethodInfo* method)
        : NativeSignalHandler(obj, method)
    { }

    virtual QStatus Register(
        /* [in] */ ajn::BusAttachment& bus,
        /* [in] */ const char* ifaceName,
        /* [in] */ const char* signalName,
        /* [in] */ const char* ancillary);

private:
    NativeSignalHandlerWithSrc(const NativeSignalHandlerWithSrc& other);
    NativeSignalHandlerWithSrc& operator =(const NativeSignalHandlerWithSrc& other);

    void Unregister(
        /* [in] */ ajn::BusAttachment& bus);
};

class NativeSignalHandlerWithRule
    : public NativeSignalHandler
{
public:
    NativeSignalHandlerWithRule(
        /* [in] */ IInterface* obj,
        /* [in] */ IMethodInfo* method)
        : NativeSignalHandler(obj, method)
    {}

    virtual QStatus Register(
        /* [in] */ ajn::BusAttachment& bus,
        /* [in] */ const char* ifaceName,
        /* [in] */ const char* signalName,
        /* [in] */ const char* ancillary);

private:
    NativeSignalHandlerWithRule(const NativeSignalHandlerWithRule& other);
    NativeSignalHandlerWithRule& operator =(const NativeSignalHandlerWithRule& other);

    void Unregister(
        /* [in] */ ajn::BusAttachment& bus);
};


} // namespace Bus
} // namespace Alljoyn
} // namespace Org

#endif // __ORG_ALLJOYN_BUS_NATIVESIGNALHANDLER_H__
