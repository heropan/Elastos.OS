#ifndef __CAR_BRIDGE_WEAK_EXTERNAL_BASE_H
# define __CAR_BRIDGE_WEAK_EXTERNAL_BASE_H

# include <node.h>

# include <nan.h>

# include "macros.h"



CAR_BRIDGE_NAMESPACE_BEGIN

class WeakExternalBase {
public:
    template<class WeakExternal>
    static void Delete(WeakExternal *weakExternal)
    {
        delete static_cast<WeakExternalBase *>(weakExternal);
    }

    WeakExternalBase(void)
    {
        ::Nan::HandleScope scope;

        _self.Reset(::Nan::New<::v8::External>(this));
        _self.SetWeak(this, &WeakCallback, ::Nan::WeakCallbackType::kParameter);
    }

    void Delete(void)
    {
        delete this;
    }

    ::v8::Local<::v8::External> self() const
    {
        return ::Nan::New(_self);
    }

protected:
    virtual ~WeakExternalBase()
    {
        _self.Reset();
    }

private:
    ::Nan::Persistent<::v8::External> _self;

    static void WeakCallback(::Nan::WeakCallbackInfo<WeakExternalBase> const &data)
    {
        WeakExternalBase *weakHeapExternal;

        weakHeapExternal = data.GetParameter();

        delete weakHeapExternal;
    }

    WeakExternalBase(WeakExternalBase const &weakHeapExternal) = delete;

    WeakExternalBase(WeakExternalBase &&weakHeapExternal) = delete;

    WeakExternalBase &operator=(WeakExternalBase const &weakHeapExternal) = delete;

    WeakExternalBase &operator=(WeakExternalBase &&weakHeapExternal) = delete;
};

CAR_BRIDGE_NAMESPACE_END

#endif
