#ifndef _CORE_LAYER_H
#define _CORE_LAYER_H

namespace Core
{
    class Layer
    {
    public:
        virtual ~Layer() = default;

        virtual void OnAttach() {}
        virtual void OnDetach() {}

        virtual void OnUpdate(float deltaTime) {}
        virtual void OnUIRender() {}
    };

} // namespace Core
#endif
