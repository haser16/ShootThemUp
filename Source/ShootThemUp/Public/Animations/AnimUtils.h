#pragma once

class AnimUtils
{
public:
    template <typename T>
    static T *FindNotifyByClass(UAnimSequenceBase *Animation)
    {
        if (!Animation)
            return nullptr;

        const auto NotifyEvents = Animation->Notifies;
        for (auto NotifyEvent : NotifyEvents)
        {
            auto AnimNotifi = Cast<T>(NotifyEvent.Notify);
            if (AnimNotifi)
            {
                return AnimNotifi;
            }
        }
        return nullptr;
    }
};
