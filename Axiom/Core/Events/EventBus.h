#pragma once

#include <entt/signal/dispatcher.hpp>

#include <utility>

class EventBus
{
public:
    template<typename Event>
    static void Trigger(Event&& event)
    {
        s_Dispatcher.trigger(std::forward<Event>(event));
    }

    template<typename Event>
    static void Enqueue(Event&& event)
    {
        s_Dispatcher.enqueue(std::forward<Event>(event));
    }

    static void Update()
    {
        s_Dispatcher.update();
    }

    template<typename Event>
    static auto Sink()
    {
        return s_Dispatcher.sink<Event>();
    }

private:
    inline static entt::dispatcher s_Dispatcher{};
};
