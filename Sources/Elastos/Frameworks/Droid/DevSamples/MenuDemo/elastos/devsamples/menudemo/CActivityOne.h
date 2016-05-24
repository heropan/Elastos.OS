
#ifndef __Elastos_DevSamples_MenuDemo_CActivityOne_H__
#define __Elastos_DevSamples_MenuDemo_CActivityOne_H__

#include <elastos/droid/app/Activity.h>
#include "_Elastos_DevSamples_MenuDemo_CActivityOne.h"

using Elastos::Droid::App::Activity;
using Elastos::Droid::View::IMenu;
using Elastos::Droid::View::IMenuItem;

namespace Elastos {
namespace DevSamples {
namespace MenuDemo {

CarClass(CActivityOne)
    , public Activity
{
public:
    CAR_OBJECT_DECL()

    CARAPI constructor();

protected:

    CARAPI OnCreate(
        /* [in] */ IBundle* savedInstanceState);

    CARAPI OnStart();

    CARAPI OnResume();

    CARAPI OnPause();

    CARAPI OnStop();

    CARAPI OnDestroy();

private:
    CARAPI OnActivityResult(
        /* [in] */ Int32 requestCode,
        /* [in] */ Int32 resultCode,
        /* [in] */ IIntent *data);

    CARAPI OnCreateOptionsMenu(
        /* [in] */ IMenu* menu,
        /* [out] */ Boolean* allowToShow);

    CARAPI OnOptionsItemSelected(
        /* [in] */ IMenuItem* item,
        /* [out] */ Boolean* result);

private:
};

} // namespace MenuDemo
} // namespace DevSamples
} // namespace Elastos

#endif // __Elastos_DevSamples_MenuDemo_CActivityOne_H__