//=========================================================================
// Copyright (C) 2012 The Elastos Open Source Project
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//=========================================================================

#ifndef __ELASTOS_DROID_TELECOM_PARCELABLECALL_H__
#define __ELASTOS_DROID_TELECOM_PARCELABLECALL_H__

#include <Elastos.CoreLibrary.Utility.h>
#include "Elastos.Droid.Net.h"
#include "Elastos.Droid.Os.h"
#include "Elastos.Droid.Telecom.h"
#include <elastos/core/Object.h>

using Elastos::Droid::Internal::Telecom::IIVideoProvider;
using Elastos::Droid::Net::IUri;
using Elastos::Droid::Os::IBundle;
using Elastos::Core::Object;
using Elastos::Utility::IList;

namespace Elastos {
namespace Droid {
namespace Telecom {

/**
 * Information about a call that is used between InCallService and Telecom.
 * @hide
 */
class ParcelableCall
    : public Object
    , public IParcelableCall
    , public IParcelable
{
public:
    CAR_INTERFACE_DECL()

    ParcelableCall();

    CARAPI constructor();

    CARAPI constructor(
        /* [in] */ const String& id,
        /* [in] */ Int32 state,
        /* [in] */ IDisconnectCause* disconnectCause,
        /* [in] */ IList* cannedSmsResponses,
        /* [in] */ Int32 capabilities,
        /* [in] */ Int32 properties,
        /* [in] */ Int64 createTimeMillis,
        /* [in] */ Int64 connectTimeMillis,
        /* [in] */ IUri* handle,
        /* [in] */ Int32 handlePresentation,
        /* [in] */ const String& callerDisplayName,
        /* [in] */ Int32 callerDisplayNamePresentation,
        /* [in] */ IGatewayInfo* gatewayInfo,
        /* [in] */ IPhoneAccountHandle* accountHandle,
        /* [in] */ IIVideoProvider* videoCallProvider,
        /* [in] */ const String& parentCallId,
        /* [in] */ IList* childCallIds,
        /* [in] */ IStatusHints* statusHints,
        /* [in] */ Int32 videoState,
        /* [in] */ IList* conferenceableCallIds,
        /* [in] */ IBundle* extras,
        /* [in] */ Boolean isActiveSub,
        /* [in] */ Int32 callSubstate);



    /** The unique ID of the call. */
    CARAPI GetId(
        /* [out] */ String* result);

    /** The current state of the call. */
    CARAPI GetState(
        /* [out] */ Int32* result);

    /**
     * Reason for disconnection, as described by {@link android.telecomm.DisconnectCause}. Valid
     * when call state is {@link CallState#DISCONNECTED}.
     */
    CARAPI GetDisconnectCause(
        /* [out] */ IDisconnectCause** result);

    /**
     * The set of possible text message responses when this call is incoming.
     */
    CARAPI GetCannedSmsResponses(
        /* [out] */ IList** result);

    // Bit mask of actions a call supports, values are defined in {@link CallCapabilities}.
    CARAPI GetCapabilities(
        /* [out] */ Int32* result);

    /** Bitmask of properties of the call. */
    CARAPI GetProperties(
        /* [out] */ Int32* result);

    CARAPI GetCreateTimeMillis(
        /* [out] */ Int64* result);

    /** The time that the call switched to the active state. */
    CARAPI GetConnectTimeMillis(
        /* [out] */ Int64* result);

    /** The endpoint to which the call is connected. */
    CARAPI GetHandle(
        /* [out] */ IUri** result);

    /**
     * The presentation requirements for the handle. See {@link TelecomManager} for valid values.
     */
    CARAPI GetHandlePresentation(
        /* [out] */ Int32* result);

    /** The endpoint to which the call is connected. */
    CARAPI GetCallerDisplayName(
        /* [out] */ String* result);

    /**
     * The presentation requirements for the caller display name.
     * See {@link TelecomManager} for valid values.
     */
    CARAPI GetCallerDisplayNamePresentation(
        /* [out] */ Int32* result);

    /** Gateway information for the call. */
    CARAPI GetGatewayInfo(
        /* [out] */ IGatewayInfo** result);

    /** PhoneAccountHandle information for the call. */
    CARAPI GetAccountHandle(
        /* [out] */ IPhoneAccountHandle** result);

    /**
     * Returns an object for remotely communicating through the video call provider's binder.
     * @return The video call.
     */
    CARAPI GetVideoCall(
        /* [out] */ IInCallServiceVideoCall** result);

    /**
     * The conference call to which this call is conferenced. Null if not conferenced.
     */
    CARAPI GetParentCallId(
        /* [out] */ String* result);

    /**
     * The child call-IDs if this call is a conference call. Returns an empty list if this is not
     * a conference call or if the conference call contains no children.
     */
    CARAPI GetChildCallIds(
        /* [out] */ IList** result);

    CARAPI GetConferenceableCallIds(
        /* [out] */ IList** result);

    /**
     * The status label and icon.
     *
     * @return Status hints.
     */
    CARAPI GetStatusHints(
        /* [out] */ IStatusHints** result);

    /**
     * The video state.
     * @return The video state of the call.
     */
    CARAPI GetVideoState(
        /* [out] */ Int32* result);

    /**
     * Any extras to pass with the call
     *
     * @return a bundle of extras
     */
    CARAPI GetExtras(
        /* [out] */ IBundle** result);

    CARAPI GetIsActiveSub(
        /* [out] */ Boolean* result);

    CARAPI GetCallSubstate(
        /* [out] */ Int32* result);

    CARAPI ReadFromParcel(
        /* [in] */ IParcel* source);

    /** Writes ParcelableCall object into a Parcel. */
    CARAPI WriteToParcel(
        /* [in] */ IParcel* destination);

    CARAPI ToString(
        /* [out] */ String* result);

private:
    String mId;
    Int32 mState;
    AutoPtr<IDisconnectCause> mDisconnectCause;
    AutoPtr<IList> mCannedSmsResponses;
    Int32 mCapabilities;
    Int32 mProperties;
    Int64 mCreateTimeMillis;
    Int64 mConnectTimeMillis;
    AutoPtr<IUri> mHandle;
    Int32 mHandlePresentation;
    String mCallerDisplayName;
    Int32 mCallerDisplayNamePresentation;
    AutoPtr<IGatewayInfo> mGatewayInfo;
    AutoPtr<IPhoneAccountHandle> mAccountHandle;
    AutoPtr<IIVideoProvider> mVideoCallProvider;
    AutoPtr<IInCallServiceVideoCall> mVideoCall;
    String mParentCallId;
    AutoPtr<IList> mChildCallIds;
    AutoPtr<IStatusHints> mStatusHints;
    Int32 mVideoState;
    AutoPtr<IList> mConferenceableCallIds;
    AutoPtr<IBundle> mExtras;
    Boolean mIsActiveSub;
    Int32 mCallSubstate;
};

} // namespace Telecom
} // namespace Droid
} // namespace Elastos

#endif //__ELASTOS_DROID_TELECOM_PARCELABLECALL_H__
