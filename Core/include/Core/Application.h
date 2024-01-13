#ifndef _CORE_APPLICATION_H
#define _CORE_APPLICATION_H

#include "Layer.h"

#include <string>
#include <functional>
#include <memory>
#include <vector>
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"
#include "glm/glm.hpp"
// THIS STRUCTURE HEAVILY INSPIRED(OR DIRECTLY USED) BY WALNUT see https://github.com/StudioCherno/Walnut
struct GLFWwindow;
namespace Core
{
    struct ApplicationSpecification
    {
        std::string Name = "Application";
        uint32_t Width = 1600;
        uint32_t Height = 900;
    };

    class Application
    {
    public:
        Application(const ApplicationSpecification &applicationSpecification = ApplicationSpecification());
        ~Application();
        static Application &Get();
        void Run();
        void SetMenubarCallback(const std::function<void()> &menubarCallback) { m_MenubarCallback = menubarCallback; }

        template <typename T>
        void PushLayer()
        {
            static_assert(std::is_base_of<Layer, T>::value, "Pushed type is not subclass of Layer!");
            m_LayerStack.emplace_back(std::make_shared<T>())->OnAttach();
        }

        void Close();

        float GetTime();
        GLFWwindow *GetWindowHandle() const { return m_WindowHandle; }

    private:
        void Init();
        void Shutdown();

    private:
        ApplicationSpecification m_Specification;
        GLFWwindow *m_WindowHandle = nullptr;
        bool m_Running = false;

        float m_TimeStep = 0.0f;
        float m_FrameTime = 0.0f;
        float m_LastFrameTime = 0.0f;

        std::vector<std::shared_ptr<Layer>> m_LayerStack;
        std::function<void()> m_MenubarCallback;
    };

    Application *CreateApplication(int argc, char **argv);

} // namespace Core

#endif