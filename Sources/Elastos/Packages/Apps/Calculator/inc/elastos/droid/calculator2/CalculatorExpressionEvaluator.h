#ifndef _ELASTOS_DROID_CALCULATOR2_CALCULATOREXPRESSIONEVALUATOR_H__
#define _ELASTOS_DROID_CALCULATOR2_CALCULATOREXPRESSIONEVALUATOR_H__

#include "_Elastos.Droid.Calculator2.h"
#include <_Org.Javia.Arity.h>
#include <elastos/core/Object.h>
#include <elastos/droid/ext/frameworkext.h>

using Elastos::Core::ICharSequence;
using Org::Javia::Arity::ISymbols;

namespace Elastos {
namespace Droid {
namespace Calculator2 {

class CalculatorExpressionEvaluator
    : public Object
    , public ICalculatorExpressionEvaluator
{
public:
    CalculatorExpressionEvaluator();

    ~CalculatorExpressionEvaluator();

    CAR_INTERFACE_DECL()

    CARAPI constructor(
        /* [in] */ ICalculatorExpressionTokenizer* tokenizer);

    CARAPI Evaluate(
        /* [in] */ ICharSequence* expr,
        /* [in] */ IEvaluateCallback* callback);

    CARAPI Evaluate(
        /* [in] */ const String& expr,
        /* [in] */ IEvaluateCallback* callback);

private:
    static const Int32 MAX_DIGITS;
    static const Int32 ROUNDING_DIGITS;

    AutoPtr<ISymbols> mSymbols;
    AutoPtr<ICalculatorExpressionTokenizer> mTokenizer;
};

} // namespace Calculator2
} // namespace Droid
} // namespace Elastos

#endif // _ELASTOS_DROID_CALCULATOR2_CALCULATOREXPRESSIONEVALUATOR_H__