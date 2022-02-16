//
// Created by Daniel Adams on 2/11/2022.
//

#ifndef WOLVIC_HANDDELEGATE_H
#define WOLVIC_HANDDELEGATE_H

#include "vrb/MacroUtils.h"
#include "vrb/Forward.h"
#include "Device.h"

#include <memory>
#include <string>

namespace crow {
class HandDelegate;
typedef std::shared_ptr<HandDelegate> HandDelegatePtr;

class HandDelegate {
public:
    virtual void CreateHand(const int32_t aHandIndex, const int32_t aModelIndex, const std::string& aImmersiveName) = 0;
    virtual void CreateHand(const int32_t aHandIndex, const int32_t aModelIndex, const std::string& aImmersiveName, const vrb::Matrix& aBeamTransform) = 0;
    virtual void SetImmersiveBeamTransform(const int32_t aHandIndex, const vrb::Matrix& aImmersiveBeamTransform) = 0;
    virtual void SetBeamTransform(const int32_t aHandIndex, const vrb::Matrix& aBeamTransform) = 0;
    virtual void SetFocused(const int32_t aHandIndex) = 0;
    virtual void DestroyHand(const int32_t aHandIndex) = 0;
    virtual void SetCapabilityFlags(const int32_t aHandIndex, const device::CapabilityFlags aFlags) = 0;
    virtual void SetEnabled(const int32_t aHandIndex, const bool aEnabled) = 0;
    virtual void SetTransform(const int32_t aHandIndex, const vrb::Matrix& aTransform) = 0;
    virtual void SetSelectActionStart(const int32_t aHandIndex) = 0;
    virtual void SetSelectActionStop(const int32_t aHandIndex) = 0;
    virtual bool IsVisible() const = 0;
    virtual void SetVisible(const bool aVisible) = 0;

protected:
    HandDelegate() {}
private:
    VRB_NO_DEFAULTS(HandDelegate)
};
}

#endif //WOLVIC_HANDDELEGATE_H
